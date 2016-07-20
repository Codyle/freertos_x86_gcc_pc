PROJ_DIR    :=  .
INC_DIR     :=  \
                -I$(PROJ_DIR)/../../Source/include \
                -I$(PROJ_DIR)/../../Source/portable/Common/include \
                -I$(PROJ_DIR)/../../Source/portable/IA32_flat \
                -I$(PROJ_DIR)/../../Source/portable/Support_Files \
                -I$(PROJ_DIR)
SRC_DIR     :=  \
                $(PROJ_DIR)/../../Source \
                $(PROJ_DIR)/../../Source/portable/MemMang \
                $(PROJ_DIR)/../../Source/portable/IA32_flat \
                $(PROJ_DIR)/../../Source/portable/Support_Files \
                $(PROJ_DIR)
BUILD_DIR   :=  $(PROJ_DIR)/build
OBJ_DIR     :=  $(BUILD_DIR)/obj

SRC_C       :=  $(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.c))
SRC_S       :=  $(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.S))
OBJ         :=  $(foreach src,$(SRC_C),$(OBJ_DIR)/$(patsubst %.c,%.o,$(notdir $(src)))) \
                $(foreach src,$(SRC_S),$(OBJ_DIR)/$(patsubst %.S,%.o,$(notdir $(src))))

BUILD       :=  RTOSDemo.elf
MAP         :=  RTOSDemo.map
LDS         :=  $(PROJ_DIR)/../../Source/portable/IA32_flat/elf_ia32_efi.lds

CC          :=  i686-elf-gcc
LDFLAGS     :=  -nostdlib -Xlinker -T -Xlinker $(LDS) -Xlinker -Map=$(BUILD_DIR)/$(MAP) -Xlinker --gc-sections
CFLAGS      :=  $(INC_DIR) -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -march=pentium -Wno-ignored-qualifiers -mno-ms-bitfields -ffunction-sections -ffreestanding
ASFLAGS     :=  $(INC_DIR) -Wa,--gdwarf2 -Wa,-march=pentium -c

.PHONY: $(SRC_C) $(SRC_S) clean

all: $(BUILD)

$(BUILD): $(SRC_C) $(SRC_S)
	$(CC) $(LDFLAGS) -o $(BUILD_DIR)/$(BUILD) $(OBJ)

$(SRC_C): | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/$(patsubst %.c,%.o,$(notdir $@)) $@

$(SRC_S): | $(OBJ_DIR)
	$(CC) $(ASFLAGS) -o $(OBJ_DIR)/$(patsubst %.S,%.o,$(notdir $@)) $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(BUILD_DIR)
