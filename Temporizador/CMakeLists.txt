add_executable(temporizador set_timer.c)
target_link_libraries(temporizador pico_stdlib)

pico_enable_stdio_usb(temporizador 1)
pico_enable_stdio_uart(temporizador 0)

pico_add_extra_outputs(temporizador )
