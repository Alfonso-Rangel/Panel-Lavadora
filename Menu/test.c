#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pin_list.h"
#include "menu.h"
#include "button.h"
#include "bits.h"
//#include "../Temporizador/timer.h"
int main() {
  int pins[] = {
    PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G,
    D1, D2, D3, D4
  };
  menu_construct(pins);
  stdio_init_all();
  init_menu();

  timer_construct(pins);
  init_timer();
  set_timer(1, 25);

  init_buttons();

  while (true) {
    if (is_on_off_btn_press()) {
      //dec_timer();
      turn_on_leds();
    }
  }
  // endwhile
}
