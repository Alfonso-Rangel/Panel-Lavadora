#include <stdio.h> //libreria estandar de entrada y salida
#include "pico/stdlib.h" //libreria que contiene funciones para los perifericos
#include "hardware/gpio.h" //libreria para manipular GPIO

#define FIRST_GPIO 2 //primer pin que utilizaremos
#define BUTTON_GPIO (FIRST_GPIO + 7) //calculamos el in del boton


int bits[] = {//declaramos un arreglo que almacena  los patrones de bits
     0x39, //C //valores exadecimales para la c y la h
     0x76  //H
};

int main() {
    stdio_init_all();//inicializa la comunicación estandar de entrada y salida 
    printf("Presiona el botón para imprimir 'C', presiona dos veces para imprimir 'H'\n");

    //bucle que inicializa y configura los pines GPIO del 2 al 8
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }
 
    //inicia el GPIO DE EL BOTON como pin de entrada 
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    int val = 0;//variable para alternar entre los bits de los arreglos
    bool button_pressed = false;//variable que indica si el boton esta presionado

    while (true) {//bucle infinito
        // Espera a que se presione el botón
        if (gpio_get(BUTTON_GPIO) && !button_pressed) {
            button_pressed = true;
            // Espera un breve tiempo para evitar el rebote del botón
            sleep_ms(500);

            // Verifica si el botón sigue presionado, lo que indicaría una segunda pulsación
            if (gpio_get(BUTTON_GPIO)) {
                val = !val; // Cambia entre 0 y 1
                int32_t mask = bits[val] << FIRST_GPIO;
                gpio_set_mask(mask);
                sleep_ms(1000);
            }
        } else if (!gpio_get(BUTTON_GPIO) && button_pressed) {
            // Espera a que el botón se libere antes de permitir otra pulsación
            button_pressed = false;
            gpio_clr_mask(bits[val] << FIRST_GPIO);
            sleep_ms(50);
        }
    }

    return 0;
}

