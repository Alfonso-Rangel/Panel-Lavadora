#include "../../include/Controlador.h"

Controlador::Controlador(uart_inst_t* uart_id, uint tx_pin, uint rx_pin, uint baud_rate) {
    uart_id_ = uart_id;
    uart_init(uart_id_, baud_rate);
    gpio_set_function(tx_pin, GPIO_FUNC_UART);
    gpio_set_function(rx_pin, GPIO_FUNC_UART);
}

void Controlador::enviar_instruccion(const char* str) {
    uart_puts(uart_id_, str);
    uart_putc(uart_id_, '\0'); 
}

char* Controlador::obtener_respuesta() {
    static char respuesta[32];
    char buffer[32];
    int index = 0;

    while (uart_is_readable(uart_id_)) {
        if (index >= sizeof(buffer) - 1) {break;}
        char c = uart_getc(uart_id_);
        if (c == '\0') {break;}
        buffer[index++] = c;
    }
    buffer[index] = '\0';
    strcpy(respuesta, buffer);
    return respuesta;
}
