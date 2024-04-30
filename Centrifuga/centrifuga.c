#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO 2
#define BUTTON_GPIO (FIRST_GPIO+7)

// This array converts a number 0-9 to a bit pattern to send to the GPIOs
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

int main() {
        stdio_init_all();
        printf("Centrifugado - Presiona el boton para empezar o reiniciar\n");

        for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
                gpio_init(gpio);
                gpio_set_dir(gpio, GPIO_OUT);
                gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
        }

        gpio_init(BUTTON_GPIO);
        gpio_set_dir(BUTTON_GPIO, GPIO_IN);
        gpio_pull_up(BUTTON_GPIO);
        
        int val = 9;
        bool countdown_active = false;
        bool last_button_state = true; // inicializa como no presionado (pull-up)

        while (true) {
                bool current_button_state = gpio_get(BUTTON_GPIO);

        // Detecta cambio de no presionado a presionado)
                if (last_button_state && !current_button_state) {
                        countdown_active = true;  // Habilita la cuenta regresiva
                        val = 9;                  // Reinicia el contador
        }
        last_button_state = current_button_state;
                
                if (countdown_active) {
                        int32_t mask = bits[val] << FIRST_GPIO;
                        gpio_set_mask(mask);
                        sleep_ms(1000);  // Espera 1 seg  
                        gpio_clr_mask(mask);

                        if (val > 0) {
                                val--;
                        } else {
                        countdown_active = false; // Detiene la cuenta regresiva al llegar a 0
                        }
                }
        }
}

