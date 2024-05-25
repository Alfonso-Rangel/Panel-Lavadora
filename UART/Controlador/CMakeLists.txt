add_executable(Controlador
    Controlador.cpp
)

pico_enable_stdio_usb(Controlador 1)
pico_enable_stdio_uart(Controlador 1)

pico_add_extra_outputs(Controlador)

target_link_libraries(Controlador pico_stdlib)