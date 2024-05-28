#include <stdio.h>
#include "pico/stdlib.h"
#include "../include/NivelCarga.h"
#include "gpio_utils.h"

int main() {
    stdio_init_all();
    int leds_gpio[10] = {21, 20, 2, 3, 4, 5, 6, 7, 8, 9};
    int button_up_gpio = 11;
    int button_down_gpio = 10;

    NivelCarga nivelCarga(leds_gpio, button_up_gpio, button_down_gpio);
    nivelCarga.init();

    gpio_init_pins();

    int val = 0;
    int selected_bits[3];

    // Configurar los tres valores del arreglo bits que el usuario quiere usar
    int a = 5; // F
    int b = 19; // T
    int c = 2; // C

    set_selected_bits(selected_bits, a, b, c);

    // Inicializar el display de 7 segmentos con el primer valor
    gpio_update_leds(val, selected_bits);

    while (true) {
        if (nivelCarga.seEstaIncrementando()) {
            nivelCarga.incrementarNivel();
        } else if (nivelCarga.seEstaDecrementando()) {
            nivelCarga.decrementarNivel();
        }
        nivelCarga.enciendeLeds();
        sleep_ms(150);
        nivelCarga.clear();

        gpio_handle_button_press(&val, selected_bits);
    }

    return 0;
}


