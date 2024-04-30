#include <stdio.h>
#include <stdlib.h>
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
  set_time(2, 59);
  int min = get_min();
  int sec = get_sec();
  int val;

  int32_t mask;
  while(true) {
    if(!(min == 0 && sec == 0)) {
      for(int i = 0; i < 4; i++) {
        switch(i) {
          case 0:
            gpio_put(D1, 0);
            gpio_put(D2, 1);
            gpio_put(D3, 1);
            gpio_put(D4, 1);
            val = min / 10;
            break;
          case 1:
            gpio_put(D1, 1);
            gpio_put(D2, 0);
            gpio_put(D3, 1);
            gpio_put(D4, 1);
            val = min % 10;
            break;
          case 2:
            gpio_put(D1, 1);
            gpio_put(D2, 1);
            gpio_put(D3, 0);
            gpio_put(D4, 1);
            val = sec / 10;
            break;
          case 3:
            gpio_put(D1, 1);
            gpio_put(D2, 1);
            gpio_put(D3, 1);
            gpio_put(D4, 0);
            val = sec % 10;
            break;
        }
        // turn leds on
        if(i >= 0 && i < 3) {
          mask = bits[val] << PIN_A;
          gpio_set_mask(mask);
          sleep_ms(timer_delay);
          gpio_clr_mask(mask);
        }
        else {
          mask = bits[val] << PIN_A;
          gpio_set_mask(mask);
          sleep_ms(60);
          gpio_clr_mask(mask);
        }
      }
      // endfor
      if(sec == 0) {
        min--;
        sec = 59;
      } else {
        sec--;
      }
    }
    else {
      gpio_put(D1, 0);
      gpio_put(D2, 0);
      gpio_put(D3, 0);
      gpio_put(D4, 0);

      mask = bits[0] << PIN_A;
      gpio_set_mask(mask);
      sleep_ms(1000);
      gpio_clr_mask(mask);
    }
    //endif
  }
  // end
}
