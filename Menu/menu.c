#include <stdio.h>
#include "hardware/gpio.h"
#include "pin_list.h"
#include "menu.h"
#include "button.h"
#include "common.h"
#include "../Temporizador/timer.h"

void set_o() {
  gpio_put(D1, 0);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  menu_val = menu_anode1;
}

void set_p() {
  gpio_put(D1, 1);
  gpio_put(D2, 0);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  menu_val = menu_anode2;
}

void set_c() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 0);
  gpio_put(D4, 1);
  menu_val = menu_anode3;
}

void set_123() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 0);
  if (menu_count == 10) {
    if(!get_mov_btn()) {
      menu_anode4++;
      if (menu_anode4 > 3) {
        menu_anode4 = 1;
      }
    }
    menu_count = 0;
  }
  menu_count++;
  // endif
}

unsigned int get_opc() {
  return menu_anode4;
}

void turn_on_options() {
  for (int i = 0; i < 4; i++) {
    switch (i) {
      case 0:
        set_o();
        break;
      case 1:
        set_p();
        break;
      case 2:
        set_c();
        break;
      case 3:
        set_123();
        break;
    }
    if (i < 3) {
      set_mask(menu_val);
    } else {
      set_mask(menu_anode4);
    }
    turn_leds_on();
    sleep_ms(delay);
    clr_mask();
  }
}

void test() {
  if (!is_ok_btn_press()) {
    turn_on_options();
  } else {
    // Por default is_time_out es verdadero
    if (is_time_out()) {
      switch (menu_anode4) {
        case 1:
          set_timer(1, 0);
          break;
        case 2:
          set_timer(2, 0);
          break;
        default:
          set_timer(3, 0);
      }
      while (!is_time_out()) {
        dec_timer();
      }
    }
    set_zeros();
  }
}
