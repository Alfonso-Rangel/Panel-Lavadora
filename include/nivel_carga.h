#ifndef NIVEL_AGUA_H
#define NIVEL_AGUA_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

void initNivelCarga(int* leds_gpio, int button_up_gpio, int button_down_gpio);
bool estaSubiendo();
bool estaBajando();
void incrementaNivel();
void decrementaNivel();
int getMask();

#endif /* NIVEL_AGUA_H */
