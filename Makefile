CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
BIN = stick-kicker.gba
CINCLUDES = -I ./include

$(BIN):
	$(CC) crt0.s *.c sprites/*.c -mcpu=arm7tdmi -nostartfiles -Tlnkscript $(CINCLUDES) -O3
	$(OBJCOPY) -O binary a.out $(BIN)
	rm a.out
