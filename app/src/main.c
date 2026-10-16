/**
 * @file main.c
 */

#include <stdint.h>
#include <zephyr/kernel.h>
#include "LED.h"

#define STEP_DELAY_MS 100

int main(void) {
  if (LED_init() != 0) {
        return 0;
    }

    while (1) {

        // Gradually increase brightness
        for (uint8_t duty_cycle = 0; duty_cycle <= 100; duty_cycle += 10) {
            LED_pwm(LED0, duty_cycle);
            k_msleep(STEP_DELAY_MS);
        }

        // Gradually decrease brightness
        for (int duty_cycle = 100; duty_cycle >= 0; duty_cycle -= 10) {
            LED_pwm(LED0, duty_cycle);
            k_msleep(STEP_DELAY_MS);
        }
    }

    return 0;
}