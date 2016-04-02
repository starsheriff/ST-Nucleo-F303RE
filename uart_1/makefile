# compiler 
CC=arm-none-eabi-gcc
CFLAGS=-Wall -mlittle-endian -mthumb
LDFLAGS=

SOURCES=main.c startup_stm32f303xe.s system_stm32f3xx.c stm32f3xx_it.c
        
# sources from the HAL library (included in the STMCube package)
SOURCES_HAL = stm32f3xx_hal_uart.c \
              stm32f3xx_hal.c \
              stm32f3xx_hal_rcc.c \
              stm32f3xx_hal_gpio.c \
              stm32f3xx_hal_cortex.c \
              stm32f3xx_hal_dma.c \
              stm32f3xx_hal_uart_ex.c
        
OBJECTS=$(SOURCES:.c=.o)
OBJECT_HAL=$(SOURCES_HAL:.c=.o)

# Specify the version of the STMCube package
STM32Cube_VERSION = STM32Cube_FW_F3_V1.4.0

# Absolute path to the directory containing the STMCube package
SRC_HAL = ~/Software/$(STM32Cube_VERSION)/Drivers/STM32F3xx_HAL_Driver/Src/

# Include files specific to the project (including the hal configuration)
INC = -I ./inc

# Directories in the STM32Cube package which contain the various include
# files required to build the project.
INC_HAL = -I ~/Software/$(STM32Cube_VERSION)/Drivers/STM32F3xx_HAL_Driver/Inc/ \
          -I ~/Software/$(STM32Cube_VERSION)/Drivers/CMSIS/Device/ST/STM32F3xx/Include/ \
          -I ~/Software/$(STM32Cube_VERSION)/Drivers/CMSIS/Include/ \
          -I ~/Software/$(STM32Cube_VERSION)/Drivers/BSP/STM32F3xx-Nucleo/


all: $(OBJECTS) $(OBJECT_HAL) main.elf main.hex

main.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I../common $(INC) $(INC_HAL) -DSTM32F303xE -Os -c main.c -o main.o
	
startup_stm32f303xe.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I../common -DSTM32F303xE -Os -c startup_stm32f303xe.s -o startup_stm32f303xe.o
	
system_stm32f3xx.o:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I../common -DSTM32F303xE -Os -c system_stm32f3xx.c -o system_stm32f3xx.o
	
stm32f3%.o: $(SRC_HAL)stm32f3%.c
	#echo $@
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I ../common $(INC) $(INC_HAL) -DSTM32F303xE -Os -c $< -o $@

stm32f3xx_it.o: stm32f3xx_it.c
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I ../common $(INC) $(INC_HAL) -DSTM32F303xE -Os -c $< -o $@
#	#$(CC) $(CFLAGS) -mcpu=cortex-m4 -I../common $(INC) $(INC_HAL) -DSTM32F303xE -Os -c stm32f3xx_it.c -o stm32f3xx_it.o

main.elf:
	$(CC) -mcpu=cortex-m4 -mlittle-endian -mthumb -DSTM32F303xE -TSTM32F303RE_FLASH.ld -Wl,--gc-sections $(OBJECTS) $(OBJECT_HAL) -o main.elf

main.hex:
	arm-none-eabi-objcopy -Oihex main.elf main.hex

#stm32f3xx_hal_rcc.o:
#	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I./Inc/ -DSTM32F303xE -Os -c stm32f3xx_hal_rcc.c -o stm32f3xx_hal_rcc.o

#stm32f3xx_hal.o:
#	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I./Inc/ -DSTM32F303xE -Os -c stm32f3xx_hal.c -o stm32f3xx_hal.o

#stm32f3xx_hal_gpio.o:
#	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I./Inc/ -DSTM32F303xE -Os -c stm32f3xx_hal_gpio.c -o stm32f3xx_hal_gpio.o

#stm32f3xx_hal_cortex.o:
#	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I./Inc/ -DSTM32F303xE -Os -c stm32f3xx_hal_cortex.c -o stm32f3xx_hal_cortex.o
	
#stm32f3xx_hal_uart.o:
#	$(CC) $(CFLAGS) -I $(INC0) -I $(INC1) -I $(INC2) -I $(INC3) -DSTM32F303xE -Os -c $(SRC_HAL)stm32f3xx_hal_uart.c -o stm32f3xx_hal_uart.o

#stm32f3xx_hal_dma.o:
#	$(CC) $(CFLAGS) -I $(INC0) -I $(INC1) -I $(INC2) -I $(INC3) -DSTM32F303xE -Os -c $(SRC_HAL)stm32f3xx_hal_dma.c -o stm32f3xx_hal_dma.o

#stm32f3xx_hal_uart_ex.o:
#	$(CC) $(CFLAGS) -I $(INC0) -I $(INC1) -I $(INC2) -I $(INC3) -DSTM32F303xE -Os -c $(SRC_HAL)stm32f3xx_hal_uart_ex.c -o stm32f3xx_hal_uart_ex.o

clean:
	rm *.o *.elf *.hex
	
flash:
	openocd openocd.cfg
	

