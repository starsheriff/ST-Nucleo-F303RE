#include "stm32f303xe.h"

#define LED_2_PIN 5

void delay(int n);

int main(void)
{
  // Enable GPIO clock on port A
  // RCC is of type RCC_TypeDef and defined and initiated in 
  // stm32f303xe.h
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  
  GPIOA->MODER |= GPIO_MODER_MODER5_0;
  //GPIOA->MODER |= (1 << (5 << 1));
  
  GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_5);
  
  GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;
  
  
  while(1)
  {
    //GPIOA->BSRR = GPIO_BSRR_BS_5;
    GPIOA->ODR = 0xFFFF;
    delay(500000);

    //GPIOA->BSRR = GPIO_BSRR_BR_5;
    GPIOA->ODR = 0x0000;
    delay(500000);
  }
  
}

void delay(int n) 
{
    volatile int i,j;

    for (i=0 ; i < n ; i++)
    {
        j++;
    }

    return;
}
