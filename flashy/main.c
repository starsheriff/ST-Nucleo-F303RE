


int main(void)
{
  HAL_Init();
  BSP_LED_Init(LED2);
  SystemClock_Config();

  while(1)
  {
    BSP_LED_On(LED2);
    HAL_Delay(100);
    BSP_LED_Off(LED2);
    HAL_Delay(200);
  }
}
