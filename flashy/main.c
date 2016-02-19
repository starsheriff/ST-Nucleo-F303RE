#include "stm32f303xe.h"

#define LED_2_PIN 5


int main(void)
{
  // Enable GPIO clock on port A
  // RCC is of type RCC_TypeDef and defined and initiated in 
  // stm32f303xe.h
  RCC->AHB1ENR |= RCC_AHBENR_GPIOAEN

  GPIOx->BSRR = (uint32_t)GPIO_Pin;

  while(1)
  {
    BSP_LED_On(LED2);
    HAL_Delay(100);
    BSP_LED_Off(LED2);
    HAL_Delay(200);
  }
}
