// main.c
#include <stdio.h>
#include "pico/stdlib.h"
#include "gpio_utils.h"

int main() {
    stdio_init_all();
    printf("Presiona el botón para elegir la letra del abecedario que gustes\n");

    gpio_init_pins();

    int val = 0;
    int selected_bits[3];

    /*// Configurar los tres valores del arreglo bits que el usuario quiere usar
    int a = 5; // índice del primer valor (cambiar según el valor deseado) F
    int b = 19; // índice del segundo valor (cambiar según el valor deseado) T
    int c = 2; // índice del tercer valor (cambiar según el valor deseado) C*/

    //set_selected_bits(selected_bits, a, b, c);
    set_Caliente(selected_bits);
    while (true) {
        gpio_handle_button_press(&val, selected_bits);
    }

    return 0;
}
