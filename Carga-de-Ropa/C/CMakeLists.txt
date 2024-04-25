add_executable(C
    nivel_carga.c
    test.c
)

pico_add_extra_outputs(C)

target_link_libraries(C pico_stdlib)