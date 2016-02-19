CC=arm-none-eabi-gcc
CFLAGS=-Wall -mlittle-endian -mthumb

main:
	$(CC) $(CFLAGS) -mcpu=cortex-m4 -I../common -DSTM32F303xE -Os -c main.c -o main.o

clean:
	rm *.o
