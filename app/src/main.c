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

    LED_pwm(LED0, brightness);

    while (1) {

        if (BTN_check_clear_pressed(BTN0)) {

            brightness += 10;

            if (brightness > 100) {
                brightness = 0;
            }

            LED_pwm(LED0, brightness);

            printk("Brightness: %u%%\n", (unsigned int)brightness);
        }

        k_msleep(SLEEP_MS);
    }

    return 0;
}