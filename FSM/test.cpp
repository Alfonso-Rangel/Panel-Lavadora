#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <thread>  // Para std::this_thread::sleep_for
#include <chrono>  // Para std::chrono::seconds
#include "fsm.h"   // Suponemos que la clase FSM está en el archivo FSM.h


int random1() {
    std::srand(std::time(nullptr));
    return rand() % 2 + 2;
}

int random2() {
    std::srand(std::time(nullptr));
    return rand() % 2 == 0 ? 0 : rand() % 2 + 5;
}

// Función de prueba para la FSM
void fsmTest() {
    FSM fsm;

    // Definir eventos
    enum Event {
        OFF = 0,
        ON,
        MODO_AUTO,
        MODO_MANUAL,
        NO_TIMEOUT,
        TIMEOUT,
        PAUSA
    };

    // Establecer reglas de transición
    fsm.setTransitionRule(0, ON, 1);
    fsm.setTransitionRule(1, OFF, 0);
    fsm.setTransitionRule(1, MODO_MANUAL , 2);
    fsm.setTransitionRule(1, MODO_AUTO, 3);
    fsm.setTransitionRule(2, OFF, 0);
    fsm.setTransitionRule(2, PAUSA, 1);
    fsm.setTransitionRule(2, TIMEOUT, 1);
    fsm.setTransitionRule(2, NO_TIMEOUT, 2);
    fsm.setTransitionRule(3, OFF, 0);
    fsm.setTransitionRule(3, PAUSA, 1);
    fsm.setTransitionRule(3, TIMEOUT, 1);
    fsm.setTransitionRule(3, NO_TIMEOUT, 3);

    while (true) {
        int state = fsm.getCurrentState();
        std::cout << "Current state: " << state << std::endl;

        // Simular eventos y transiciones   
        switch (state) {
        case 0:
            std::this_thread::sleep_for(std::chrono::seconds(1));
            fsm.computeNextState(ON);
            break;
        case 1:
            std::this_thread::sleep_for(std::chrono::seconds(1));
            fsm.computeNextState(random1()); // OFF o MODO_AUTO o MODO_MANUAL
            break;
        case 2:
            std::this_thread::sleep_for(std::chrono::seconds(1));
            fsm.computeNextState(random2()); // OFF o PAUSA o TIMEOUT
            break;
        case 3:
            std::this_thread::sleep_for(std::chrono::seconds(1));
            fsm.computeNextState(random2()); // OFF o PAUSA o TIMEOUT
            break;
        default:
            std::cerr << "Estado desconocido." << std::endl;
            return;
        }
    }
}

int main() {
    fsmTest();
    return 0;
}
