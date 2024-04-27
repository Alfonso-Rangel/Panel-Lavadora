#include "pico/stdlib.h"
#include "hardware/gpio.h"

class NivelCarga {
private:
    int nivelActual; 
    int* mascarasNiveles;
    int* pinesLed;
    int pinBotonIncremento;
    int pinBotonDecremento;
    static constexpr int NIVELES = 5;

public:
    NivelCarga(int* leds, int botonIncremento, int botonDecremento)
        : pinBotonIncremento(botonIncremento), pinBotonDecremento(botonDecremento)
    {
        nivelActual = 0;
        mascarasNiveles = new int[NIVELES]{0b0000000000, 0b0000000001, 0b0010010111, 0b0011111111, 0b1111111111};
        pinesLed = leds;

        // Configurar pines GPIO para LEDs
        for (int i = 0; i < 10; i++) {
            gpio_init(pinesLed[i]);
            gpio_set_dir(pinesLed[i], GPIO_OUT);
            gpio_set_outover(pinesLed[i], GPIO_OVERRIDE_INVERT);
        }

        // Configurar pines GPIO para botones
        gpio_init(pinBotonIncremento);
        gpio_init(pinBotonDecremento);
        gpio_set_dir(pinBotonIncremento, GPIO_IN);
        gpio_set_dir(pinBotonDecremento, GPIO_IN);
        gpio_pull_up(pinBotonIncremento);
        gpio_pull_up(pinBotonDecremento);
    }


    ~NivelCarga() {
        delete[] mascarasNiveles;
    }

    bool seEstaIncrementando() {
        return !gpio_get(pinBotonIncremento);
    }

    bool seEstaDecrementando() {
        return !gpio_get(pinBotonDecremento);
    }

    int getMascara() {
        return mascarasNiveles[nivelActual];
    }

    void incrementarNivel() {
        nivelActual = (nivelActual == NIVELES - 1) ? 0 : nivelActual + 1;
    }

    void decrementarNivel() {
        nivelActual = (nivelActual == 0) ? NIVELES - 1 : nivelActual - 1;
    }

    int getNivel() {
        return nivelActual;
    }

    void setNivel(int nivel) {
        if (nivel > 0 && nivel < NIVELES - 1) {
            nivelActual = nivel;
        }
    }
};
