add_executable(Modo-Lavadora
    ModoLavadora.cpp
    Test.cpp
)

pico_add_extra_outputs(Modo-Lavadora)

target_link_libraries(Modo-Lavadora pico_stdlib)