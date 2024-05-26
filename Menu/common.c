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

void set_mask(uint32_t _mask) {
  mask = bits[_mask] << PIN_A;
}

void turn_leds_on() {
  gpio_set_mask(mask);
}

void clr_mask() {
  gpio_clr_mask(mask);
}
