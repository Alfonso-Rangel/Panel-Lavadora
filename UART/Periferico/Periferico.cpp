#include "../../include/Periferico.h"

Periferico::Periferico(uart_inst_t* uart_id, uint tx_pin, uint rx_pin, uint baud_rate) {
    uart_id_ = uart_id;
    uart_init(uart_id_, baud_rate);
    gpio_set_function(tx_pin, GPIO_FUNC_UART);
    gpio_set_function(rx_pin, GPIO_FUNC_UART);
}

char* Periferico::obtener_instruccion() {
    static char respuesta[32];
    char buffer[32];
    int index = 0;

    while (uart_is_readable(uart_id_)) {
        if (index >= sizeof(buffer) - 1) break;
        char c = uart_getc(uart_id_);
        if (c == '\n' || c == '\0') { break; }
        buffer[index++] = c;
    }
    buffer[index] = '\0';
    strcpy(respuesta, buffer);
    return respuesta;
}

void Periferico::enviar_respuesta(char* respuesta) {
    uart_puts(uart_id_, respuesta);
    uart_putc(uart_id_, '\n');
}
