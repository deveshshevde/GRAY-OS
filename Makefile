#assign the value of aarch64-linux-gnu to ARMGNU 
#if not set 
ARMGNU ?= aarch64-linux-gnu

Compiler_ops = -Wall -nostdlib -nostartfiles -ffreestanding -Iinclude -mgeneral-regs-only
#-mgeneral-regs-only dont know how this optimisation works will note down later!!
ASMOPS = -Iinclude 

BUILD_DIR = build
SRC_DIR = src

all : kernelV8.img

clean :
	rm -rf $(BUILD_DIR) *.img 

$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(ARMGNU)-gcc $(Compiler_ops) -MMD -c $< -o $@

$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
	$(ARMGNU)-gcc $(ASMOPS) -MMD -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)

DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

kernelV8.img: $(SRC_DIR)/linker.ld $(OBJ_FILES)
	$(ARMGNU)-ld -T $(SRC_DIR)/linker.ld -o $(BUILD_DIR)/kernelV8.elf  $(OBJ_FILES)
	$(ARMGNU)-objcopy $(BUILD_DIR)/kernelV8.elf -O binary kernelV8.img

qemu:
	qemu-system-aarch64 -M raspi4b -kernel kernelV8.img -serial null -serial stdio 

add:
	git add .

push:
	git push