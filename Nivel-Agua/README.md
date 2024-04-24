# Funcionalidad Nivel del Agua
### Objetivo 
Desarrollar un panel que controle el nivel carga para asignar el nivel del agua de la lavadora.
Este panel cuenta con una barra de leds de 10 segmentos y dos botones para bajar y subir el nivel.
Hay 4 niveles en total. 

### Lista de Archivos
1. *CMakeLists.txt* :: Necesario para la construcción del proyecto.
2. *nivel_agua.c* :: Código de la funcionalidad de nivel de carga.

### Materiales Requeridos
Una lista de materiales necesarios para visualizar el módulo del proyecto.
| Material |  Cantidad  |
|:-----|:--------:|
| Raspberry Pico W | 1 | 
| Barra 10 segmentos |  1  |
| Resistencia 85 ohm | 14 | 
| Botón | 2 |
| Cable tipo Dupont| 26 |


### Reporte de Tareas | 23/04/2024
Estas tareas tienen como objetivo ayudarme a estudiar el funcionamiento de la Raspberry para lograr el objetivo de este módulo del panel.
- [✓] Encender todos los leds con un botón para comprobar que las conexiones sean correctas. 
- [✓] Usar el botón para encender los leds uno por uno, de forma secuencial.
- [✓] Conectar un segundo botón y encender los leds en sentido contrario al primer botón.
- [✓] Encender varios leds a la vez, pues de 10 leds sólo se hacen hay 4 niveles.
- [ ] Crear una función que devuelva el nivel de carga actualmente seleccionado.