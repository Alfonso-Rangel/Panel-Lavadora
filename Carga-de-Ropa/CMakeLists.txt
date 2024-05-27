add_executable(Carga-de-Ropa
    NivelCarga.cpp
    Test.cpp
)

pico_add_extra_outputs(Carga-de-Ropa)

target_link_libraries(Carga-de-Ropa pico_stdlib)