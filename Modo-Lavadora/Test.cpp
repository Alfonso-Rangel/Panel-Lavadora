#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../include/ModoLavadora.h"


int main() {
    stdio_init_all();
    int leds_gpio[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // Define los pines GPIO para los LEDs
    int button_up_gpio = 13; // Define el botón de incremento
    int button_down_gpio = 12; // Define el botón de decremento
    int button_changemode_gpio = 14;
    
    NivelCarga nivelCarga(leds_gpio, button_up_gpio, button_down_gpio);
    ModoLavadora modoLavadora(&nivelCarga, button_changemode_gpio);

    nivelCarga.init();
    modoLavadora.init();
    
    while (true) {
        if (modoLavadora.seEstaCambiandoModo()) {
            modoLavadora.cambiaModo();
            modoLavadora.aplicaModo();
        }
        if (modoLavadora.modoManual()) {
            if (nivelCarga.seEstaIncrementando()) { 
                nivelCarga.incrementarNivel();
            } else if (nivelCarga.seEstaDecrementando()) {
                nivelCarga.decrementarNivel();
            }  
        }
        nivelCarga.enciendeLeds();
        
        sleep_ms(150);
        nivelCarga.clear();
    }
}
