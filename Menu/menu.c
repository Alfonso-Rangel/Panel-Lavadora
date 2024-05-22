#include <stdio.h>
#include "hardware/gpio.h"
#include "pin_list.h"
#include "menu.h"

void construct(const int* a) {
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

void set_anode_1() {
  gpio_put(D1, 0);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  val = 0;
}

void set_anode_2() {
  gpio_put(D1, 1);
  gpio_put(D2, 0);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  val = 5;
}

void set_anode_3() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 0);
  gpio_put(D4, 1);
  val = 4;
}

void set_anode_4() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 0);
  val = 1;
}

unsigned int get_val() {
  return val;
}
