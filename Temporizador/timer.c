#include <stdio.h>
#include "hardware/gpio.h"
#include "pin_list.h"
#include "timer.h"

void timer_construct(const int a[]) {
  for(int i = 0; i < PINS_SIZE; i++) {
    pins[i] = a[i];
  }
  timer_mask = 0;
}

void timer_init() {
  for(int i = 0; i < PINS_SIZE; i++) {
    gpio_init(pins[i]);
    gpio_set_dir(pins[i], GPIO_OUT);
    gpio_set_outover(pins[i], GPIO_OVERRIDE_INVERT);
  }
}

uint32_t timer_read_value() {
  static int i = 0;
  if(i == 4) {
    i = 0;
  }
  int val;
  switch(i) {
    case 0:
      gpio_put(D1, 0);
      gpio_put(D2, 1);
      gpio_put(D3, 1);
      gpio_put(D4, 1);
      val = get_min() / 10;
      break;
    case 1:
      gpio_put(D1, 1);
      gpio_put(D2, 0);
      gpio_put(D3, 1);
      gpio_put(D4, 1);
      val = get_min() % 10;
      break;
    case 2:
      gpio_put(D1, 1);
      gpio_put(D2, 1);
      gpio_put(D3, 0);
      gpio_put(D4, 1);
      val = get_sec() / 10;
      break;
    case 3:
      gpio_put(D1, 1);
      gpio_put(D2, 1);
      gpio_put(D3, 1);
      gpio_put(D4, 0);
      val = get_sec() % 10;;
      break;
  }
  i++;
  timer_mask = bits[val] << PIN_A;
  return timer_mask;
}

void timer_turn_led_on() {
  gpio_set_mask(timer_mask);
}

void clear_timer() {
  gpio_clr_mask(timer_mask);
}

void set_time(int _min, int _sec) {
  min = _min;
  sec = _sec;
}

int get_min() {
  return min;
}

int get_sec() {
  return sec;
}

void dec_min() {
  min--;
}

void dec_sec() {
  sec--;
}

void preset_sec() {
  sec = 59;
}
