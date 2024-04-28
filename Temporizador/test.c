#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "test.h"

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
}
