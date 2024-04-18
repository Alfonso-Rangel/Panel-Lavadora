add_executable(Nivel-Agua
    nivel_agua.c
)

pico_add_extra_outputs(Nivel-Agua)

target_link_libraries(Nivel-Agua pico_stdlib)