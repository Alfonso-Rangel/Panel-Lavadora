/* @brief ON_OFF_BUTTON 16
 * OK_BUTTON 14
 * MOV_BUTTON 15
 * */
#include <stdio.h>

/* @brief Valor del botón de encendido y apagado*/
static bool on_off_val = false;
/* @brief Valor del botón de aceptar*/
static bool ok_val = false;
/* @brief Valor del botón de mover*/
static bool mov_val = false;
/* @brief Valor del estado acutal del botón*/
static bool on_off_current_state = false;
/* @brief Valor del estado anterior del botón*/
static bool on_off_prev_state = false;
/* @brief Valor del estado acutal del botón*/
static bool ok_current_state = false;
/* @brief Valor del estado anterior del botón*/
static bool ok_prev_state = false;
/* @brief Valor del estado acutal del botón*/
static bool mov_current_state = false;
/* @brief Valor del estado anterior del botón*/
static bool mov_prev_state = false;

/* @brief Inicializa los botones*/
void init_buttons();
/* @brief Verifica si el botón de prendido y apagado es presionado*/
bool is_on_off_btn_press();
/* @brief Verifica si el botón mov es presionado*/
bool is_mov_btn_press();
/* @brief Verifica si el botón de aceptar es presionado*/
bool is_ok_btn_press();
/* @brief Regresa el valor del botón mov*/
bool get_mov_btn();
