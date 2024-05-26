#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pin_list.h"
#include "menu.h"
#include "button.h"
#include "common.h"
#include "../Temporizador/timer.h"
int main() {
  int pins[] = {
    PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G,
    D1, D2, D3, D4
  };
  construct(pins);
  stdio_init_all();
  init();

  init_buttons();
  
  while (true) {
    if (is_on_off_btn_press()) {
      turn_on_leds();
    }
  }
  // endwhile
}
