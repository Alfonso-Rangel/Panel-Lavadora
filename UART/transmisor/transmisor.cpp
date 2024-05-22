#include <cstdio>
#include "pico/stdlib.h"
#include "hardware/uart.h"

#define UART_ID uart0
#define BAUD_RATE 9600
#define UART_TX_PIN 0
#define UART_RX_PIN 1

void setup_uart() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}

int main() {
    stdio_init_all();
    setup_uart();

    char cmd[] = "GET_SALUDO";
    char buffer[128];
    int index;

    while (true) {
        // Enviar comando
        uart_puts(UART_ID, cmd);

        // Esperar un poco para la respuesta
        sleep_ms(100);

        // Leer respuesta
        index = 0;
        while (uart_is_readable(UART_ID)) {
            buffer[index++] = uart_getc(UART_ID);
        }
        buffer[index] = '\0'; // Terminar la cadena

        // Imprimir respuesta
        printf("Received: %s\n", buffer);

        // Esperar antes de enviar el próximo comando
        sleep_ms(1000);
    }

    return 0;
}
