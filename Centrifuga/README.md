-- Simulador de Centrifugado para Lavadora --

Este proyecto simula la función de centrifugado de una lavadora utilizando una Raspberry Pi Pico W y un display de 7 segmentos. El sistema permite a los usuarios iniciar o reiniciar la simulación de la cuenta regresiva del proceso de centrifugado mediante un botón.

- Hardware Requerido:
1. Raspberry Pi Pico W
2. Display de 7 segmentos
3. Resistencias adecuadas para los segmentos del display
4. Botón pulsador
5. Protoboard y cables de conexión

- Funcionalidad del Software:
  El código en C controla el display de 7 segmentos para mostrar una cuenta regresiva de 9 a 0, simbolizando la duración restante del ciclo de centrifugado. El botón permite al usuario interactuar con el sistema para iniciar o reiniciar la cuenta regresiva en cualquier momento.

Descripción detallada:

Al presionar el botón, se detecta un cambio de estado que activa la cuenta regresiva en el display.
Los números se muestran secuencialmente con un intervalo de 1 segundo, representando los segundos restantes del ciclo de centrifugado.
La cuenta regresiva se detiene al llegar a 0 y el sistema queda a la espera de otra acción del usuario para reiniciar.

Diagrama:
![image](https://github.com/Alfonso-Rangel/Panel-Lavadora/assets/66036399/2bc09f77-c380-4bfd-b4a5-0379bdddd454)