add_executable(FSM
    FSM.cpp
    Test.cpp
    ../UART/Controlador/Controlador.cpp
    ../Temporizador.time.c
    ../Menu/button.c
    ../Menu/common.c
)

pico_add_extra_outputs(FSM)

target_link_libraries(FSM pico_stdlib)