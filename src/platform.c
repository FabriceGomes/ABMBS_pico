#include "platform.h"
#include "McuWait.h"

uint32_t SystemCoreClock = 120000000; 

void PL_Init(){


    McuWait_Init(); /* initialize the module */
}
