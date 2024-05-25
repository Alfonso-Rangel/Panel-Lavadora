#include <stdio.h>
#include "pico/stdlib.h"
#include "gpio_utils.h"

int pines[7];
int32_t mask;

int bits[] = { // Contiene los bits de A a Z
    0x5F, 0x7C, 0x39, 0x5E, 0x7B, 0x71, 0x6F, 0x74, 0x30, 0x1E,
    0x75, 0x38, 0x15, 0x37, 0x3F, 0x73, 0x67, 0x33, 0x6D, 0x78,
    0x3E, 0x2E, 0x2A, 0x76, 0x6E, 0x4B
};


void gpio_init_pins() { // Indicar a partir de cuál pin comenzar 
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);
}

void gpio_handle_button_press(int *val, int *selected_bits) {
    static bool button_pressed = false;

    if (gpio_get(BUTTON_GPIO) && !button_pressed) {
        button_pressed = true;
        sleep_ms(500);

        if (gpio_get(BUTTON_GPIO)) {
            gpio_update_leds(*val, selected_bits);
            if (*val == 2) {
                *val = 0;
            } else {
                (*val)++;
            }
            //gpio_update_leds(*val, selected_bits);
        }
    } else if (!gpio_get(BUTTON_GPIO) && button_pressed) {
        button_pressed = false;
        // No limpiar el LED aquí ya que queremos mantenerlo encendido
        sleep_ms(50);
    }
}

void gpio_update_leds(int val, int *selected_bits) {
    static int32_t previous_mask = 0;

    // Apagar los LEDs anteriores
    gpio_clr_mask(previous_mask);

    // Encender los LEDs correspondientes a la nueva letra
    mask = selected_bits[val] << FIRST_GPIO;
    gpio_set_mask(mask);

    // Guardar el estado actual para poder apagarlo la próxima vez
    previous_mask = mask;
}

void set_selected_bits(int *selected_bits, int a, int b, int c) {
    selected_bits[0] = bits[a];
    selected_bits[1] = bits[b];
    selected_bits[2] = bits[c];
}

int32_t getMascara() {
    return mask;
}