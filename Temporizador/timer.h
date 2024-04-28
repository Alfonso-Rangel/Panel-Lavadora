#include <stdio.h>
#define PINS_SIZE 11

/* @brief*/
static uint32_t pins[PINS_SIZE];

/* @brief*/
static uint32_t timer_mask;

/* @brief*/
static uint32_t bits[] = {
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
static uint32_t const timer_delay = 6;

void timer_construct(const int*);
void timer_init();
int* get_time(int);
void timer_read_values();
