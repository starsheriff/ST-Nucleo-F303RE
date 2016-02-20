#include <stm32f303xe.h>

#define LED_2_PIN 5

void delay(int n);

int main(void)
{
  /* Enable GPIO clock on port A
     RCC is of type RCC_TypeDef and defined and initiated in 
     stm32f303xe.h */
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  
  /* Configure PIN5 as output */
  /* All lines have the same effect, choose one */
  GPIOA->MODER |= GPIO_MODER_MODER5_0;
  //GPIOA->MODER |= (1 << (5 << 1));
  
  /* Optional, ensure PIN 5 configured as push/pull */
  //GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_5);
  
  /* Set speed */
  GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;
  
  
  while(1)
  {
    /* Turn LED ON */
    /* All lines have same effect, choose one */
    GPIOA->BSRR = GPIO_BSRR_BS_5; // using makro from stm32f303xe.h
    //GPIOA->BSRR |= (1 << LED_2_PIN);
    //GPIOA->ODR = 0xFFFF; // not recommended
    delay(50000);

    /* Turn LED OFF */
    /* All lines have same effect, choose one */
    //GPIOA->BSRR = GPIO_BSRR_BR_5;
    GPIOA->BRR = GPIO_BSRR_BS_5;
    //GPIOA->BSRR = (1 << (LED_2_PIN + 16));
    //GPIOA->BRR |= (1 << LED_2_PIN);
    //GPIOA->ODR = 0x0000; // not recommended
    delay(500000);
  }
  
}

void delay(int n) 
{
  volatile int i=0;
  
  while(i<n)
  {
    i++;
  } 
}
