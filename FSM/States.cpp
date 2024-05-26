#include <iostream>
#include "../include/Events.h"
#include "../include/Controlador.h"

int state_0() {
    /*  Este estado controla el encendido y apagado.
        --------------------------------------------
        Si se ha precionado el boton de encendido:
            regresa ON
        En otro caso:
            regresa MANTENET_ESTADO
    */
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
            regresa OFF
    */
    return OFF;
}

int state_2() {
    /*  En este estado se ejecuta la comunicación con el periférico (leds de carga de ropa y temperatura)
        ------------------------------------------------------
        Si se ha precionado el boton de apagado:
            regresa OFF
        En otro caso:
            Controlador controlador(uart1, 4, 5, 115200);
            char* instruccion = getModo(); <- Se obtiene el modo almacenado en una variable 
            controlador.enviar_instruccion(instruccion);
            sleep_ms(1000); // Esperar un poco antes de leer la respuesta
            char* respuesta = controlador.obtener_respuesta();
            temporizador.setTiempo(respuesta) <- Deberías tener una funcion que le indique al temporizador desde dónde iniciar 
            la cuenta regresiva
            regresa INICIA_TEMP;
    */
    return INICIA_TEMP;
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
    return TIMEOUT;
}