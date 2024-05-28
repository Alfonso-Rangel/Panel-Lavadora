#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../../include/Periferico.h"

char* obtener_respuesta(const char* str) {
        static char respuesta_buffer[4];

        if (strcmp(str, "NORMAL") == 0) {
            strcpy(respuesta_buffer, "10");
            return respuesta_buffer;
        } else if (strcmp(str, "RAPIDO") == 0) {
            strcpy(respuesta_buffer, "5");
            return respuesta_buffer;
        } else if (strcmp(str, "MANUAL") == 0) {
            strcpy(respuesta_buffer, "1");
            return respuesta_buffer;
        } else {
            strcpy(respuesta_buffer, "0");
            return respuesta_buffer;
        }
    }

int main() {
    stdio_init_all();
    Periferico periferico(uart0, 0, 1, 115200); // UART0, TX=GP0, RX=GP1, Baud rate = 115200

    while (true) {
        char* instruccion =  periferico.obtener_instruccion();
        //printf("Instrucción recibida: %s\n", instruccion);
        if (instruccion[0] != '\0' || instruccion[0] != '\n') {
            char* respuesta = obtener_respuesta(instruccion);
            periferico.enviar_respuesta(respuesta);
            //printf("Respuesta dada: %s\n", respuesta);
        }
        sleep_ms(1000);
    }

    return 0;
}