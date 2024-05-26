#include <stdio.h>
#include "hardware/gpio.h"
#include "pin_list.h"
#include "menu.h"
#include "button.h"
#include "bits.h"

void menu_construct(const int* a) {
  for (int i = 0; i < PINS_SIZE; i++) {
    pins[i] = a[i];
  }
}

void init_menu() {
  for (int i = 0; i < PINS_SIZE; i++) {
    gpio_init(pins[i]);
    gpio_set_dir(pins[i], GPIO_OUT);
    // Son ánodos
    gpio_set_outover(pins[i], GPIO_OVERRIDE_INVERT);
  }
}

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

void turn_on_leds() {
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
      menu_mask = bits[menu_val] << PIN_A;
    } else {
      menu_mask = bits[menu_anode4] << PIN_A;
    }
    gpio_set_mask(menu_mask);
    sleep_ms(menu_delay);
    gpio_clr_mask(menu_mask);
    if (!get_ok_btn()) {
      break;
    }
    // endif
  }
  // endfor
}
