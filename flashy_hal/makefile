CC=arm-none-eabi-gcc
CFLAGS=-Wall -mlittle-endian -mthumb
LDFLAGS=
SOURCES=main.c startup_stm32f303xe.s system_stm32f3xx.c stm32f3xx_it.c stm32f3xx_hal.c stm32f3xx_hal_rcc.c stm32f3xx_hal_gpio.c stm32f3xx_hal_cortex.c
OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS) main.elf main.hex

main.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I../common -DSTM32F303xE -Os -c main.c -o main.o
	
startup_stm32f303xe.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I../common -DSTM32F303xE -Os -c startup_stm32f303xe.s -o startup_stm32f303xe.o
	
system_stm32f3xx.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I../common -DSTM32F303xE -Os -c system_stm32f3xx.c -o system_stm32f3xx.o

stm32f3xx_it.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I../common -DSTM32F303xE -Os -c stm32f3xx_it.c -o stm32f3xx_it.o

main.elf:
	$(CC) -mcpu=cortex-m4 -mlittle-endian -mthumb -DSTM32F401xE -TSTM32F303RE_FLASH.ld -Wl,--gc-sections $(OBJECTS) -o main.elf

main.hex:
	arm-none-eabi-objcopy -Oihex main.elf main.hex

stm32f3xx_hal_rcc.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I./Inc/ -DSTM32F303xE -Os -c stm32f3xx_hal_rcc.c -o stm32f3xx_hal_rcc.o

stm32f3xx_hal.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I./Inc/ -DSTM32F303xE -Os -c stm32f3xx_hal.c -o stm32f3xx_hal.o

stm32f3xx_hal_gpio.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I./Inc/ -DSTM32F303xE -Os -c stm32f3xx_hal_gpio.c -o stm32f3xx_hal_gpio.o

stm32f3xx_hal_cortex.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I./Inc/ -DSTM32F303xE -Os -c stm32f3xx_hal_cortex.c -o stm32f3xx_hal_cortex.o

clean:
	rm *.o *.elf *.hex
