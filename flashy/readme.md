# Flashy
Hello world for devboards. Turns the user LED on and off.




Definitions from Nucleo Board with STM32F303xE:
* GPIO Port: A
* GPIO Pin: 5
That's where the LED is connected to on the Nucleo board.

Going deeper:
GPIO_PIN_5 is available at `stm32f3xx_hal_gpio.h`

`#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */`

So when entering main(), we have some more things to do.
1. Enable the clock on the LED Pin.
2. Configure the Pin (as output, push/pull)
3. Start infinite loop turning LED on and off.
