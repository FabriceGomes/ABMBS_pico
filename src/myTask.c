#include "myTask.h"
#include "stdint.h"
#include "stdio.h"
#include "McuRTOS.h"
#include "leds.h"
#include "buttons.h"
#include "McuSystemView.h"
#include "McuRTT.h"

static TaskHandle_t killmeTaskHandle;

typedef struct
{
  LEDS_Leds_e LED;
  BTN_Buttons_e BUTTON;
  // Weitere Parameter hier
} TaskParams;

static void killmeTask(void *pv)
{
  vTaskPrioritySet(NULL, 5);
  vTaskSuspend(NULL);
  vTaskDelete(NULL);
}

static void otherTask(void *pv)
{
  vTaskResume(killmeTaskHandle);
  vTaskDelete(NULL);
}

static void LEDTask(void *pv)
{

  TaskParams *taskParams = (TaskParams *)pv; // Zeiger auf die übergebene Struktur

  LEDS_Leds_e led = taskParams->LED;
  BTN_Buttons_e button = taskParams->BUTTON;

  printf("LEDTask led param is %d\n", (int)led);
  // testing task priorities
  // vTaskPrioritySet(NULL; uxTaskPriorityGet(NULL)+1);
  // vTaskPrioritySet(NULL; uxTaskPriorityGet(NULL)-1);

  for (;;)
  {

    McuSystemView_Print((const char *)"Button!\r\n");

    if (BTN_IsPressed(button))
    {
      McuSystemView_OnUserStart(1);
      Leds_On(led);
      McuSystemView_OnUserStop(1);
    }
    else{
      Leds_Off(led);
    }
  }
}

static void LEDTaskTwo(void *pv)
{

  LEDS_Leds_e led2 = *(LEDS_Leds_e *)pv;

  for (;;)
  {
    vTaskDelay(pdMS_TO_TICKS(50));
    Leds_Neg(led2);
  }
}

static void LEDTaskThree(void *pv)
{

  LEDS_Leds_e led3 = *(LEDS_Leds_e *)pv;

  for (;;)
  {
    vTaskDelay(pdMS_TO_TICKS(1000));
    Leds_Neg(led3);
  }
}

void MyTasks_Deinit(void)
{
}

void MyTask_Init(void)
{
  BaseType_t res;
  BaseType_t res2;
  BaseType_t res3;

  TaskParams params = {
      .LED = LEDS_BLUE,
      .BUTTON = BTN_NAV_CENTER,
      // Weitere Parameter initialisieren
  };

  LEDS_Leds_e taskParam2 = LEDS_RED;
  LEDS_Leds_e taskParam3 = LEDS_GREEN;

  TaskHandle_t myTaskHndl1 = NULL;
  TaskHandle_t myTaskHndl2 = NULL;
  TaskHandle_t myTaskHndl3 = NULL;

  res = xTaskCreate(LEDTask,                           /* function */
                    "LEDTask",                         /* Kernel awareness name */
                    150 / sizeof(StackType_t),         /* stack */
                    &params, /* task parameter */      // NULL bei keinem Parameter,
                    tskIDLE_PRIORITY + 1, /* priority */
                    &myTaskHndl1                       /* handle */
  );

  if (res != pdPASS)
  { /* error handling here */
  }

  res2 = xTaskCreate(LEDTaskTwo,
                     "LEDTaskTwo",
                     150 / sizeof(StackType_t),
                     &taskParam2,
                     tskIDLE_PRIORITY + 1,
                     &myTaskHndl2);

  if (res2 != pdPASS)
  {
  }

  res3 = xTaskCreate(LEDTaskThree,
                     "LEDTaskThree",
                     150 / sizeof(StackType_t),
                     &taskParam3,
                     tskIDLE_PRIORITY + 1,
                     &myTaskHndl3);

  if (res3 != pdPASS)
  {
  }

  vTaskStartScheduler();
}