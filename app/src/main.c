/**
 * @file main.c
 */

#include <zephyr/kernel.h>
#include "LED.h"

int main(void) {
  LED_init();

  while (1) {
   LED_set(LED0, LED_ON);
   k_msleep(500);
   LED_set(LED0, LED_OFF);

   LED_set(LED1, LED_ON);
   k_msleep(500);
   LED_set(LED1, LED_OFF);

   LED_set(LED2, LED_ON);
   k_msleep(500);
   LED_set(LED2, LED_OFF);

   // Turn LED3 ON, then OFF
  LED_set(LED3, LED_ON);
  k_msleep(500);
  LED_set(LED3, LED_OFF);
  }
  return 0;
}