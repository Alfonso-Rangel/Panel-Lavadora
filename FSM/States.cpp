#include <iostream>
#include "../include/Events.h"
#include "../include/Controlador.h"
#include "../Menu/button.h"
#include "../Menu/menu.h"
#include "../Temporizador/timer.h"

char * opcion = "MANUAL";

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
    if (is_on_off_btn_press()) {
        return OFF;
    }
    else if (is_ok_btn_press()) {
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
        default:
            opcion = "MANUAL";
            break;
        }
        return SEL_MODO;
    }
    return MANTENER_ESTADO;
}

int state_2() {
    /*  En este estado se ejecuta la comunicación con el periférico (leds de carga de ropa y temperatura)
        ------------------------------------------------------
    */
    if (is_on_off_btn_press()) {
        return OFF;
    }
    else {
        Controlador controlador(uart1, 4, 5, 115200);
        controlador.enviar_instruccion(modo);
        sleep_ms(1000); // Esperar un poco antes de leer la respuesta 

        const char* respuesta = controlador.obtener_respuesta();
        int num = 0;

        try {
            num = std::stoi(respuesta);  // convierte char* a std::string automáticamente
        } catch (const std::invalid_argument& e) {
            num = 0; 
        } catch (const std::out_of_range& e) {
            num = 0;
        }
        set_timer(num, 0);
        return INICIA_TEMP;
    }
}


int state_3() {
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
    if (is_on_off_btn_press()) {
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