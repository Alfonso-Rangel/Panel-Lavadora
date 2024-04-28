#include <stdio.h>
#include "hardware/gpio.h"
#include "pin_list.h"
#include "timer.h"

/* @brief*/
void timer_construct(const int a[]) {
  for(int i = 0; i < PINS_SIZE; i++) {
    pins[i] = a[i];
  }
  timer_mask = 0;
}

/* @brief*/
void timer_init() {
  for(int i = 0; i < PINS_SIZE; i++) {
    gpio_init(pins[i]);
    gpio_set_dir(pins[i], GPIO_OUT);
    gpio_set_outover(pins[i], GPIO_OVERRIDE_INVERT);
  }
}

/* @brief*/
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
      val = d1;
      break;
    case 1:
      gpio_put(D1, 1);
      gpio_put(D2, 0);
      gpio_put(D3, 1);
      gpio_put(D4, 1);
      val = d2;
      break;
    case 2:
      gpio_put(D1, 1);
      gpio_put(D2, 1);
      gpio_put(D3, 0);
      gpio_put(D4, 1);
      val = d3;
      break;
    case 3:
      gpio_put(D1, 1);
      gpio_put(D2, 1);
      gpio_put(D3, 1);
      gpio_put(D4, 0);
      val = d4;
      break;
  }
  i++;
  timer_mask = bits[val] << PIN_A;
  return timer_mask;
}

/* @brief*/
void timer_turn_led_on() {
  gpio_set_mask(timer_mask);
}

/* @brief*/
void clear_timer() {
  gpio_clr_mask(timer_mask);
}

/* @brief*/
void set_time(int min, int sec) {
  if(min >= 0 && min < 60 && sec >= 0 && sec < 60) {
    d1 = (min / 10) % 10;
    d2 = min % 10;
    d3 = (sec / 10) % 10;
    d4 = sec % 10;
  }
}

/* @brief*/
int get_time() {
  return (d1*1000 + d2*100 + d3*10 + d4);
}
