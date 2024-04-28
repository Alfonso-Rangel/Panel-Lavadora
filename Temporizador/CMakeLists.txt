#add_executable(temporizador set_timer.c)
add_executable(timer timer.c test.c)
target_link_libraries(timer pico_stdlib)

pico_enable_stdio_usb(timer 1)
pico_enable_stdio_uart(timer 0)

pico_add_extra_outputs(timer)
