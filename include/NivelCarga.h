#ifndef NIVELCARGA_H
#define NIVELCARGA_H
/**
 * @file NivelCarga.h
 * @brief Clase para controlar el nivel de carga con LEDs y botones en una Raspberry Pico W.
 */
#include "pico/stdlib.h"
#include "hardware/gpio.h"
/**
 * @brief Clase para controlar el nivel de carga de ropa con LEDs y botones.
 */
class NivelCarga {
private:
    int nivelActual; // Nivel de carga de ropa actual
    int* mascarasNiveles;
    int* pinesLed; // Apuntador a arreglo de 10 elementos
    int pinBotonIncremento;
    int pinBotonDecremento;
    static constexpr int NIVELES = 5;

public:
    /**
     * @brief Constructor de la clase NivelCarga.
     * @param leds Puntero al array de 10 pines GPIO para los LEDs.
     * @param botonIncremento Pin GPIO para el botón de incremento.
     * @param botonDecremento Pin GPIO para el botón de decremento.
     */
    NivelCarga(int* leds, int botonIncremento, int botonDecremento);

    /**
     * @brief Destructor de la clase NivelCarga.
     * Libera la memoria asignada para las máscaras de niveles.
     */
    ~NivelCarga();

    /**
     * @brief Comprueba si se está presionando el botón de incremento.
     * @return true si se está presionando el botón de incremento, false en caso contrario.
     */
    bool seEstaIncrementando();

    /**
     * @brief Comprueba si se está presionando el botón de decremento.
     * @return true si se está presionando el botón de decremento, false en caso contrario.
     */
    bool seEstaDecrementando();

    /**
     * @brief Obtiene la máscara de bits del nivel de carga actual.
     * @return La máscara de bits del nivel de carga actual.
     */
    int getMascara();

    /**
     * @brief Incrementa el nivel de carga.
     */
    void incrementarNivel();
    /**
     * @brief Decrementa el nivel de carga.
     */
    void decrementarNivel();

    /**
     * @return Un entero entre 0 y 4 que representa el nivel actual.
    */
    int getNivel();

    /**
     * @brief Establece un nivel entre el 0 y 4, en otro caso no hace nada.
    */
    void setNivel(int nivel);
};
#endif // NIVELCARGA_H