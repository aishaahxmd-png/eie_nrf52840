/**
 * @file main.c
 */

#include <zephyr/kernel.h>
#include "LED.h"

int main(void) {
  LED_init();

  while (1) {
  LED_toggle(LED0);
  k_msleep(500); 
  }
  return 0;
}