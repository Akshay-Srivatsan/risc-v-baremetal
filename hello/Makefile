TARGET=hello

ELF=$(TARGET).elf
LIST=$(TARGET).list
BIN=$(TARGET).bin
HEX=$(TARGET).hex

SRC = $(wildcard *.c)
ASM = $(wildcard *.S)
OBJ = $(patsubst %.S, %.o, $(ASM)) $(patsubst %.c, %.o, $(SRC))

CROSS = riscv64-unknown-elf
CC = $(CROSS)-gcc
LD = $(CROSS)-ld
OC = $(CROSS)-objcopy
OD = $(CROSS)-objdump
JLINK = JLinkExe

CFLAGS = -fno-builtin -ffreestanding -nostdlib -nostartfiles -Wall -Wno-unused-function -march=rv32imac -mabi=ilp32 -mcmodel=medany
LDFLAGS = -march=rv32imac -mabi=ilp32 -mcmodel=medany -nostdlib -nostartfiles

.PHONY: all
all: $(BIN) $(LIST)

%.o: %.S
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET).elf: $(OBJ) memmap
	$(CC) $(START) $(LDFLAGS) -Tmemmap -o $@ $(OBJ)

%.list: %.elf
	$(OD) -D $< > $@

%.bin: %.elf %.list
	$(OC) -O binary $< $@

%.hex: %.elf %.list
	$(OC) -O ihex $< $@

.PHONY: install
install: $(HEX)
	@test -n "$(RISCV_MOUNT)" || (echo "Set the RISCV_MOUNT environment variable to the path at which your HiFive1 RevB board is mounted.  This will probably be under /media or /Volumes." && false)
	cp $(HEX) $(RISCV_MOUNT)


.PHONY: flash
flash: $(BIN)
	echo -e "loadfile $< 0x20010000\nrnh\nexit" | $(JLINK) -device FE310 -if JTAG -speed 4000 -jtagconf -1,-1 -autoconnect 1 -NoGui 1

.PHONY: clean
clean:
	rm -f $(BIN) $(LIST) $(ELF) $(OBJ)


