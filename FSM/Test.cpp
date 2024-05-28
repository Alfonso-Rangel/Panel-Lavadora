#include <iostream>
#include "../include/FSM.h"
#include "../include/Events.h"
#include "../include/Controlador.h"

extern "C" {
#include "../Menu/button.h"
#include "../Menu/menu.h"
#include "../Menu/common.h"
#include "../Menu/pin_list.h"
#include "../Temporizador/timer.h"
}

int state_0() {
    /*  Este estado controla el encendido y apagado.
        --------------------------------------------
        Si se ha precionado el boton de encendido:
            regresa ON
        En otro caso:
            regresa MANTENER_ESTADO
    */
    if (is_on_off_btn_press()) {
        return ON;
    }
    return MANTENER_ESTADO;
}

int state_1() {
    /*  Aquí se leen los botones de:
        - Encendido/Apagado
        - Cambiar modo
        - Aceptar
        -------------------------------------
        Si se ha precionado el boton de apagado:
            regresa OFF
        Si no, si se ha leído el botón de aceptar:
            setModo(modo) <- Se supone que aquí se debe tener el modo de lavado almacenado en una variable
            regresa SEL_MODO
        En otro caso:
            regresa MANTENER_ESTADO
    */

    if (!is_on_off_btn_press()) {
        return OFF;
    }
    else {
        turn_on_options();
        if (is_ok_btn_press()) {
            char * opcion = "MANUAL";
            switch (get_opc()) {
                case 1: 
                    opcion = "NORMAL";
                    break;
                case 2: 
                    opcion = "RAPIDO";
                    break;
                case 3: 
                    opcion = "MANUAL";
                    break;
                default: break;
            }
            Controlador controlador(uart0, 0, 1, 115200);
            controlador.enviar_instruccion(opcion);
            sleep_ms(1000); // Esperar un poco antes de leer la respuesta 
            const char* respuesta = controlador.obtener_respuesta();
            set_time(respuesta);
            return INICIA_TEMP;
        }
    }
    return MANTENER_ESTADO;
}

int state_2() {
    /*  Este estado se encarga de correr el temporizador 
        -------------------------------------------------
        Si se ha precionado el boton de apagado:
            regresa OFF
        Si no, si el temporizador llegó a 0:
            regresa TIMEOUT
        En otro caso
            contunúa la cuanta regresiva
            regresa MANTENER_ESTADO 
    */
    if (!is_on_off_btn_press()) {
        return OFF;
    }
    else if(is_time_out()) {
        return TIMEOUT;
    }
    else {
        dec_timer();
        return MANTENER_ESTADO;
    }
}

int main() {
    int pins[] = {
        PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G,
        D1, D2, D3, D4
    };
    construct(pins);
    stdio_init_all();
    init();

    init_buttons();

    FSM fsm;

    // Establecer reglas de transición
    fsm.setTransitionRule(0, MANTENER_ESTADO, 0);
    fsm.setTransitionRule(0, ON, 1);
    fsm.setTransitionRule(1, MANTENER_ESTADO, 1);
    fsm.setTransitionRule(1, OFF, 0);
    fsm.setTransitionRule(1, INICIA_TEMP, 2);
    fsm.setTransitionRule(2, MANTENER_ESTADO, 2);
    fsm.setTransitionRule(2, TIMEOUT, 1);
    fsm.setTransitionRule(2, OFF, 0);
    

    while (true) {
        int state = fsm.getCurrentState();
        
        switch (state) {
            case 0:
                fsm.computeNextState(state_0());
                break;
            case 1:
                fsm.computeNextState(state_1());
                break;
            case 2:
                fsm.computeNextState(state_2()); 
                break;
            default: break;
        }
    }
    return 0;
}
