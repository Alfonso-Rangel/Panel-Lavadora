#ifndef NIVEL_AGUA_H
#define NIVEL_AGUA_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO 2
#define BUTTON_GPIO_UP (FIRST_GPIO + 11)
#define BUTTON_GPIO_DOWN (FIRST_GPIO + 10)
#define LENGTH 5

void initNivelCarga();
bool estaSubiendo();
bool estaBajando();
int getEstadoBoton(int button_gpio);
void actualizaLEDs();
void incrementaNivel();
void decrementaNivel();
int getMask();

#endif /* NIVEL_AGUA_H */
