add_executable(Periferico
    Periferico.cpp
)

pico_enable_stdio_usb(Periferico 1)
pico_enable_stdio_uart(Periferico 1)

pico_add_extra_outputs(Periferico)

target_link_libraries(Periferico pico_stdlib)