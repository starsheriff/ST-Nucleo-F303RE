inc1 = $(HOME)/Software/STM32Cube_FW_F3_V1.3.0/Drivers/CMSIS/Include
inc2 = $(HOME)/Software/STM32Cube_FW_F3_V1.3.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include

all: main system

main:
	arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I$(inc1) -I$(inc2) -DSTM32F303xe -Os -c main.c -o main.o

system:
	arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I$(inc1) -I$(inc2) -DSTM32F303xe -Os -c system_stm32f3xx.c -o system.o

startup:
	arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I$(inc1) -I$(inc2) -DSTM32F303xe -Os -c startup_stm32f303xe.s -o startup.o

	
