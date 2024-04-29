#ifndef NIVELCARGA_H
#define NIVELCARGA_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"

/**
 * @file NivelCarga.h
 * @brief Clase para controlar el nivel de carga con LEDs y botones en una Raspberry Pico W.
 */

class NivelCarga {
private:
    int nivelActual; // Representa el nivel de carga de ropa actual
    int* mascarasNiveles; // Máscaras de niveles de carga
    int* pinesLed; // Puntero a arreglo de 10 elementos para los LEDs
    int pinBotonIncremento; // Pin GPIO para el botón de incremento
    int pinBotonDecremento; // Pin GPIO para el botón de decremento
    int32_t mask; // Máscara actual de LEDs encendidos
    static constexpr int NIVELES = 11; // Total de niveles de carga de ropa

public:
    /**
     * @brief Constructor de la clase NivelCarga.
     * @param leds Puntero al array de 10 pines GPIO para los LEDs.
     * @param botonIncremento Pin GPIO para el botón de incremento.
     * @param botonDecremento Pin GPIO para el botón de decremento.
     */
    NivelCarga(int* leds, int botonIncremento, int botonDecremento);

    /**
     * @brief Inicializa la configuración de pines GPIO.
     */
    void init();

    /**
     * @brief Destructor de la clase NivelCarga.
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
     * @brief Incrementa el nivel de carga.
     */
    void incrementarNivel();

    /**
     * @brief Decrementa el nivel de carga.
     */
    void decrementarNivel();

    /**
     * @brief Obtiene el nivel de carga actual.
     * @return Un entero entre 0 y 4 que representa el nivel actual.
     */
    int getNivel();

    /**
     * @brief Establece un nivel de carga específico.
     * @param nivel El nivel de carga deseado.
     */
    void setNivel(int nivel);

    /**
     * @brief Limpia la máscara actual de LEDs encendidos.
     */
    void clear();

    /**
     * @brief Enciende los LEDs correspondientes al nivel de carga actual.
     */
    void enciendeLeds();
};

#endif // NIVELCARGA_H
