#include "../include/NivelCarga.h"

NivelCarga::NivelCarga(int* leds, int botonIncremento, int botonDecremento)
    : pinBotonIncremento(botonIncremento), pinBotonDecremento(botonDecremento)
{
    nivelActual = 0;

    mascaraLeds = new int[NIVELES] {
        0b0000000000,
        0b0000000001,
        0b0000000011,
        0b0000000111,
        0b0010000111,
        0b0010010111,
        0b0010110111,
        0b0011110111,
        0b0011111111,
        0b0111111111,
        0b1111111111
    };
    
    mascaraNiveles = new int[3]{
        0b0000000001, 0b0010010111, 0b0011111111
    };
    
    pinesLed = leds;
}

void NivelCarga::init() {
    // Configurar pines GPIO para LEDs
    for (int i = 0; i < 10; i++) {
        gpio_init(pinesLed[i]);
        gpio_set_dir(pinesLed[i], GPIO_OUT);
        gpio_set_outover(pinesLed[i], GPIO_OVERRIDE_INVERT);
    }

    // Configurar pines GPIO para botones
    gpio_init(pinBotonIncremento);
    gpio_init(pinBotonDecremento);
    gpio_set_dir(pinBotonIncremento, GPIO_IN);
    gpio_set_dir(pinBotonDecremento, GPIO_IN);
    gpio_pull_up(pinBotonIncremento);
    gpio_pull_up(pinBotonDecremento);
}

NivelCarga::~NivelCarga() {
    delete[] mascaraLeds;
}

bool NivelCarga::seEstaIncrementando() {
    return !gpio_get(pinBotonIncremento);
}

bool NivelCarga::seEstaDecrementando() {
    return !gpio_get(pinBotonDecremento);
}


void NivelCarga::incrementarNivel() {
    if (nivelActual < NIVELES - 1) nivelActual++;
    //nivelActual = (nivelActual == NIVELES - 1) ? 0 : nivelActual + 1;
}

void NivelCarga::decrementarNivel() {
    if (nivelActual > 0) nivelActual--;
    //nivelActual = (nivelActual == 0) ? NIVELES - 1 : nivelActual - 1;
}

int NivelCarga::getNivel() {
    return nivelActual;
}

void NivelCarga::setNivel(int nivel) {
    if (nivel >= 0 && nivel < NIVELES - 1) {
        nivelActual = nivel;
    }
}

void NivelCarga::clear() {
    gpio_clr_mask(mask);
}

void NivelCarga::enciendeLeds() {
    mask = mascaraLeds[nivelActual] << pinesLed[0];
    gpio_set_mask(mask);
}

void NivelCarga::setNivelApagado() {
    nivelActual = 0;
}

void NivelCarga::setNivelBajo() {
    nivelActual = 1;
}

void NivelCarga::setNivelMedio() {
    nivelActual = 5;
}
