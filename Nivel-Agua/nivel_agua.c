#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO 2
#define BUTTON_GPIO (FIRST_GPIO+7)


// Este array convierte un número del 0 al 9 en un patrón de bits para enviar a los GPIOs

// Ánodo común
int bits[10] = {
    0xC0,  // 0
    0xF9,  // 1
    0xA4,  // 2
    0xB0,  // 3
    0x99,  // 4
    0x92,  // 5
    0x82,  // 6
    0xF8,  // 7
    0x80,  // 8
    0x98   // 9
};

// Cátodo común
/*
int bits[10] = {
        0x3f,  // 0
        0x06,  // 1
        0x5b,  // 2
        0x4f,  // 3
        0x66,  // 4
        0x6d,  // 5
        0x7d,  // 6
        0x07,  // 7
        0x7f,  // 8
        0x67   // 9
};
*/

int main() {
    stdio_init_all();
    
    // Configurar pines GPIO como salida
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    // Configurar pin del botón como entrada con pull-up
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    bool count_down = false; // Estado de la cuenta regresiva
    int val = 0;
    while (true) {
        // Si se presiona el botón, cambiar el estado de la cuenta regresiva
        if (!gpio_get(BUTTON_GPIO)) {
            count_down = !count_down;
            sleep_ms(250); // Esperar un momento para evitar la detección múltiple del botón
        }

        // Si estamos en modo de cuenta regresiva, contar hacia abajo
        if (count_down) {
            // Mostrar el valor actual
            int32_t mask = bits[val];
            for (int i = 0; i < 7; i++) {
                if (mask & (1 << i)) {
                    gpio_put(FIRST_GPIO + i, 1);
                } else {
                    gpio_put(FIRST_GPIO + i, 0);
                }
            }

            // Decrementar el valor y ajustarlo si es necesario
            val--;
            if (val < 0) {
                val = 9;
            }

            sleep_ms(1000); // Esperar un segundo antes de mostrar el siguiente valor
        } else {
            // Si no estamos en modo de cuenta regresiva, mostrar 0
            for (int i = 0; i < 7; i++) {
                gpio_put(FIRST_GPIO + i, 0);
            }
            val = 0; // Reiniciar el valor
        }
    }
}
