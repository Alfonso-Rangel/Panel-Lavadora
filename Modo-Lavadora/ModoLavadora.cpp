#include "../include/ModoLavadora.h"
#include "../include/NivelCarga.h"   
ModoLavadora::ModoLavadora(NivelCarga* nivelCarga, int botonCambio) // Recibe también temperatura, centrifugado y temporizador 
    : modoActual(MANUAL), nivelCarga(nivelCarga), pinBotonCambio(botonCambio)
{
}

void ModoLavadora:: init() {
    gpio_init(pinBotonCambio);
    gpio_set_dir(pinBotonCambio, GPIO_IN);
    gpio_pull_up(pinBotonCambio);
}

ModoLavadora::~ModoLavadora() {
}

void ModoLavadora::cambiaModo() {
    switch (modoActual) {
        case MANUAL: modoActual = LAVADO_RAPIDO; break;
        case LAVADO_RAPIDO: modoActual = LAVADO_NORMAL; break;
        case LAVADO_NORMAL: modoActual = MANUAL; break;
        default: break;
    }
}

void ModoLavadora::aplicaModo() {
    switch (modoActual) {
        case MANUAL: 
            nivelCarga->setNivelApagado();
            break;
        case LAVADO_RAPIDO:
            nivelCarga->setNivelBajo();
            // temperatura->setTemperatura();
            // centrifugado->setCentrifugado();
            // temposrizador->setTemporizador(); 
            break;
        case LAVADO_NORMAL:
            nivelCarga->setNivelMedio(); 
            // temperatura->setTemperatura();
            // centrifugado->setCentrifugado();
            // temposrizador->setTemporizador(); 
            break;
        default: break;
    }
}

bool ModoLavadora::modoManual() {
    return modoActual == MANUAL;
}

bool ModoLavadora::seEstaCambiandoModo() {
    return !gpio_get(pinBotonCambio);
}