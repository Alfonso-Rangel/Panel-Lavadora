#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "NivelCarga.cpp"

int main() {
    stdio_init_all();
    int leds_gpio[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // Define los pines GPIO para los LEDs
    int button_up_gpio = 13; // Define el botón de incremento
    int button_down_gpio = 12; // Define el botón de decremento
    
    NivelCarga nivelCarga(leds_gpio, button_up_gpio, button_down_gpio); // Inicializa el módulo

    bool botonPresionado = false;
    while (true) {
        if (nivelCarga.estaSubiendo() && !botonPresionado) {
            botonPresionado = true;
            nivelCarga.incrementaNivel();
        } else if (nivelCarga.estaBajando() && !botonPresionado) {
            botonPresionado = true;
            nivelCarga.decrementaNivel();
        } else {
            botonPresionado = false;
        }
        
        int32_t mask = nivelCarga.getMask() << leds_gpio[0];
        gpio_set_mask(mask);
        sleep_ms(150);
        gpio_clr_mask(mask);
    }
}
