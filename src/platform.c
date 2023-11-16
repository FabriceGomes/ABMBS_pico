#include "platform.h"
#include "McuLib.h"
#include "McuWait.h"
#include "McuUtility.h"
#include "McuGPIO.h"
#include "McuLED.h"

#include "gpio.h"
#include "leds.h"
#include "buttons.h"
#include "debounce.h"

#include "McuRTOS.h"
#include "McuRTT.h"
#include "McuSystemView.h"

#include "myTask.h"

uint32_t SystemCoreClock = 120000000;

void PL_Init(void) {
McuLib_Init();
McuRTT_Init();
McuSystemView_Init();
McuWait_Init();
McuGPIO_Init();
McuLED_Init();
McuRTOS_Init();
Leds_Init();
BTN_Init();
Debounce_Init();
Gpio_Init();
Gpio_Test();
//MyTask_Init();

}

void PL_Deinit(void) {
    MyTasks_Deinit();
    Gpio_Deinit();
    Debounce_Deinit();
    BTN_Deinit();
    Leds_Deinit();
    McuRTOS_Deinit();
    McuLED_Deinit();
    McuGPIO_Deinit();
    McuWait_Deinit();
    McuSystemView_Deinit();
    McuRTT_Deinit();
    McuLib_Deinit();
}