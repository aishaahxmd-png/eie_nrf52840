/**
 * @file main.c
 */

#include <stdint.h>
#include <zephyr/kernel.h>
#include "LED.h"
#include "BTN.h" 

#define SLEEP_MS 1

int main(void) {
  
    if (BTN_init() < 0) {
        return 0;
    }

    if (LED_init() != 0) {
        return 0;
    }

    uint8_t brightness = 0;

    // Start with all LEDs OFF
    LED_set(LED0, LED_OFF);
    LED_set(LED1, LED_OFF);
    LED_set(LED2, LED_OFF);
    LED_set(LED3, LED_OFF);

    while (1) {

        if (BTN_check_clear_pressed(BTN0)) {

            // Increase counter by 1
            counter++;

            // Reset when counter reaches 16
            if (counter == 16) {
                counter = 0;
            }

            // Display counter in binary using LEDs
            LED_set(LED0, (counter & 1) ? LED_ON : LED_OFF);
            LED_set(LED1, (counter & 2) ? LED_ON : LED_OFF);
            LED_set(LED2, (counter & 4) ? LED_ON : LED_OFF);
            LED_set(LED3, (counter & 8) ? LED_ON : LED_OFF);

            printk("Counter: %u\n", (unsigned int)counter);
        }

        k_msleep(SLEEP_MS);
    }

    return 0;
}