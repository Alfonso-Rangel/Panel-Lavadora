#include <cstdio>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>

class Controlador {
public:
    Controlador(uart_inst_t* uart_id, uint tx_pin, uint rx_pin, uint baud_rate) {
        uart_id_ = uart_id;
        uart_init(uart_id_, baud_rate);
        gpio_set_function(tx_pin, GPIO_FUNC_UART);
        gpio_set_function(rx_pin, GPIO_FUNC_UART);
    }

    void enviar_string(const char* str) {
        uart_puts(uart_id_, str);
        uart_putc(uart_id_, '\n'); 
    }

    char* esperar_respuesta(char *buffer) {
        int index = 0;

        while (uart_is_readable(uart_id_)) {
            if (index >= sizeof(buffer) - 1) break;
            char c = uart_getc(uart_id_);
            if (c == '\n' || c == '\0') {break;}
            buffer[index++] = c;
        }
        buffer[index] = '\0';
        return buffer;
        
    }

private:
    uart_inst_t* uart_id_;
};

int main() {
    stdio_init_all();

    Controlador controlador(uart1, 4, 5, 115200); // UART0, TX=GP0, RX=GP1, Baud rate = 115200

    const char* mensajes[] = {"NORMAL", "RAPIDO", "MANUAL"};
    int codigo = 0;

    while (true) {
        printf("Instrucción dada: %s\n", mensajes[codigo]);
        controlador.enviar_string(mensajes[codigo]);
        sleep_ms(1000); // Esperar un poco antes de leer la respuesta
        char respuesta[16];
        controlador.esperar_respuesta(respuesta);
        printf("Respuesta recibida: %s\n", respuesta);
        codigo = (codigo >= 2) ? 0 : codigo + 1;
    }

    return 0;
}
