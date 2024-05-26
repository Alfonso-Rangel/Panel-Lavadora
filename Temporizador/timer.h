#include <stdio.h>
#define PINS_SIZE 11

/* @brief*/
static uint32_t pins[PINS_SIZE];

/* @brief La máscara */
static uint32_t timer_mask;

/* @brief Tiempo de retardo */
static uint32_t const timer_delay = 5;

/* @brief Minutos del temporizador */
static unsigned int min = 0;

/* @brief Segundos del temporizador */
static unsigned int sec = 0;

/* @brief El número que se desea prender */
static unsigned int timer_val = 0;

/* @brief Contador para el decremento de los minutos y segundos */
static unsigned int timer_ctr = 0;

/*TAL VEZ BORRAR get_min, get_sec, dec_min, dec_sec, preset_sec, 
 * get_ctr, inc_ctr, reset_ctr por redundacia.
 *
 * dec_ctr hace todo eso.*/

/* @brief*/
void timer_construct(const int*);

/* @brief*/
void init_timer();

/* @brief*/
void timer_turn_led_on();

/* @brief*/
void clear_timer();

/* @brief Inicializa los minutos y los segundos */
void set_timer(unsigned int, unsigned int);

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

/* @brief Verifica si el tiempo se acabo */
bool is_time_over();

/* @brief Regresa el valor del contador */
unsigned int get_ctr();

/* @brief Incrementa el contador */
void inc_ctr();

/* @brief Resetea el contador */
void reset_ctr();

/* @brief Enciende el primer ánodo mientras apaga los demás,
 * y se establece el número que se encenderá */
void turn_minute_1();

/* @brief Enciende el segundo ánodo mientras apaga los demás,
 * y se establece el número que se encenderá */
void turn_minute_0();

/* @brief Enciende el tercer ánodo mientras apaga los demás,
 * y se establece el número que se encenderá */
void turn_sec_1();

/* @brief Enciende el cuarto ánodo mientras apaga los demás,
 * y se establece el número que se encenderá */
void turn_sec_0();

/* @brief Agrega ceros a los cuatro ánodos */
void set_zeros();

/* @brief Decrementa el contador */
void dec_ctr();

/* @brief Decrementa el temporizador*/
void dec_timer();
