#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "timer.h"
#include "pin_list.h"

int main() {
  int pins[] = {
    PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G,
    D1, D2, D3, D4
  };
  timer_construct(pins);
  stdio_init_all();
  init_timer();
  set_timer(2, 0);

  while(true) {
    dec_timer();
  }
  // endwhile
}
