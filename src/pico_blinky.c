#include "hardware/gpio.h"
#include "McuWait.h"
#include "pico_blinky.h"
#include "platform.h"


void delay(void)
{

    for (volatile int i = 0; i < 5000000; i++)
    {
        __asm("nop");
    }
}

#if 1

void blinky_delay(void)
{
    const int unsigned LED_PIN = PICO_DEFAULT_LED_PIN; /* GPIO 25 */
    for (;;)
    {
        for (int i = 0; i < 3; i++)
        {
            gpio_put(LED_PIN, 1);
            delay();
            gpio_put(LED_PIN, 0);
            delay();
        }
        for (int i = 0; i < 3; i++)
        {
            gpio_put(LED_PIN, 1);
            delay();
            gpio_put(LED_PIN, 0);
            delay();
        }
    }
}

#endif

#if 1
void blinky_wait(void)
{
    const int unsigned LED_PIN = PICO_DEFAULT_LED_PIN; /* GPIO 25 */
    for(;;)
    {
        for (int i = 0; i < 3; i++)
        {
            gpio_put(LED_PIN, 1);
            McuWait_Waitms(500);
            gpio_put(LED_PIN, 0);
            McuWait_Waitms(500);
        }
        for (int i = 0; i < 3; i++)
        {
            gpio_put(LED_PIN, 1);
            McuWait_Waitms(2000);
            gpio_put(LED_PIN, 0);
            McuWait_Waitms(2000);
            
        }
    }
}

#endif
