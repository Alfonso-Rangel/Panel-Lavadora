#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../include/nivel_carga.h"

int main() {
    stdio_init_all();
    initNivelCarga();
    bool botonPresionado = false;
    while (true) {
        if (estaSubiendo() && !botonPresionado) {
            botonPresionado = true;
            incrementaNivel();
        } else if (estaBajando() && !botonPresionado) {
            botonPresionado = true;
            decrementaNivel();
        } else {
            botonPresionado = false;
        }
        
        int32_t mask = getMask() << FIRST_GPIO;
        gpio_set_mask(mask);
        sleep_ms(150);
        gpio_clr_mask(mask);
    }
}