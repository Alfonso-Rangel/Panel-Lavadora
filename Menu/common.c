#include <stdio.h>
#include "hardware/gpio.h"
#include "pin_list.h"
#include "common.h"

void construct(const int a[]) {
  for (int i = 0; i < PINS_SIZE; i++) {
    pins[i] = a[i];
  }
}

void init() {
  for (int i = 0; i < PINS_SIZE; i++) {
    gpio_init(pins[i]);
    gpio_set_dir(pins[i], GPIO_OUT);
    // Son ánodos
    gpio_set_outover(pins[i], GPIO_OVERRIDE_INVERT);
  }
}
