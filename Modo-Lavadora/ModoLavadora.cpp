#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../Carga-de-Ropa/NivelCarga.cpp"

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
    ModoLavadora(NivelCarga* nivelCarga, int botonCambio) // Recibe también temperatura, centrifugado y temporizador 
        : modoActual(MANUAL), nivelCarga(nivelCarga), pinBotonCambio(botonCambio)
    {
        gpio_init(pinBotonCambio);
        gpio_set_dir(pinBotonCambio, GPIO_IN);
        gpio_pull_up(pinBotonCambio);
    }

    ~ModoLavadora() {
    }

    void cambiaModo() {
        // Verificar el modo y ajustar el nivel de carga
        switch (modoActual) {
            case MANUAL:
                modoActual = LAVADO_RAPIDO;
                break;
            case LAVADO_RAPIDO:
                nivelCarga->setNivel(1);
                // temperatura->setTemperatura();
                // centrifugado->setCentrifugado();
                // temposrizador->setTemporizador(); 
                modoActual = LAVADO_NORMAL;
                break;
            case LAVADO_NORMAL:
                nivelCarga->setNivel(3); 
                // temperatura->setTemperatura();
                // centrifugado->setCentrifugado();
                // temposrizador->setTemporizador(); 
                modoActual = MANUAL;
                break;
        }
    }

    bool modoManual() {
        return modoActual == MANUAL;
    }

    bool seEstaCambiandoModo() {
        return !gpio_get(pinBotonCambio);
    }
};
