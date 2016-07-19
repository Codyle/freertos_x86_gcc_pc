proj_dir    :=  .

inc_dir     :=  \
                -I$(proj_dir)/../../Source/include \
                -I$(proj_dir)/../../Source/portable/Common/include \
                -I$(proj_dir)/../../Source/portable/IA32_flat \
                -I$(proj_dir)/../../Source/portable/Support_Files \
                -I$(proj_dir)

src_dir     :=  \
                $(proj_dir)/../../Source \
                $(proj_dir)/../../Source/portable/MemMang \
                $(proj_dir)/../../Source/portable/IA32_flat \
                $(proj_dir)/../../Source/portable/Support_Files \
                $(proj_dir)

lds         :=  $(proj_dir)/../../Source/portable/IA32_flat/elf_ia32_efi.lds

build_dir   :=  $(proj_dir)/build

obj_dir     :=  $(build_dir)/obj

src_c       :=  $(foreach dir,$(src_dir),$(wildcard $(dir)/*.c))

src_s       :=  $(foreach dir,$(src_dir),$(wildcard $(dir)/*.S))

obj         :=  $(foreach src,$(src_c),$(obj_dir)/$(patsubst %.c,%.o,$(notdir $(src)))) \
                $(foreach src,$(src_s),$(obj_dir)/$(patsubst %.S,%.o,$(notdir $(src))))

map         :=  RTOSDemo.map

build       :=  RTOSDemo.elf

.PHONY: $(src_c) $(src_s) clean

all: $(src_c) $(src_s)
	i686-elf-gcc -nostdlib -Xlinker -T -Xlinker $(proj_dir)/$(lds) -Xlinker -Map=$(build_dir)/$(map) -Xlinker --gc-sections \
        -o $(build_dir)/$(build) $(obj)

$(src_c): | $(obj_dir)
	i686-elf-gcc $(inc_dir) -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -march=pentium -Wno-ignored-qualifiers -mno-ms-bitfields -ffunction-sections -ffreestanding -o $(obj_dir)/$(patsubst %.c,%.o,$(notdir $@)) $@

$(src_s): | $(obj_dir)
	i686-elf-gcc $(inc_dir) -Wa,--gdwarf2 -Wa,-march=pentium -c \
        -o $(obj_dir)/$(patsubst %.S,%.o,$(notdir $@)) $@

$(obj_dir):
	mkdir -p $(obj_dir)

clean:
	rm -rf $(build_dir)
