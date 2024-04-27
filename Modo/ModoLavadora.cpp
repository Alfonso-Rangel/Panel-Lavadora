#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "NivelCarga.h"

class ModoLavadora {
private:
    enum Modo { MANUAL, LAVADO_RAPIDO, LAVADO_NORMAL }; // Enum
    Modo modoActual; // Modo actual de la lavadora
    NivelCarga* nivelCarga; // Puntero a la instancia de la clase NivelCarga
    // Temperatura* temperatura;
    // Centrifugado* centrifugado;
    // Temposrizador* temporizador;

public:
    ModoLavadora(NivelCarga* nivelCarga) // Recibe también temperatura, centrifugado y temporizador 
        : modoActual(MANUAL), nivelCarga(nivelCarga)
    {
    }

    ~ModoLavadora() {
    }

    void setModo(Modo modo) {
        modoActual = modo;
        // Verificar el modo y ajustar el nivel de carga
        switch (modo) {
            case MANUAL:
                // El usuario controlará manualmente el nivel de carga
                break;
            case LAVADO_RAPIDO:
                nivelCarga->setNivel(1);
                // temperatura->setTemperatura();
                // centrifugado->setCentrifugado();
                // temposrizador->setTemporizador(); 
                break;
            case LAVADO_NORMAL:
                nivelCarga->setNivel(3); 
                // temperatura->setTemperatura();
                // centrifugado->setCentrifugado();
                // temposrizador->setTemporizador(); 
                break;
        }
    }
};
