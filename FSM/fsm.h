#ifndef FSM_H
#define FSM_H

#include <iostream>
#include <map>
#include <tuple>

// Definición de la clase FSM
class FSM {
private:
  int current_state;  // Estado actual
  std::map<std::tuple<int, int>, int> transitions;  // Mapa de transiciones

public:
  // Constructor para inicializar el estado inicial
  FSM(int initial_state = 0);

  // Método para obtener el estado actual
  int getCurrentState() const;

  // Método para establecer una regla de transición
  void setTransitionRule(int state, int event, int next_state);

  // Método para calcular el siguiente estado basado en el evento
  void computeNextState(int event);
};

#endif // FSM_H
