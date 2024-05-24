#include <stdio.h>
#include "hardware/gpio.h"
#include "pin_list.h"
#include "menu.h"
#include "button.h"

void construct(const int* a) {
  for (int i = 0; i < PINS_SIZE; i++) {
    pins[i] = a[i];
  }
}

void init() {
  for (int i = 0; i < PINS_SIZE; i++) {
    gpio_init(pins[i]);
    gpio_set_dir(pins[i], GPIO_OUT);
    // Son ánodos
    gpio_set_outover(pins[i], GPIO_OVERRIDE_INVERT);
  }
}

void set_anode_1() {
  gpio_put(D1, 0);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  val = 0;
}

void set_anode_2() {
  gpio_put(D1, 1);
  gpio_put(D2, 0);
  gpio_put(D3, 1);
  gpio_put(D4, 1);
  val = 5;
}

void set_anode_3() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 0);
  gpio_put(D4, 1);
  val = 4;
}

void set_anode_4() {
  gpio_put(D1, 1);
  gpio_put(D2, 1);
  gpio_put(D3, 1);
  gpio_put(D4, 0);
  //val = 1;
  if(!get_mov_btn()) {
    anode4++;
    if (anode4 > 3) {
      anode4 = 1;
    }
  }
  // endif
}

unsigned int get_val() {
  return val;
}

void turn_on_leds() {
  /* Necesitas los pins
   * construct(pins), stdio_init_all
   * init y mask*/
  for (int i = 0; i < 4; i++) {
    switch (i) {
      case 0:
        set_anode_1();
        break;
      case 1:
        set_anode_2();
        break;
      case 2:
        set_anode_3();
        break;
      case 3:
        set_anode_4();
        break;
    }
    //mask = bits[get_val()] << PIN_A;
    //gpio_set_mask(mask);
    //sleep_ms(menu_delay);
    //gpio_clr_mask(mask);
  }
  // endfor
}
