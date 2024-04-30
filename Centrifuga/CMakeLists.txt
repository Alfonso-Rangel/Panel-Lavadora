add_executable(centrifuga
        centrifuga.c
        )

# pull in common dependencies
target_link_libraries(centrifuga pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(centrifuga)

# add url via pico_set_program_url
example_auto_set_url(centrifuga)
