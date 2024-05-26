#include <iostream>
#include <thread>  // Para std::this_thread::sleep_for
#include <chrono>  // Para std::chrono::seconds
#include "../include/FSM.h"
#include "States.cpp"
#include "../include/Events.h"

int main() {
    FSM fsm;

    // Establecer reglas de transición
    fsm.setTransitionRule(0, MANTENER_ESTADO, 0);
    fsm.setTransitionRule(0, ON, 1);
    fsm.setTransitionRule(1, MANTENER_ESTADO, 1);
    fsm.setTransitionRule(1, OFF, 0);
    fsm.setTransitionRule(1, SEL_MODO, 2);
    fsm.setTransitionRule(2, MANTENER_ESTADO, 2);
    fsm.setTransitionRule(2, INICIA_TEMP, 3);
    fsm.setTransitionRule(2, OFF, 0);
    fsm.setTransitionRule(3, MANTENER_ESTADO, 3);
    fsm.setTransitionRule(3, TIMEOUT, 1);
    fsm.setTransitionRule(3, OFF, 0);
    

    while (true) {
        int state = fsm.getCurrentState();
        
        switch (state) {
        case 0:
            std::this_thread::sleep_for(std::chrono::seconds(1));
            fsm.computeNextState(state_0());
            break;
        case 1:
            std::this_thread::sleep_for(std::chrono::seconds(1));
            fsm.computeNextState(state_1()); // OFF o MODO_AUTO o MODO_MANUAL
            break;
        case 2:
            std::this_thread::sleep_for(std::chrono::seconds(1));
            fsm.computeNextState(state_2()); // OFF o PAUSA o TIMEOUT
            break;
        case 3:
            std::this_thread::sleep_for(std::chrono::seconds(1));
            fsm.computeNextState(state_3()); // OFF o PAUSA o TIMEOUT
            break;
        default: return;
        }
    }
    return 0;
}
