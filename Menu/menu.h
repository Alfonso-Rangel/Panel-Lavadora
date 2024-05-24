#include <stdio.h>
#define PINS_SIZE 11

static uint32_t pins[PINS_SIZE];

/* @brief Tiempo de retardo */
static uint32_t const menu_delay = 5;

/* @brief Tiempo de retardo */
static uint32_t mask = 0;

/* @brief El número que se desea prender */
static unsigned int val = 0;

static unsigned int anode4 = 1;

static unsigned int count = 0;

/* @brief*/
static int const bits[] = {
  0x3f, // 0-o
  0x06, // 1
  0x5b, // 2
  0x4f, // 3
  0x39, // c
  0x73 // p
};

/* @brief Constructor*/
void construct(const int*);
/* @brief Inicializa*/
void init();
/* @brief Setea el primer ánado*/
void set_anode_1();
/* @brief Setea el segundo ánado*/
void set_anode_2();
/* @brief Setea el tercer ánado*/
void set_anode_3();
/* @brief Setea el cuarto ánado*/
void set_anode_4();
/* @brief Retorna el valor*/
unsigned int get_val();
/* @brief V1 del código.
 * Lo pongo en esta función
 * para modularizar
 */
void turn_on_leds();
