#ifndef GPIO_UTILS_H
#define GPIO_UTILS_H
#include <stdio.h> //libreria estandar de entrada y salida
#include "pico/stdlib.h" //libreria que contiene funciones para los perifericos
#include "hardware/gpio.h" //libreria para manipular GPIO


#ifdef __cplusplus
extern "C" {
#endif
#define FIRST_GPIO 12
#define BUTTON_GPIO (FIRST_GPIO + 7)
extern int bits[];

void gpio_init_pins();
void gpio_handle_button_press(int *val, int *selected_bits);
void gpio_update_leds(int val, int *selected_bits);
void set_selected_bits(int *selected_bits, int a, int b, int c);
void set_Caliente();
void set_Frio();
#ifdef __cplusplus
}
#endif

#endif


/*// gpio_utils.h
#ifndef GPIO_UTILS_H
#define GPIO_UTILS_H


#ifdef __cpulsplus
extern "c"{

}
#include <stdio.h> //libreria estandar de entrada y salida
#include "pico/stdlib.h" //libreria que contiene funciones para los perifericos
#include "hardware/gpio.h" //libreria para manipular GPIO


#define FIRST_GPIO 12
#define BUTTON_GPIO (FIRST_GPIO + 7)

extern int bits[];

void gpio_init_pins();
void gpio_handle_button_press(int *val, int *selected_bits);
void gpio_update_leds(int val, int *selected_bits);
void set_selected_bits(int *selected_bits, int a, int b, int c);

#endif // GPIO_UTILS_H*/
