/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

/*
  Our 7 Segment display has pins as follows:

  --A--
  F   B
  --G--
  E   C
  --D--

  By default we are allocating GPIO 2 to segment A, 3 to B etc.
  So, connect GPIO 2 to pin A on the 7 segment LED display etc. Don't forget
  the appropriate resistors, best to use one for each segment!

  Connect button so that pressing the switch connects the GPIO 9 (default) to
  ground (pull down)
*/

#define FIRST_GPIO 2
#define BUTTON_GPIO_UP (FIRST_GPIO + 11)
#define BUTTON_GPIO_DOWN (FIRST_GPIO + 10)
#define LENGTH 5

// This array converts a number 0-9 to a bit pattern to send to the GPIOs
/*
int bits[LENGTH] = {
       0b0000000000, 
       0b0000000001, // 1 A
       0b0000000010, // 2 V
       0b0000000100, // 3 V
       0b0010000000, // 4 V
       0b0000010000, // 5 V
       0b0000100000, // 6 N
       0b0001000000, // 7 N
       0b0000001000, // 8 N 
       0b0100000000, // 9 R
       0b1000000000, // 10 R
       0b1111111111

};
*/
int bits[LENGTH] = {
       0b0000000000, // Sin carga 
       0b0000000001, // Carga baja
       0b0010010111, // Carga media
       0b0011111111, // Carga moderada
       0b1111111111 // Capacidad máxima
};



/// \tag::hello_gpio[]
int main() {
    stdio_init_all();

    // We could use gpio_set_dir_out_masked() here
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 10; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        // Our bitmap above has a bit set where we need an LED on, BUT, we are pulling low to light
        // so invert our output
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }

    gpio_init(BUTTON_GPIO_UP);
    gpio_init(BUTTON_GPIO_DOWN);
    gpio_set_dir(BUTTON_GPIO_UP, GPIO_IN);
    gpio_set_dir(BUTTON_GPIO_DOWN, GPIO_IN);
    // We are using the button to pull down to 0v when pressed, so ensure that when
    // unpressed, it uses internal pull ups. Otherwise when unpressed, the input will
    // be floating.
    gpio_pull_up(BUTTON_GPIO_UP);
    gpio_pull_up(BUTTON_GPIO_DOWN);

    int val = 0;
    bool button_pressed = false;
    while (true) {
        // Count upwards or downwards depending on button input
        // We are pulling down on switch active, so invert the get to make
        // a press count downwards
        if (!gpio_get(BUTTON_GPIO_UP)) {
            if (!button_pressed) {
                button_pressed = true;
                if (val == LENGTH - 1) {
                    val = 0;
                } else {
                    val++;
                }
            }
        } else if (!gpio_get(BUTTON_GPIO_DOWN)) {
            if (!button_pressed) {
                button_pressed = true;
                if (val == 0) {
                    val = LENGTH - 1;
                } else {
                    val--;
                }
            }
        } else {
            button_pressed = false;
        }

        // We are starting with GPIO 2, our bitmap starts at bit 0 so shift to start at 2.
        int32_t mask = bits[val] << FIRST_GPIO;

        // Set all our GPIOs in one go!
        // If something else is using GPIO, we might want to use gpio_put_masked()
        gpio_set_mask(mask);
        sleep_ms(150);
        gpio_clr_mask(mask);
    }
}
/// \end::hello_gpio[]
