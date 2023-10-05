#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "platform.h"
#include "pico_blinky.h"



int main(void) {

PL_Init();
for(;;)
{
  //pico_blinky_delay();
  blinky_wait();
}


return 0;
}
