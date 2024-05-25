#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

class SistemaDeCarga {
private:
    // GPIO settings for the 7-segment display
    static constexpr int FIRST_GPIO = 12; // Example GPIO pin number
    static constexpr int BUTTON_GPIO = 19; // Example GPIO pin for the button
    int pines[7];
    int32_t mask;
    int bits[26] = {
        0x5F, 0x7C, 0x39, 0x5E, 0x7B, 0x71, 0x6F, 0x74, 0x30, 0x1E,
        0x75, 0x38, 0x15, 0x37, 0x3F, 0x73, 0x67, 0x33, 0x6D, 0x78,
        0x3E, 0x2E, 0x2A, 0x76, 0x6E, 0x4B
    };
    int selected_bits[3];

    // GPIO settings for the LED bar
    int pinBotonIncremento;
    int pinBotonDecremento;
    int nivelActual;
    int* mascaraLeds;
    int* pinesLed;
    static constexpr int NIVELES = 11;

    bool button_pressed = false;

public:
    SistemaDeCarga(int* leds, int botonIncremento, int botonDecremento)
        : pinBotonIncremento(botonIncremento), pinBotonDecremento(botonDecremento)
    {
        nivelActual = 0;
        mascaraLeds = new int[NIVELES] {
            0b0000000000,
            0b0000000001,
            0b0000000011,
            0b0000000111,
            0b0010000111,
            0b0010010111,
            0b0010110111,
            0b0011110111,
            0b0011111111,
            0b0111111111,
            0b1111111111
        };
        pinesLed = leds;
    }

    ~SistemaDeCarga() {
        delete[] mascaraLeds;
    }

    void init() {
        // Initialize 7-segment display GPIOs
        for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
            gpio_init(gpio);
            gpio_set_dir(gpio, GPIO_OUT);
        }
        gpio_init(BUTTON_GPIO);
        gpio_set_dir(BUTTON_GPIO, GPIO_IN);
        gpio_pull_up(BUTTON_GPIO);

        // Initialize LED bar GPIOs
        for (int i = 0; i < 10; i++) {
            gpio_init(pinesLed[i]);
            gpio_set_dir(pinesLed[i], GPIO_OUT);
            gpio_set_outover(pinesLed[i], GPIO_OVERRIDE_INVERT);
        }
        gpio_init(pinBotonIncremento);
        gpio_init(pinBotonDecremento);
        gpio_set_dir(pinBotonIncremento, GPIO_IN);
        gpio_set_dir(pinBotonDecremento, GPIO_IN);
        gpio_pull_up(pinBotonIncremento);
        gpio_pull_up(pinBotonDecremento);
    }

    void handleButtonPress(int* val) {
        if (gpio_get(BUTTON_GPIO) && !button_pressed) {
            button_pressed = true;
            sleep_ms(200);
            if (gpio_get(BUTTON_GPIO)) {
                updateLeds(*val);
                if (*val == 2) {
                    *val = 0;
                } else {
                    (*val)++;
                }
            }
        } else if (!gpio_get(BUTTON_GPIO) && button_pressed) {
            button_pressed = false;
            sleep_ms(50);
        }
    }

    void updateLeds(int val) {
        static int32_t previous_mask = 0;

        // Clear previous LEDs
        gpio_clr_mask(previous_mask);

        // Set new LEDs for 7-segment display
        mask = selected_bits[val] << FIRST_GPIO;
        gpio_set_mask(mask);

        // Store current state for clearing next time
        previous_mask = mask;
    }

    void setSelectedBits(int a, int b, int c) {
        selected_bits[0] = bits[a];
        selected_bits[1] = bits[b];
        selected_bits[2] = bits[c];
    }

    bool seEstaIncrementando() {
        return !gpio_get(pinBotonIncremento);
    }

    bool seEstaDecrementando() {
        return !gpio_get(pinBotonDecremento);
    }

    void incrementarNivel() {
        if (nivelActual < NIVELES - 1) nivelActual++;
    }

    void decrementarNivel() {
        if (nivelActual > 0) nivelActual--;
    }

    int getNivel() {
        return nivelActual;
    }

    void setNivel(int nivel) {
        if (nivel >= 0 && nivel < NIVELES - 1) {
            nivelActual = nivel;
        }
    }

    void clear() {
        gpio_clr_mask(mask);
    }

    void enciendeLeds() {
        mask = mascaraLeds[nivelActual] << pinesLed[0];
        gpio_set_mask(mask);
    }

    void setNivelBajo() {
        nivelActual = 1;
    }

    void setNivelMedio() {
        nivelActual = 5;
    }

    void setNivelApagado() {
        nivelActual = 0;
    }
};

int main() {
    // Example GPIO pins for LEDs and buttons
    int leds[10] = {21, 20, 2, 3, 4, 5, 6, 7, 8, 9};
    int botonIncremento = 11;
    int botonDecremento = 10;

    SistemaDeCarga sistema(leds, botonIncremento, botonDecremento);
    sistema.init();

    int val = 0;
    sistema.setSelectedBits(5, 19, 2);

    while (true) {
        sistema.handleButtonPress(&val);
        if (sistema.seEstaIncrementando()) {
            sistema.incrementarNivel();
            sistema.enciendeLeds();
        }
        if (sistema.seEstaDecrementando()) {
            sistema.decrementarNivel();
            sistema.enciendeLeds();
        }
        sleep_ms(100); // Delay to prevent bouncing issues
    }

    return 0;
}
