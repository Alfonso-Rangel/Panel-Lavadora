#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#include <string.h>

class Controlador {
private:
    uart_inst_t* uart_id_;

public:
    Controlador(uart_inst_t* uart_id, uint tx_pin, uint rx_pin, uint baud_rate);

    void enviar_instruccion(const char* str);

    char* obtener_respuesta();
};

#endif // CONTROLADOR_H
