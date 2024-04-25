add_executable(C++
    NivelCarga.cpp
    Test.cpp
)

pico_add_extra_outputs(C++)

target_link_libraries(C++ pico_stdlib)