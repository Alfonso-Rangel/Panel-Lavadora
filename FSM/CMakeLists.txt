add_executable(FSM
    fsm.c
)

pico_add_extra_outputs(FSM)

target_link_libraries(FSM pico_stdlib)