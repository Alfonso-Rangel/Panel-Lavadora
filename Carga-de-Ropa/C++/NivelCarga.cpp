#include "pico/stdlib.h"
#include "hardware/gpio.h"

class NivelCarga {
private:
    int val;
    int* bits;
    int* leds_gpio;
    int boton_incremento; // Cambiado el nombre del parámetro
    int boton_decremento; // Cambiado el nombre del parámetro
    const int NIVELES = 5;

public:
    NivelCarga(int* leds, int boton_incremento, int boton_decremento) // Cambiado el nombre del parámetro
        : boton_incremento(boton_incremento), boton_decremento(boton_decremento) // Inicialización de miembros en la lista de inicialización
    {
        val = 0;
        bits = new int[NIVELES]{0b0000000000, 0b0000000001, 0b0010010111, 0b0011111111, 0b1111111111};
        leds_gpio = leds;

        // Configurar los pines GPIO para los LEDs
        for (int i = 0; i < 10; i++) {
            gpio_init(leds_gpio[i]);
            gpio_set_dir(leds_gpio[i], GPIO_OUT);
            gpio_set_outover(leds_gpio[i], GPIO_OVERRIDE_INVERT);
        }

        // Configurar los pines GPIO para los botones
        gpio_init(this->boton_incremento); // Utilizamos this-> para referenciar el miembro de la clase
        gpio_init(this->boton_decremento); // Utilizamos this-> para referenciar el miembro de la clase
        gpio_set_dir(this->boton_incremento, GPIO_IN); // Utilizamos this-> para referenciar el miembro de la clase
        gpio_set_dir(this->boton_decremento, GPIO_IN); // Utilizamos this-> para referenciar el miembro de la clase
        gpio_pull_up(this->boton_incremento); // Utilizamos this-> para referenciar el miembro de la clase
        gpio_pull_up(this->boton_decremento); // Utilizamos this-> para referenciar el miembro de la clase
    }

    bool estaSubiendo() {
        return !gpio_get(boton_incremento);
    }

    bool estaBajando() {
        return !gpio_get(boton_decremento);
    }

    int getMask() {
        return bits[val];
    }

    void incrementaNivel() {
        val = (val == NIVELES - 1) ? 0 : val + 1;
    }

    void decrementaNivel() {
        val = (val == 0) ? NIVELES - 1 : val - 1;
    }
};
