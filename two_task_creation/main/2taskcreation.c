#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandletask;

void task1 (void *pv)
{
    while (1)
    printf(" we are in task1 \n");
   vTaskDelete(xHandletask);
}
void task2 (void *pv)
{
    while (1)
    {
        printf("we are in task2 \n");
    }
    vTaskDelete(xHandletask);
    
}
void app_main ()
{
     BaseType_t result ;
     result = xTaskCreate(task1,"mycode",2048,NULL,5,&xHandletask);
     if (result == pdPASS )
     {
         printf("task1 is created \n");
         printf("5 \n");
     }

     result = xTaskCreate(task2,"task2created",2048,NULL,10,&xHandletask);
     if (result == pdPASS )
     {
         printf("task2 is created \n");
         printf("10 \n");
     }
}


