#include <stdio.h>
#define PINS_SIZE 11

/* @brief*/
static uint32_t pins[PINS_SIZE];

/* @brief*/
static uint32_t timer_mask;

/* @brief*/
static uint32_t const timer_delay = 5;

/* @brief*/
static unsigned int min = 0;

/* @brief*/
static unsigned int sec = 0;

/* @brief*/
static unsigned int val = 0;

/* @brief Contador para el decremento de los minutos y segundos */
static unsigned int ctr = 0;

/* @brief*/
static int const bits[] = {
  0x3f,
  0x06,
  0x5b,
  0x4f,
  0x66,
  0x6d,
  0x7d,
  0x07,
  0x7f,
  0x67 
};


/* @brief*/
void timer_construct(const int*);

/* @brief*/
void timer_init();

/* @brief*/
uint32_t timer_read_value();

/* @brief*/
void timer_turn_led_on();

/* @brief*/
void timer_clear();

/* @brief*/
void clear_timer();

/* @brief Inicializa los minutos y los segundos */
void set_time(unsigned int, unsigned int);

/* @brief Regresa el valor de los minutos */
unsigned int get_min();

/* @brief Regresa el valor de los segundos */
unsigned int get_sec();

/* @brief Decrementa los minutos */
void dec_min();

/* @brief Decrementa los segundos */
void dec_sec();

/* @brief Presetea los segundos a 59 */
void preset_sec();

/* @brief Regresa el valor del contador */
unsigned int get_ctr();

/* @brief Incrementa el contador */
void inc_ctr();

/* @brief Resetea el contador */
void reset_ctr();

/* @brief Enciende el primer ánodo mientras apaga los demás,
 * y regresa el número que encenderá */
unsigned int set_anode_1();

/* @brief Enciende el segundo ánodo mientras apaga los demás,
 * y regresa el número que encenderá */
unsigned int set_anode_2();

/* @brief Enciende el tercer ánodo mientras apaga los demás,
 * y regresa el número que encenderá  */
unsigned int set_anode_3();

/* @brief Enciende el cuarto ánodo mientras apaga los demás,
 * y regresa el número que encenderá  */
unsigned int set_anode_4();

/* @brief Agrega ceros en los cuatro ánodos */
unsigned int set_zeros();
