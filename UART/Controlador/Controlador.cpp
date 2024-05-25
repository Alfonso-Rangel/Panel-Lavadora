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
        uart_putc(uart_id_, '\n'); // Añadir un delimitador de nueva línea
    }

    void esperar_respuesta() {
        char buffer[255];
        int index = 0;

        while (uart_is_readable_within_us(uart_id_, 1000000)) { // Esperar hasta 1 segundo
            buffer[index++] = uart_getc(uart_id_);
            if (index >= sizeof(buffer) - 1) break;
        }
        buffer[index] = '\0';
        printf("Respuesta recibida: %s\n", buffer);
    }

private:
    uart_inst_t* uart_id_;
};

int main() {
    stdio_init_all();

    Controlador controlador(uart0, 0, 1, 115200); // UART0, TX=GP0, RX=GP1, Baud rate = 115200

    const char* mensajes[] = {"NORMAL", "RAPIDO", "MANUAL"};
    int codigo = 0;

    while (true) {
        controlador.enviar_string(mensajes[0]);
        sleep_ms(100); // Esperar un poco antes de leer la respuesta
        controlador.esperar_respuesta();
        codigo = (codigo > 2) ? 0 : codigo + 1;
        
        sleep_ms(1000); // Esperar un segundo antes de enviar el siguiente código
    }

    return 0;
}
