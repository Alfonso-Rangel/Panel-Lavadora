#ifndef MODOLAVADORA_H
#define MODOLAVADORA_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../Carga-de-Ropa/NivelCarga.h"

class ModoLavadora {
private:
   enum Modo { MANUAL, LAVADO_RAPIDO, LAVADO_NORMAL }; // Enum
    Modo modoActual; // Modo actual de la lavadora
    int pinBotonCambio;
    NivelCarga* nivelCarga; // Puntero a la instancia de la clase NivelCarga
    // Temperatura* temperatura;
    // Centrifugado* centrifugado;
    // Temposrizador* temporizador;

public:
    /**
     * @brief Constructor de la clase ModoLavadora.
     * @param nivelCarga Puntero a la instancia de la clase NivelCarga.
     */
    ModoLavadora(NivelCarga* nivelCarga, int botonCambio);

    /**
     * @brief Destructor de la clase ModoLavadora.
     */
    ~ModoLavadora();

    void init();
    void cambiaModo();
    void aplicaModo();
    bool modoManual();
    bool seEstaCambiandoModo();
};
#endif //