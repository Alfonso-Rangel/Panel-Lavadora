add_executable(Temperatura
	temperatura.c
	gpio_utils.c
    
)

pico_add_extra_outputs(Temperatura)

target_link_libraries(Temperatura pico_stdlib)
