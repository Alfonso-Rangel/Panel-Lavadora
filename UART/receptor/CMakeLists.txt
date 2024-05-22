add_executable(receptor
    receptor.cpp
)

pico_enable_stdio_usb(receptor 1)
pico_enable_stdio_uart(receptor 1)

pico_add_extra_outputs(receptor)

target_link_libraries(receptor pico_stdlib)