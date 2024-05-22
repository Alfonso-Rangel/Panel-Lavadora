#include <cstdio>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string.h>

#define UART_ID uart0
#define BAUD_RATE 9600
#define UART_TX_PIN 0
#define UART_RX_PIN 1

void setup_uart() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

const char* saludo() {
    return "Hola desde la Raspberry Pi Pico W 2";
}

int main() {
    stdio_init_all();
    setup_uart();

    char buffer[128];
    int index;

    while (true) {
        index = 0;

        // Leer comando
        while (uart_is_readable(UART_ID)) {
            buffer[index++] = uart_getc(UART_ID);
        }
        buffer[index] = '\0'; // Terminar la cadena

        // Verificar comando y responder
        if (strcmp(buffer, "GET_SALUDO") == 0) {
            uart_puts(UART_ID, saludo());
        }
    }

    return 0;
}
