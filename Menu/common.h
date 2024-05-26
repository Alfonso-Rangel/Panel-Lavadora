#include <stdio.h>

#define PINS_SIZE 11
/* @brief Arreglo con los valores de 0-9
 * A-Z
 * excepto o*/
static int const bits[] = {
  0x3f, // 0
  0x06, // 1
  0x5b, // 2
  0x4f, // 3
  0x66, // 4
  0x6d, // 5
  0x7d, // 6
  0x07, // 7
  0x7f, // 8
  0x67, // 9
  0x5F, // A - 10
  0x7C, // B - 11
  0x39, // C - 12
  0x5E, // D - 13
  0x7B, // E - 14
  0x71, // F - 15
  0x6F, // G - 16
  0x74, // H - 17
  0x30, // I - 18
  0x1E, // J - 19
  0x75, // K - 20
  0x38, // L - 21
  0x15, // M - 22
  0x37, // N - 23
  0x73, // P - 24
  0x67, // Q - 25
  0x33, // R - 26
  0x6D, // S - 27
  0x78, // T - 28
  0x3E, // U - 29
  0x2E, // V - 30
  0x2A, // W - 31
  0x76, // X - 32
  0x6E, // Y - 33
  0x4B  // Z - 34
};

/* @brief*/
static uint32_t pins[PINS_SIZE];

/* @brief La máscara */
static uint32_t mask = 0;

/* @brief Tiempo de retardo */
static uint32_t const delay = 5;

/* @brief*/
void construct(const int*);

/* @brief*/
void init();
