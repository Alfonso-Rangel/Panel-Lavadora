# Funcionalidad Nivel de la Carga de Ropa
### Objetivo 
Desarrollar un panel que controle el nivel carga  de ropa para asignar el nivel del agua de la lavadora.
Este panel cuenta con una barra de leds de 10 segmentos y dos botones para bajar y subir el nivel.
Hay 4 niveles en total. 

### Lista de Archivos
1. *CMakeLists.txt* :: Necesario para la construcción del proyecto.
2. *nivel_carga.c* :: Código de la funcionalidad de nivel de carga.
3. *test.c* :: Pruebas y ejemplo de utilización.

### Materiales Requeridos
Una lista de materiales necesarios para visualizar el módulo del proyecto.
| Material |  Cantidad  |
|:-----|:--------:|
| Raspberry Pico W | 1 | 
| Barra 10 segmentos |  1  |
| Resistencia 85 ohm | 14 | 
| Botón | 2 |
| Cable tipo Dupont| 26 |


## Resumen del Sprint 
### Criterios de aceptación
1. Que el usuario pueda seleccionar entre 4 diferentes niveles de carga de ropa, representados por una serie de LED en el panel de la lavadora.
2. Los niveles de carga de ropa están definidos de forma clara y comprensible para que el usuario pueda identificar fácilmente la cantidad de prendas correspondiente a cada nivel.
3. Al seleccionar un nivel de carga, la lavadora ajusta automáticamente el llenado de agua y el ciclo de lavado para adaptarse a la cantidad de ropa seleccionada.
### Definición de Terminado (Done)
- [x] Se ha implementado una clase llamada NivelCarga que controla el nivel de carga de ropa en la lavadora.
- [x] La clase NivelCarga proporciona métodos para *seleccionar*, *ajustar* y *obtener* el nivel de carga, además de *encender* los LEDs.
- [x] Se ha integrado la clase NivelCarga con la Raspberry Pico W para permitir la interacción del usuario con los diferentes niveles de carga.
- [x] La documentación del código y los comentarios son claros y completos para facilitar la comprensión y mantenimiento del sistema.

