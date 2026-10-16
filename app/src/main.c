/**
 * @file main.c
 */

#include <zephyr/kernel.h>
#include "LED.h"

int main(void) {
  LED_init();
// Blink LED0 once per second
  LED_blink(LED0, LED_1HZ);

  // Blink LED1 twice per second
  LED_blink(LED1, LED_2HZ);

  // Blink LED2 four times per second
  LED_blink(LED2, LED_4HZ);

  // Blink LED3 eight times per second
  LED_blink(LED3, LED_8HZ);

   while (1) {
    k_msleep(1000);
  }
  return 0;
}