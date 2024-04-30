# Temperatura
Esta funcion de fue realizada partiendo del codigo del visualizador de 7 segmentos (0-9, 9-0) 

## Funcionalidad Código
1. Primero se declara un arreglo de tamaño dos, con los leds que enciende cada letra.

2. Inicializamos el boton y le asignamos un GPIO en la rasperry.

3. Inicializamos dos variables importantes para la ejecucion del programa:
    * val: para recorrer el arreglo.
    * button_pressed: para indicar si el boton esta presionado.
4. Creamos un blucle infinito
    * Agregamos dos if en donde se evaluara si el boton esta presionado y poder cambiar a otra opcion.
### ¿Qué hace el código?
Sencillo es poder elegir entre dos opciones "C" que corresponde a agua fria(cold) y si presionas el boton nuevamente cambiamos a "H" que corresponde al agua Caliente.


