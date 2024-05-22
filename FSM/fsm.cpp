#include "fsm.h"

// Constructor para inicializar el estado inicial
FSM::FSM(int initial_state) : current_state(initial_state) {}

// Método para obtener el estado actual
int FSM::getCurrentState() const {
    return current_state;
}

// Método para establecer una regla de transición
void FSM::setTransitionRule(int state, int event, int next_state) {
    transitions[std::make_tuple(state, event)] = next_state;
}

// Método para calcular el siguiente estado basado en el evento
void FSM::computeNextState(int event) {
    auto key = std::make_tuple(current_state, event);
    if (transitions.find(key) != transitions.end()) {
        current_state = transitions[key];
    } else {
        throw std::runtime_error("Transition not defined for the given state and event.");
    }
}