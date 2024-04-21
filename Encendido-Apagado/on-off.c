#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/gpio.h"

#define BUTTON_GPIO 9

int main() {
  stdio_init_all();
  if(cyw43_arch_init()) {
    return -1;
  }
  
  gpio_init(BUTTON_GPIO);
  gpio_set_dir(BUTTON_GPIO, GPIO_IN);
  gpio_pull_up(BUTTON_GPIO);
  int is_on = 0;

  while(1) {
    if(gpio_get(BUTTON_GPIO) == 0) {
      //printf("PRIMER if = %d\n", gpio_get(BUTTON_GPIO));
      sleep_ms(25);
      if(gpio_get(BUTTON_GPIO) == 0) {
        //printf("if dentro del if = %d\n", gpio_get(BUTTON_GPIO));
        is_on = !is_on;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, is_on);
      }
      while(gpio_get(BUTTON_GPIO) == 0) {
        //printf("BUCLE = %d\n", gpio_get(BUTTON_GPIO));
        sleep_ms(25);
      }
    }
    //printf("FIN = %d\n", gpio_get(BUTTON_GPIO));
  }
}
