#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../../include/nivel_carga.h"

int main() {
    stdio_init_all();
     // Definir los pines GPIO para los LEDs y los botones
    int leds_gpio[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int button_up_gpio = 13;
    int button_down_gpio = 12;
    
    initNivelCarga(leds_gpio, button_up_gpio, button_down_gpio);

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
        
        int32_t mask = getMask() << leds_gpio[0];
        gpio_set_mask(mask);
        sleep_ms(150);
        gpio_clr_mask(mask);
    }
}