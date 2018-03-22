cmake_minimum_required(VERSION 2.6)
project(numeros_primos)

add_executable(numeros_primos main.cpp)

install(TARGETS numeros_primos RUNTIME DESTINATION bin)
