#include "gpio_utils.h"

//arreglo de bits donde estan representadas las letras de la A a la Z
int bits[] = {
    0x5F, 0x7C, 0x39, 0x5E, 0x7B, 0x71, 0x6F, 0x74, 0x30, 0x1E,
    0x75, 0x38, 0x15, 0x37, 0x3F, 0x73, 0x67, 0x33, 0x6D, 0x78,
    0x3E, 0x2E, 0x2A, 0x76, 0x6E, 0x4B
};

//funcion para inicializar los pines GPIO
void gpio_init_pins() {
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio, 0); // Asegura que todos los leds esten apagados
    }
    //inicializa el pin GPIO para el boton como entrada y activa la resistencia pull up
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);
}

//funcion para manejar la pulsacion del boton
void gpio_handle_button_press(int *val, int *selected_bits) {
    static bool button_pressed = false;
    //Detecta la pulsacion del boton con un simple debucing
    if (!gpio_get(BUTTON_GPIO) && !button_pressed) {
        button_pressed = true;
        sleep_ms(50); // Debouncing delay
        *val = (*val + 1) % 3; //incrementa el valor y lo vuelve 0,1,2
        gpio_update_leds(*val, selected_bits); //actualiza los LEDS basados en el nuevo valor
    } else if (gpio_get(BUTTON_GPIO) && button_pressed) {
        button_pressed = false; //Reinicia el estado del boton
    }
}
//Funcion para actualizar los leds basados en el balor actual
void gpio_update_leds(int val, int *selected_bits) {
    static int32_t previous_mask = 0;

    //Apaga los LEDS anteriores
    gpio_clr_mask(previous_mask);

    // Enciende los leds para el valor actual
    int32_t mask = selected_bits[val];
    gpio_set_mask(mask << FIRST_GPIO);

    // almacena las mascara actualpara a apagar en la proxima actualizacion
    previous_mask = mask << FIRST_GPIO;
}
//funcion para establecer los bits seleccionados con indices especificos del arreglo de bits
void set_selected_bits(int *selected_bits, int a, int b, int c) {
    selected_bits[0] = bits[a];
    selected_bits[1] = bits[b];
    selected_bits[2] = bits[c];
}

//Funcion para configurar los bits para el estado caliente
void set_Caliente(int *selected_bits){
   set_selected_bits(selected_bits,5,5,5);
}

//Funcion para configurar los bits para el estado Frio

void set_Frio(int *selected_bits){
    set_selected_bits(selected_bits,2,2,2); 
}


