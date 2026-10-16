/**
 * @file main.c
 */

#include <zephyr/kernel.h>
#include "LED.h"

int main(void) {
  LED_init();

  while (1) {
  LED_toggle(LED0);
  LED_toggle(LED1);
  LED_toggle(LED2);
  LED_toggle(LED3);

  k_msleep(250); 

  LED_toggle(LED0);

  k_msleep(250);
  }
  return 0;
}