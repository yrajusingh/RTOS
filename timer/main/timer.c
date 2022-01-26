#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/timers.h>

 TimerHandle_t motor_timer_handle ;
 void TurnMotorOFF ( TimerHandle_t xTimer)
 {
     printf("turning motor off \n");
 }

 void app_main ()
 {
  motor_timer_handle = xTimerCreate ("MotorOFF",pdMS_TO_TICKS(2000),pdTRUE,NULL,TurnMotorOFF);
  xTimerStart(motor_timer_handle ,0);
  while (1)
  {
      printf("main task \n");
      vTaskDelay(pdMS_TO_TICKS(1000));
  }
     
 }











