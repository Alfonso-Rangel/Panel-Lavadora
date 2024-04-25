#include "../include/nivel_carga.h"

int val = 0;

int bits[LENGTH] = {
       0b0000000000, // Sin carga 
       0b0000000001, // Carga baja
       0b0010010111, // Carga media
       0b0011111111, // Carga moderada
       0b1111111111 // Capacidad máxima
};

void initNivelCarga() {
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 10; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }
    gpio_init(BUTTON_GPIO_UP);
    gpio_init(BUTTON_GPIO_DOWN);
    gpio_set_dir(BUTTON_GPIO_UP, GPIO_IN);
    gpio_set_dir(BUTTON_GPIO_DOWN, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO_UP);
    gpio_pull_up(BUTTON_GPIO_DOWN);
}

bool estaSubiendo() {
     return !gpio_get(BUTTON_GPIO_UP);    
}

bool estaBajando() {
     return !gpio_get(BUTTON_GPIO_DOWN);    
}

int getEstadoBoton(int button_gpio) {
    return !gpio_get(button_gpio); // Invierte el valor porque se activa cuando se pulsa el botón
}

int getMask() {
    return bits[val];
}

void incrementaNivel() {
    val = (val == LENGTH - 1) ? 0 : val + 1;
}

void decrementaNivel() {
    val = (val == 0) ? LENGTH - 1 : val - 1;
}
