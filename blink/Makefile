TARGET=boot

SRC=$(TARGET).S
ELF=$(TARGET).elf
LIST=$(TARGET).list
BIN=$(TARGET).bin

AS = riscv64-unknown-elf-as
OC = riscv64-unknown-elf-objcopy
OD = riscv64-unknown-elf-objdump
JLINK = JLinkExe

%.elf: %.S
	$(AS) $< -o $@

%.list: %.elf
	$(OD) -D $< > $@

%.bin: %.elf
	$(OC) -O binary $< $@

.PHONY: all
all: $(BIN) $(LIST)

.PHONY: flash
flash: $(BIN)
	echo -e "loadfile $< 0x20010000\nrnh\nexit" | $(JLINK) -device FE310 -if JTAG -speed 4000 -jtagconf -1,-1 -autoconnect 1

.PHONY: clean
clean:
	rm -f $(BIN) $(LIST) $(ELF)


