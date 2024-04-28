#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "timer.h"
#include "pin_list.h"

int main() {
  int pins[] = {
    PIN_A,
    PIN_B,
    PIN_C,
    PIN_D,
    PIN_E,
    PIN_F,
    PIN_G,
    D1,
    D2,
    D3,
    D4
  };
  timer_construct(pins);
  stdio_init_all();
  timer_init();
  int a, b, c, d;
  a = 0;
  b = 2;
  c = 0;
  d = 7;

  while(true) {
    uint32_t val = timer_read_value(a, b, c, d);
    timer_turn_led_on();
    sleep_ms(timer_delay);
    timer_clear();
  }
}
