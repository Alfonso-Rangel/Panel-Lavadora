#include "../../include/nivel_carga.h"

#define NIVELES 5

int val = 0;

int boton_incrementa;
int boton_decrementa;

int bits[NIVELES] = {
       0b0000000000, // Sin carga 
       0b0000000001, // Carga baja
       0b0010010111, // Carga media
       0b0011111111, // Carga moderada
       0b1111111111 // Capacidad máxima
};

void initNivelCarga(int* leds_gpio, int button_up_gpio, int button_down_gpio) {
    // Configura los pines GPIO para los LEDs
    for (int i = 0; i < 10; i++) {
        gpio_init(leds_gpio[i]);
        gpio_set_dir(leds_gpio[i], GPIO_OUT);
        gpio_set_outover(leds_gpio[i], GPIO_OVERRIDE_INVERT);
    }
    
    // Configura los pines GPIO para los botones
    gpio_init(button_up_gpio);
    gpio_init(button_down_gpio);
    gpio_set_dir(button_up_gpio, GPIO_IN);
    gpio_set_dir(button_down_gpio, GPIO_IN);
    gpio_pull_up(button_up_gpio);
    gpio_pull_up(button_down_gpio);
    boton_incrementa = button_up_gpio;
    boton_decrementa = button_down_gpio;
}

bool estaSubiendo() {
     return !gpio_get(boton_incrementa);    
}

bool estaBajando() {
     return !gpio_get(boton_decrementa);    
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
