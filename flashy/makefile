CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -Wall -mlittle-endian -mthumb
LDFLAGS=-mcpu=cortex-m4 -mlittle-endian -mthumb -DSTM32F401xE 
OBJECTS=main.o startup_stm32f303xe.o system_stm32f3xx.o

all: $(OBJECTS) main.elf main.hex

main.o:
	$(CC) $(CFLAGS) -I../common -DSTM32F303xE -Os -c main.c -o main.o
	
startup_stm32f303xe.o:
	$(CC) $(CFLAGS) -I../common -DSTM32F303xE -Os -c ../common/startup_stm32f303xe.s -o startup_stm32f303xe.o
	
system_stm32f3xx.o:
	$(CC) $(CFLAGS) -I../common -DSTM32F303xE -Os -c ../common/system_stm32f3xx.c -o system_stm32f3xx.o

main.elf:
	$(CC) $(LDFLAGS) -T../common/STM32F303XE_FLASH_minimal.ld -Wl,--gc-sections $(OBJECTS) -o main.elf

main.hex:
	arm-none-eabi-objcopy -Oihex main.elf main.hex
	
flash:
	openocd -f openocd.cfg

clean:
	rm *.o *.elf *.hex
