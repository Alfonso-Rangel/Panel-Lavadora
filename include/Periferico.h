#ifndef PERIFERICO_H
#define PERIFERICO_H

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <stdlib.h>
#include <string.h>

class Periferico {
private:
    uart_inst_t* uart_id_;

public:
    Periferico(uart_inst_t* uart_id, uint tx_pin, uint rx_pin, uint baud_rate);

    char* obtener_instruccion();

    void enviar_respuesta(char* respuesta);
};

#endif // PERIFERICO_H
