## SPDX-License-Identifier: GPL-2.0-only
romstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CSE) += cse.c
ramstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CSE) += cse.c
romstage-$(CONFIG_SOC_INTEL_CSE_LITE_SKU) += cse_lite.c
ramstage-$(CONFIG_SOC_INTEL_CSE_LITE_SKU) += cse_lite.c
ramstage-$(CONFIG_SOC_INTEL_CSE_LITE_SKU) += cse_lite_cmos.c
romstage-$(CONFIG_SOC_INTEL_CSE_LITE_SKU) += cse_lite_cmos.c
ramstage-$(CONFIG_SOC_INTEL_CSE_HAVE_SPEC_SUPPORT) += cse_spec.c
ramstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CSE) += disable_heci.c
smm-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CSE) += disable_heci.c
ramstage-$(CONFIG_SOC_INTEL_CSE_SET_EOP) += cse_eop.c
romstage-$(CONFIG_SOC_INTEL_CSE_PRE_CPU_RESET_TELEMETRY) += telemetry.c

romstage-$(CONFIG_SOC_INTEL_CSE_LITE_SYNC_BY_PAYLOAD) += cse_sync_payload.c

ifeq ($(CONFIG_STITCH_ME_BIN),y)

CSE_BP1_BIN := $(objcse)/cse_bp1.bin
CSE_BP2_BIN := $(objcse)/cse_bp2.bin
CSE_LAYOUT_BIN := $(objcse)/cse_layout.bin
CSE_RW_FILE := $(CSE_BP2_BIN)

CSE_BPDT_VERSION := $(call strip_quotes,$(CONFIG_CSE_BPDT_VERSION))
ifeq ($(CONFIG_CSE_BPDT_VERSION),)
$(error "CONFIG_CSE_BPDT_VERSION is not set!")
endif

CSE_FPT_INPUT=$(call cse_input_path,$(CONFIG_CSE_FPT_FILE))
CSE_DATA_INPUT=$(call cse_input_path,$(CONFIG_CSE_DATA_FILE))

get_cse_region_offset=$(call int-subtract,$(call get_fmap_value,$(1)) $(CSE_LAYOUT_OFFSET))

CSE_LAYOUT_OFFSET=$(call get_fmap_value,FMAP_SECTION_CSE_LAYOUT_START)
CSE_BP1_OFFSET=$(call get_cse_region_offset,FMAP_SECTION_CSE_RO_START)
CSE_BP1_SIZE=$(call get_fmap_value,FMAP_SECTION_CSE_RO_SIZE)
CSE_BP2_OFFSET=$(call get_cse_region_offset,FMAP_SECTION_CSE_RW_START)
CSE_BP2_SIZE=$(call get_fmap_value,FMAP_SECTION_CSE_RW_SIZE)
CSE_DP_OFFSET=$(call get_cse_region_offset,FMAP_SECTION_CSE_DATA_START)
CSE_DP_SIZE=$(call get_fmap_value,FMAP_SECTION_CSE_DATA_SIZE)

.PHONY: cse_inputs
cse_inputs: $(cse_input_files)

$(cse_decomp_files): $(CSE_FPT_INPUT) $(CSE_FPT)
	printf "    DUMP       $(@F)\n"
	$(CSE_FPT) $< dump -o $(objcse) -n $(@F) > /dev/null

define cse_add_ingredient
	$(if $($(2)-file), \
		printf "    CSEADD     $(2) ($($(2)-file)) -> $(1)\n";
		$(CSE_SERGER) $@ add -n $(2) -f $($(2)-file) > /dev/null,
		printf "    CSEADD     $(2) (dummy) -> $(1)\n";
		$(CSE_SERGER) $@ add -n $(2) > /dev/null)
endef

$(objcse)/cse_%.bin: $(CSE_SERGER) cse_inputs $(cse_decomp_files)
	printf "    CREATE     $(@F) (version $(CSE_BPDT_VERSION))\n"
	$(CSE_SERGER) $@ create-bpdt -v $(CSE_BPDT_VERSION) > /dev/null
	$(foreach ingredient,$(cse_$*_ingredients),\
		$(call cse_add_ingredient,$(@F),$(ingredient));)

$(OBJ_ME_BIN): $(CSE_BP1_BIN) $(CSE_BP2_BIN) $(CSE_DATA_INPUT) $(obj)/fmap_config.h
	printf "    CREATE     $(@F)\n"
	$(CSE_SERGER) $@ create-cse-region -v $(CSE_BPDT_VERSION) \
		--bp1 $(CSE_BP1_OFFSET):$(CSE_BP1_SIZE) --bp1_file $(CSE_BP1_BIN) \
		--bp2 $(CSE_BP2_OFFSET):$(CSE_BP2_SIZE) --bp2_file $(CSE_BP2_BIN) \
		--dp $(CSE_DP_OFFSET):$(CSE_DP_SIZE) --dp_file $(CSE_DATA_INPUT) > /dev/null

