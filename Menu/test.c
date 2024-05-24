#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pin_list.h"
#include "menu.h"
#include "button.h"
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
  construct(pins);
  stdio_init_all();
  init();

  int32_t mask;

  init_buttons();

  while (true) {
    if (is_on_off_btn_press()) {
      bool val1 = is_ok_btn_press();
      bool val2 = is_mov_btn_press();
    }
    //bool val = is_on_off_btn_press();
    //bool val = is_ok_btn_press();
    //bool val = is_mov_btn_press();
    sleep_ms(1000);
  }
}
