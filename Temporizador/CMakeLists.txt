add_executable(timer test.c timer.c)
target_link_libraries(timer pico_stdlib)

pico_enable_stdio_usb(timer 1)
pico_enable_stdio_uart(timer 0)

pico_add_extra_outputs(timer)
