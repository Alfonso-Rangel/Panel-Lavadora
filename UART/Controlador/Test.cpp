#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../../include/Controlador.h"

int main() {
    stdio_init_all();

    Controlador controlador(uart1, 4, 5, 115200); // UART0, TX=GP0, RX=GP1, Baud rate = 115200

    const char* mensajes[] = {"NORMAL", "RAPIDO", "MANUAL"};
    int codigo = 0;

    while (true) {
        printf("Instrucción dada: %s\n", mensajes[codigo]);
        controlador.enviar_instruccion(mensajes[codigo]);
        sleep_ms(1000); // Esperar un poco antes de leer la respuesta
        char* respuesta = controlador.obtener_respuesta();
        printf("Respuesta recibida: %s\n", respuesta);
        codigo = (codigo >= 2) ? 0 : codigo + 1;
    }

    return 0;
}