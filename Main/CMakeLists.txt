add_executable(Main
    main.c
)

pico_add_extra_outputs(Main)

target_link_libraries(Main pico_stdlib)