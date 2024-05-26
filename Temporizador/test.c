#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "timer.h"
#include "pin_list.h"
#include "../Menu/common.h"

int main() {
  int pins[] = {
    PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G,
    D1, D2, D3, D4
  };
  construct(pins);
  stdio_init_all();
  init();
  set_timer(5, 0);

  while(true) {
    dec_timer();
  }
  // endwhile
}
