CC=arm-none-eabi-gcc
CFLAGS2=-mcpu=cortex-m4 -Wall -mlittle-endian -mthumb
#CFLAGS2=-Wall -O2 -nostdlib -nostartfiles -ffreestanding -mthumb -mcpu=cortex-m4 -march=armV7e-m -mlittle-endian

LDFLAGS=-mcpu=cortex-m4 -mlittle-endian -mthumb -DSTM32F401xE 
OBJECTS=startup.o main.o 
#system_stm32f3xx.o

all: $(OBJECTS) main.elf main.hex

main.o:
	$(CC) $(CFLAGS2) -I../common -DSTM32F303xE  -c main.c -o main.o
	
startup.o:
	$(CC) $(CFLAGS2) -I../common -DSTM32F303xE -c startup.s -o startup.o
	
system_stm32f3xx.o:
	$(CC) $(CFLAGS2) -I../common -DSTM32F303xE  -c ../common/system_stm32f3xx.c -o system_stm32f3xx.o

main.elf:
	arm-none-eabi-ld -T memorymap.ld  $(OBJECTS) -o main.elf
		
main.hex:
	arm-none-eabi-objcopy -O binary main.elf main.hex
	
flash:
	openocd -f openocd.cfg

clean:
	rm *.o *.elf *.hex
