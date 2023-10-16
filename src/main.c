#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "platform.h"
#include "pico_blinky.h"
#include "McuGPIO.h"
#include "leds.h"
#include "leds_config.h"

void InitButtons(McuGPIO_Handle_t *handle, int Pin)
{
  McuGPIO_Config_t config;
  McuGPIO_GetDefaultConfig(&config);
  config.isInput = true;
  config.hw.pin = Pin;
  config.hw.pull = McuGPIO_PULL_UP;
  *handle = McuGPIO_InitGPIO(&config);
}

int main(void)
{

  PL_Init();
/*  Leds_Init();

  static McuGPIO_Handle_t ButtonHold;
  int PinButtonHold = 11;

  static McuGPIO_Handle_t ButtonDown;
  int PinButtonDown = 14;
  static McuGPIO_Handle_t ButtonUp;
  int PinButtonUp = 15;

  InitButtons(&ButtonHold, PinButtonHold);
  InitButtons(&ButtonDown, PinButtonDown);
  InitButtons(&ButtonUp, PinButtonUp);

  if (ButtonHold == NULL && ButtonUp == NULL && ButtonDown)
  {
    Leds_On(LEDS_BLUE);
    for (;;)
    {
      
    }
  }

  for (;;)
  {
    if (McuGPIO_IsLow(ButtonHold))
    {
      Leds_On(LEDS_RED);
      Leds_On(LEDS_BLUE);
      Leds_On(LEDS_GREEN);
    }

    if (McuGPIO_IsLow(ButtonUp))
    {
      Leds_On(LEDS_RED);
    }

    if (McuGPIO_IsLow(ButtonDown))
    {
      Leds_On(LEDS_GREEN);
    }
    


    Leds_Off(LEDS_RED);
    Leds_Off(LEDS_BLUE);
    Leds_Off(LEDS_GREEN);
  }
*/
  PL_Deinit();
  return 0;
}
