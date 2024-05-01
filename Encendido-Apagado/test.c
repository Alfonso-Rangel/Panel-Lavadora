#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BUTTON_GPIO 15
#define PIN_A 2
#define D1 10

int main() {

  gpio_init(BUTTON_GPIO);
  gpio_set_dir(BUTTON_GPIO, GPIO_IN);
  gpio_pull_up(BUTTON_GPIO);

  gpio_init(PIN_A);
  gpio_set_dir(PIN_A, GPIO_OUT);
  int is_on = 0;

  while(1) {
    if(gpio_get(BUTTON_GPIO) == 0) {
      printf("PRIMER if = %d\n", gpio_get(BUTTON_GPIO));
      sleep_ms(25);
      if(gpio_get(BUTTON_GPIO) == 0) {
        printf("if dentro del if = %d\n", gpio_get(BUTTON_GPIO));
        is_on = !is_on;
        gpio_put(D1, 1);
        gpio_put(PIN_A, is_on);
      }
      while(gpio_get(BUTTON_GPIO) == 0) {
        printf("BUCLE = %d\n", gpio_get(BUTTON_GPIO));
        sleep_ms(25);
      }
    }
    printf("FIN = %d\n", gpio_get(BUTTON_GPIO));
  }
}