endif

ifeq ($(CONFIG_SOC_INTEL_CSE_RW_UPDATE),y)

ifneq ($(CONFIG_STITCH_ME_BIN),y)

ifeq ($(CONFIG_SOC_INTEL_CSE_RW_FILE),"")
$(error "CSE RW file path is missing and need to be set by mainboard config")
endif
CSE_RW_FILE := $(call strip_quotes,$(CONFIG_SOC_INTEL_CSE_RW_FILE))

endif

CSE_LITE_ME_RW = $(call strip_quotes,$(CONFIG_SOC_INTEL_CSE_RW_CBFS_NAME))

regions-for-file-$(CSE_LITE_ME_RW) = FW_MAIN_A,FW_MAIN_B

cbfs-files-y += $(CSE_LITE_ME_RW)
$(CSE_LITE_ME_RW)-file := $(CSE_RW_FILE)
$(CSE_LITE_ME_RW)-name := $(CSE_LITE_ME_RW)
$(CSE_LITE_ME_RW)-type := raw
ifeq ($(CONFIG_SOC_INTEL_CSE_LITE_COMPRESS_ME_RW),y)
$(CSE_LITE_ME_RW)-compression := LZMA
endif

INPUT_FILE := $(call strip_quotes,$(CONFIG_SOC_INTEL_CSE_RW_FILE))
TEMP_FILE := $(shell mktemp)
OFFSETS := 16 18 20 22 # Offsets for CSE version components
VERSIONS := CSE_VERSION_MAJOR CSE_VERSION_MINOR CSE_VERSION_HOTFIX CSE_VERSION_BUILD
INDEXES := $(shell seq 1 $(words $(OFFSETS)))

$(obj)/cse_rw.version:
	$(foreach index,$(INDEXES), \
		$(shell dd if=$(INPUT_FILE) of=$(TEMP_FILE) bs=1 skip=$(word $(index),$(OFFSETS)) count=2 status=none) \
		$(eval $(word $(index),$(VERSIONS)) := $(shell printf "%d" 0x$(shell echo $(shell echo $(shell xxd -p $(TEMP_FILE)) | cut -c3-4)$(shell echo $(shell xxd -p $(TEMP_FILE)) | cut -c1-2))) ) \
	)
	rm -f $(TEMP_FILE)
	$(eval CSE_RW_CBFS_VERSION := $(shell printf "%d.%d.%d.%d" $(CSE_VERSION_MAJOR)$(CSE_VERSION_MINOR)$(CSE_VERSION_HOTFIX)$(CSE_VERSION_BUILD)))
	@echo '$(CSE_RW_CBFS_VERSION)' > $@

CSE_RW_VERSION = $(call strip_quotes,$(CONFIG_SOC_INTEL_CSE_RW_VERSION_CBFS_NAME))
regions-for-file-$(CSE_RW_VERSION) = FW_MAIN_A,FW_MAIN_B
cbfs-files-y += $(CSE_RW_VERSION)
$(CSE_RW_VERSION)-file := $(obj)/cse_rw.version
$(CSE_RW_VERSION)-name := $(CSE_RW_VERSION)
$(CSE_RW_VERSION)-type := raw

endif

ifeq ($(CONFIG_SOC_INTEL_CSE_SUB_PART_UPDATE),y)

CSE_IOM_FILE = $(call strip_quotes,$(CONFIG_SOC_INTEL_CSE_IOM_CBFS_FILE))
CSE_IOM = $(call strip_quotes,$(CONFIG_SOC_INTEL_CSE_IOM_CBFS_NAME))
regions-for-file-$(CSE_IOM) = FW_MAIN_A,FW_MAIN_B,COREBOOT
cbfs-files-y += $(CSE_IOM)
$(CSE_IOM)-file := $(CSE_IOM_FILE)
$(CSE_IOM)-name := $(CSE_IOM)
$(CSE_IOM)-type := raw

CSE_NPHY_FILE = $(call strip_quotes,$(CONFIG_SOC_INTEL_CSE_NPHY_CBFS_FILE))
CSE_NPHY = $(call strip_quotes,$(CONFIG_SOC_INTEL_CSE_NPHY_CBFS_NAME))
regions-for-file-$(CSE_NPHY) = FW_MAIN_A,FW_MAIN_B,COREBOOT
cbfs-files-y += $(CSE_NPHY)
$(CSE_NPHY)-file := $(CSE_NPHY_FILE)
$(CSE_NPHY)-name := $(CSE_NPHY)
$(CSE_NPHY)-type := raw
endif
