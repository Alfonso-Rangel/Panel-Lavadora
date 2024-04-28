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
  set_time(12, 8);

  while(true) {
    uint32_t val = timer_read_value();
    timer_turn_led_on();
    //sleep_ms(timer_delay);
    sleep_ms(1000);
    printf("tiempo = %d\n", get_time());
    clear_timer();
  }
}
