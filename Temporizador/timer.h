#include <stdio.h>
#define PINS_SIZE 11

/* @brief*/
static uint32_t pins[PINS_SIZE];

/* @brief*/
static uint32_t timer_mask;

/* @brief*/
static uint32_t const timer_delay = 6;

/* @brief**/
static int d1 = 0;
static int d2 = 0;
static int d3 = 0;
static int d4 = 0;

/* @brief*/
static int bits[] = {
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


void timer_construct(const int*);
void timer_init();
uint32_t timer_read_value();
void timer_turn_led_on();
void timer_clear();
void clear_timer();
void set_time(int, int);
int get_time();
