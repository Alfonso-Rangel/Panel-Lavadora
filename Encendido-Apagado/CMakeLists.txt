add_executable(on-off
        test.c
        )

target_link_libraries(on-off
        pico_stdlib              # for core functionality
        )
pico_enable_stdio_usb(on-off 1)
pico_enable_stdio_uart(on-off 0)
# enable usb output, disable uart output
#pico_enable_stdio_usb(picow_blink 1)
#pico_enable_stdio_uart(picow_blink 0)

# create map/bin/hex/uf2 file etc.
# create map/bin/hex file etc.
pico_add_extra_outputs(on-off)


