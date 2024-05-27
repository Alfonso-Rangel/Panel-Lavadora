cmake_minimum_required(VERSION 3.15)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(Panel-Lavadora C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(Encendido-Apagado)
add_subdirectory(Temporizador)
add_subdirectory(Menu)
add_subdirectory(Carga-de-Ropa)
add_subdirectory(Modo-Lavadora)
add_subdirectory(UART)
