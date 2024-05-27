#include "../include/NivelCarga.h"

NivelCarga::NivelCarga(int* leds, int botonIncremento, int botonDecremento)
    : pinBotonIncremento(botonIncremento), pinBotonDecremento(botonDecremento), pinesLed(leds), nivelActual(0) {
    mascaraLeds = new int[NIVELES] {
        0b1111111111,
        0b0111111111,
        0b0011111111,
        0b0001111111,
        0b0000111111,
        0b0000011111,
        0b0000001111,
        0b0000000111,
        0b0000000011,
        0b0000000001,
        0b0000000000 

        /*0b1111111111,  // Nivel 0: Todos los LEDs apagados
        0b0000000001,  // Nivel 1: Solo el primer LED encendido
        0b0000000011,  // Nivel 2: Los primeros 2 LEDs encendidos
        0b0000000111,  // Nivel 3: Los primeros 3 LEDs encendidos
        0b0000001111,  // Nivel 4: Los primeros 4 LEDs encendidos
        0b0000011111,  // Nivel 5: Los primeros 5 LEDs encendidos
        0b0000111111,  // Nivel 6: Los primeros 6 LEDs encendidos
        0b0001111111,  // Nivel 7: Los primeros 7 LEDs encendidos
        0b0011111111,  // Nivel 8: Los primeros 8 LEDs encendidos
        0b0111111111,  // Nivel 9: Los primeros 9 LEDs encendidos
        0b0000000000  //todos encendidos*/
        
    };
}

NivelCarga::~NivelCarga() {
    delete[] mascaraLeds;
}

void NivelCarga::init() {
    // Configurar pines GPIO para LEDs
    for (int i = 0; i < 10; i++) {
        gpio_init(pinesLed[i]);
        gpio_set_dir(pinesLed[i], GPIO_OUT);
    }

    // Configurar pines GPIO para botones
    gpio_init(pinBotonIncremento);
    gpio_init(pinBotonDecremento);
    gpio_set_dir(pinBotonIncremento, GPIO_IN);
    gpio_set_dir(pinBotonDecremento, GPIO_IN);
    gpio_pull_up(pinBotonIncremento);
    gpio_pull_up(pinBotonDecremento);
}

bool NivelCarga::seEstaIncrementando() {
    return !gpio_get(pinBotonIncremento);
}

bool NivelCarga::seEstaDecrementando() {
    return !gpio_get(pinBotonDecremento);
}

void NivelCarga::incrementarNivel() {
    if (nivelActual < NIVELES - 1) nivelActual++;
}

void NivelCarga::decrementarNivel() {
    if (nivelActual > 0) nivelActual--;
}

void NivelCarga::enciendeLeds() {
    int32_t mask = mascaraLeds[nivelActual];
    for (int i = 0; i < 10; i++) {
        gpio_put(pinesLed[i], mask & (1 << i));
    }
}

void NivelCarga::clear() {
    for (int i = 0; i < 10; i++) {
        gpio_put(pinesLed[i], 0);
    }
}

int NivelCarga::getNivel() {
    return nivelActual;
}

void NivelCarga::setNivel(int nivel) {
    if (nivel >= 0 && nivel < NIVELES) {
        nivelActual = nivel;
    }
}

void NivelCarga::setNivelApagado() {
    setNivel(0);
}

void NivelCarga::setNivelBajo() {
    setNivel(1);
}

void NivelCarga::setNivelMedio() {
    setNivel(5);
}
