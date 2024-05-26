#include <stdio.h>
#define PINS_SIZE 11

static uint32_t pins[PINS_SIZE];

/* @brief Tiempo de retardo */
static uint32_t const menu_delay = 5;

/* @brief Tiempo de retardo */
static uint32_t menu_mask = 0;

/* @brief El número o letra que se desea prender */
static unsigned int menu_val = 0;

/* @brief El valor que debe ir en ánodo 1 (O)*/
static unsigned int const menu_anode1 = 0;

/* @brief El valor que debe ir en ánodo 2 (P)*/
static unsigned int const menu_anode2 = 24;

/* @brief El valor que debe ir en ánodo 3 (C) */
static unsigned int const menu_anode3 = 12;

/* @brief El valor que debe ir en ánodo 4
 * entre 1-3 */
static unsigned int menu_anode4 = 1;

static unsigned int menu_count = 0;

/* @brief Constructor*/
void menu_construct(const int*);
/* @brief Inicializa*/
void init_menu();
/* @brief Setea una 'O' en el  primer ánado*/
void set_o();
/* @brief Setea una 'P' en el segundo ánado*/
void set_p();
/* @brief Setea una 'C' en el tercer ánado*/
void set_c();
/* @brief Setea 1, 2 o 3 en el cuarto ánado*/
void set_123();
/* @brief Retorna el valor*/
unsigned int get_val();
/* @brief V1 del código.
 * Lo pongo en esta función
 * para modularizar
 */
void turn_on_leds();
