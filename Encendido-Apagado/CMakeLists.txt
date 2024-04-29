add_executable(Encendido-Apagado
        on-off.c
        )

target_link_libraries(Encendido-Apagado
        pico_stdlib              # for core functionality
        pico_cyw43_arch_none     # we need Wifi to access the GPIO, but we don't need anything else
        )
pico_enable_stdio_usb(Encendido-Apagado 1)
pico_enable_stdio_uart(Encendido-Apagado 0)
# enable usb output, disable uart output
#pico_enable_stdio_usb(picow_blink 1)
#pico_enable_stdio_uart(picow_blink 0)

# create map/bin/hex/uf2 file etc.
# create map/bin/hex file etc.
pico_add_extra_outputs(Encendido-Apagado)

