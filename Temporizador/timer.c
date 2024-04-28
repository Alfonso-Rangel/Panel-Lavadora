#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "hardware/gpio.h"

/* @brief*/
void timer_construct(const int a[]) {
  for(int i = 0; i < PINS_SIZE; i++) {
    pins[i] = a[i];
  }
  timer_mask = 0;
}

/* @brief*/
void timer_init() {
  for(int i = 0; i < PINS_SIZE; i++) {
    gpio_init(pins[i]);
    gpio_set_dir(pins[i], GPIO_OUT);
    gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
  }
}

/* @brief*/
int* get_time(int mmss) {
  int m1 = mmss / 1000;
  int m0 = (mmss / 100) % 10;
  int s1 = (mmss / 10) % 10;
  int s0 = mmss % 10;
  int* arr = (int*)malloc(sizeof(int) * 4);
  arr[0] = m1;
  arr[1] = m0;
  arr[2] = s1;
  arr[3] = s0;
  return arr;
}
