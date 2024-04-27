#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "NivelCarga.h"

class ModoLavadora {
private:
    enum Modo { MANUAL, LAVADO_RAPIDO, LAVADO_NORMAL }; // Enumeración para los modos de la lavadora
    Modo modoActual; // Modo actual de la lavadora
    NivelCarga* nivelCarga; // Puntero a la instancia de la clase NivelCarga

public:
    /**
     * @brief Constructor de la clase ModoLavadora.
     * @param nivelCarga Puntero a la instancia de la clase NivelCarga.
     */
    ModoLavadora(NivelCarga* nivelCarga);

    /**
     * @brief Destructor de la clase ModoLavadora.
     */
    ~ModoLavadora();

    /**
     * @brief Método para establecer el modo de la lavadora.
     * @param modo El nuevo modo de la lavadora (MANUAL, LAVADO_RAPIDO o LAVADO_NORMAL).
     */
    void setModo(Modo modo);
};
