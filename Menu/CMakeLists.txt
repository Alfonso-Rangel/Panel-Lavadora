add_executable(
  menu
  test.c
  menu.c
  button.c
  common.c
  ../Temporizador/timer.c
)

target_link_libraries(menu pico_stdlib)

pico_enable_stdio_usb(menu 1)
pico_enable_stdio_uart(menu 0)

pico_add_extra_outputs(menu)
