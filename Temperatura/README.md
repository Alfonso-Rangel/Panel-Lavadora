# Función-Lavadora
## Control de Leds con GPIO y Botón

En las funciones realizadas en el código hacemos uso de las GPIO de las Rasperry Pi Pico w para controlar el conjunto de los Led, cambiando entre los diferentes patrones de bits cuando se pressiona el botón.

## uso
- Presiona el boton para cambiar entre los tres estados(las letras que se hayan elegido).

- Para imprimir la misma letra, solo hay que pasar la letra al arreglo 3 veces.

## Funciones Principales
- **gpio_init_pins():** Inicializa los pines GPIO para los LEDs y el botón.
- **gpio_handle_button_press(int *val, int *selected_bits)**: Maneja la pulsación del botón y cambia el estado de los LEDs.
- **gpio_update_leds(int val, int *selected_bits):** Actualiza los LEDs según el estado actual.
- **set_selected_bits(int *selected_bits, int a, int b, int c)**: Establece los bits seleccionados para los estados de los LEDs.
- **set_Caliente(int *selected_bits):** Configura los bits seleccionados para el estado "Caliente".
- **set_Frio(int *selected_bits):** Configura los bits seleccionados para el estado "Frío".



