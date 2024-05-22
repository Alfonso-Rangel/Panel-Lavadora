add_executable(transmisor
    transmisor.cpp
)

pico_enable_stdio_usb(transmisor 1)
pico_enable_stdio_uart(transmisor 1)

pico_add_extra_outputs(transmisor)

target_link_libraries(transmisor pico_stdlib)