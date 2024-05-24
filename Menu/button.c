#include <stdio.h>
#include "hardware/gpio.h"
#include "button.h"
#include "pin_list.h"

void init_buttons() {
  gpio_init(ON_OFF_BUTTON);
  gpio_set_dir(ON_OFF_BUTTON, GPIO_IN);
  gpio_pull_up(ON_OFF_BUTTON);

  gpio_init(OK_BUTTON);
  gpio_set_dir(OK_BUTTON, GPIO_IN);
  gpio_pull_up(OK_BUTTON);

  gpio_init(MOV_BUTTON);
  gpio_set_dir(MOV_BUTTON, GPIO_IN);
  gpio_pull_up(MOV_BUTTON);
}

bool is_on_off_btn_press() {
  on_off_current_state = gpio_get(ON_OFF_BUTTON);
  if (!on_off_current_state && on_off_prev_state) {
    on_off_val = !on_off_val;
  }
  on_off_prev_state = on_off_current_state;

  if (on_off_val) {
    printf("Botón ON-OFF ENCENDIDO\n");
  } else {
    printf("Botón ON-OFF APAGADO\n");
  }

  return on_off_val;
}

bool is_mov_btn_press() {
  mov_current_state = gpio_get(MOV_BUTTON);
  if (!mov_current_state && mov_prev_state) {
    mov_val = !mov_val;
  }
  mov_prev_state = mov_current_state;

  if (mov_val) {
    printf("Botón MOV ENCENDIDO\n");
  } else {
    printf("Botón MOV APAGADO\n");
  }

  return mov_val;
}

bool is_ok_btn_press() {
  ok_current_state = gpio_get(OK_BUTTON);
  if (!ok_current_state && ok_prev_state) {
    ok_val = !ok_val;
  }
  ok_prev_state = ok_current_state;

  if (ok_val) {
    printf("Botón OK ENCENDIDO\n");
  } else {
    printf("Botón OK APAGADO\n");
  }

  return ok_val;
}

bool get_mov_btn() {
  return gpio_get(MOV_BUTTON);
}
