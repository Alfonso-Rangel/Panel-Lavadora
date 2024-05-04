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
  set_time(3, 0);

  int32_t mask;
  while(true) {
    if(!(get_min() == 0 && get_sec() == 0)) {
      for(int i = 0; i < 4; i++) {
        switch(i) {
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
        // turn leds on
        mask = bits[get_val()] << PIN_A;
        gpio_set_mask(mask);
        sleep_ms(timer_delay);
        gpio_clr_mask(mask);
      }
      // endfor
      if(get_ctr() == 50) {
        if(get_sec() == 0) {
          dec_min();
          preset_sec();
        } else {
          dec_sec();
        }
        reset_ctr();
      }
      inc_ctr();
    }
    else {
      set_zeros();
      mask = bits[get_val()] << PIN_A;
      gpio_set_mask(mask);
      sleep_ms(timer_delay);
      gpio_clr_mask(mask);
    }
    //endif
  }
  // end
}
