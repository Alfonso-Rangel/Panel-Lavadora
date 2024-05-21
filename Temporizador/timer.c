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

void init_timer() {
  for(int i = 0; i < PINS_SIZE; i++) {
    gpio_init(pins[i]);
    gpio_set_dir(pins[i], GPIO_OUT);
    // Son ánodos
    gpio_set_outover(pins[i], GPIO_OVERRIDE_INVERT);
  }
}

void timer_turn_led_on() {
  gpio_set_mask(timer_mask);
}

void clear_timer() {
  gpio_clr_mask(timer_mask);
}

void set_timer(unsigned int _min, unsigned int _sec) {
  min = _min;
  sec = _sec;
}

unsigned int get_min() {
  return min;
}

unsigned int get_sec() {
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

int is_timer_over(){
  if(min == 0 && sec == 0) {
    return 1;
  }
  return 0;
}

unsigned int get_ctr() {
  return ctr;
}

void inc_ctr() {
  ctr++;
}

void reset_ctr() {
  ctr = 0;
}

unsigned int get_val() {
  return val;
}

void set_anode_1() {
  gpio_put(D1, 0);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  val = min / 10;
}

void set_anode_2() {
  gpio_put(D1, 1);
  gpio_put(D2, 0);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  val = min % 10;
}

void set_anode_3() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 0);
  gpio_put(D4, 1);
  val = sec / 10;
}

void set_anode_4() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 0);
  val = sec % 10;
}

void set_zeros() {
  gpio_put(D1, 0);
  gpio_put(D2, 0);
  gpio_put(D3, 0);
  gpio_put(D4, 0);
  val = 0;
}

void dec_ctr() {
  if(ctr == 50) {
    if(sec == 0) {
      min--;
      sec = 59;
    } else {
      sec--;
    }
    ctr = 0;
  }
  ctr++;
}
