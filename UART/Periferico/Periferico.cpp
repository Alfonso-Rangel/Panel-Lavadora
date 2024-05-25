#include <cstdio>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string.h>

class Periferico {
public:
    Periferico(uart_inst_t* uart_id, uint tx_pin, uint rx_pin, uint baud_rate) {
        uart_id_ = uart_id;
        uart_init(uart_id_, baud_rate);
        gpio_set_function(tx_pin, GPIO_FUNC_UART);
        gpio_set_function(rx_pin, GPIO_FUNC_UART);
    }

    void leer_y_responder() {
        char buffer[128];
        int index = 0;

        while (uart_is_readable(uart_id_)) {
            if (index >= sizeof(buffer) - 1) break;
            char c = uart_getc(uart_id_);
            if (c == '\n' || c == '\0') {break;}
            buffer[index++] = c;
        }
        buffer[index] = '\0';
        printf("Lectura: %s\n", buffer);
        char* respuesta = obtener_respuesta(buffer);
        printf("Respuesta: %s\n", respuesta);
        uart_puts(uart_id_, respuesta);
        uart_putc(uart_id_, '\n'); // Añadir un delimitador de nueva línea
    }

private:
    uart_inst_t* uart_id_;

    char* obtener_respuesta(const char* str) {
        static char respuesta_buffer[4]; // Suficientemente grande para "10" y "5" y "1"

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
};

int main() {
    stdio_init_all();
    Periferico periferico(uart1, 8, 9, 115200); // UART0, TX=GP0, RX=GP1, Baud rate = 115200

    while (true) {
        periferico.leer_y_responder();
        sleep_ms(1000); // Breve retraso para evitar un uso intensivo del CPU
    }

    return 0;
}
