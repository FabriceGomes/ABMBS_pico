#include "hardware/gpio.h"
#include "McuWait.h"
#include "pico_blinky.h"
#include "platform.h"

/// @brief delay with nops
/// @param  
void delay(void)
{

    for (volatile int i = 0; i < 5000000; i++)
    {
        __asm("nop");
    }
}

#if 1

/// @brief blinky with nops
/// @param  
void blinky_delay(void)
{



    const int unsigned LED_PIN = PICO_DEFAULT_LED_PIN; /* GPIO 25 */

    gpio_init(LED_PIN);
gpio_set_dir(LED_PIN,TRUE);

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

/// @brief blinky with the mculib-waitfunction;
/// @param  
void blinky_wait(void)
{
    const int unsigned LED_PIN = PICO_DEFAULT_LED_PIN; /* GPIO 25 */

gpio_init(LED_PIN);
gpio_set_dir(LED_PIN,TRUE);

    for(;;)
    {
        for (int i = 0; i < 3; i++)
        {
            gpio_put(LED_PIN, TRUE);
            McuWait_Waitms(500);
            gpio_put(LED_PIN, FALSE);
            McuWait_Waitms(500);
        }
        for (int i = 0; i < 3; i++)
        {
            gpio_put(LED_PIN, TRUE);
            McuWait_Waitms(2000);
            gpio_put(LED_PIN, FALSE);
            McuWait_Waitms(2000);
            
        }
    }
}

#endif
