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
  
  GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5_0;

  while(1)
  {
    GPIOA->BSRR = GPIO_BSRR_BS_5;
    delay(50000);

    GPIOA->BRR = GPIO_BRR_BR_5;
    delay(50000);
  }
}

void delay(int n) 
{
    while(n>0) {
        n--;
    }
}
