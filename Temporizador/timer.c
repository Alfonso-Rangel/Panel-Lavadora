#include <stdio.h>
#include "hardware/gpio.h"
#include "../Menu/pin_list.h"
#include "timer.h"
#include "../Menu/common.h"

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

bool is_time_out(){
  if(min == 0 && sec == 0) {
    return true;
  }
  return false;
}

unsigned int get_ctr() {
  return timer_ctr;
}

void inc_ctr() {
  timer_ctr++;
}

void reset_ctr() {
  timer_ctr = 0;
}

void turn_minute_1() {
  gpio_put(D1, 0);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  timer_val = min / 10;
}

void turn_minute_0() {
  gpio_put(D1, 1);
  gpio_put(D2, 0);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  timer_val = min % 10;
}

void turn_sec_1() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 0);
  gpio_put(D4, 1);
  timer_val = sec / 10;
}

void turn_sec_0() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 0);
  timer_val = sec % 10;
}

void dec_timer() {
  for (int i = 0; i < 4; i++) {
    switch (i) {
      case 0:
        turn_minute_1();
        break;
      case 1:
        turn_minute_0();
        break;
      case 2:
        turn_sec_1();
        break;
      case 3:
        turn_sec_0();
        break;
    }
    set_mask(timer_val);
    turn_leds_on();
    sleep_ms(delay);
    clr_mask();
  }
  // Se decremeta el contador
  if(timer_ctr == 50) {
    if(sec == 0) {
      min--;
      sec = 59;
    } else {
      sec--;
    }
    timer_ctr = 0;
  }
  timer_ctr++;
}

void set_zeros() {
  gpio_put(D1, 0);
  gpio_put(D2, 0);
  gpio_put(D3, 0);
  gpio_put(D4, 0);

  set_mask(0);
  turn_leds_on();
  sleep_ms(delay);
  clr_mask();
}
