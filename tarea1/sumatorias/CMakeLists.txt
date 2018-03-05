cmake_minimum_required(VERSION 2.6)
project(sumatorias)

add_executable(sumatorias main.cpp)
add_executable(sumatoria1 sumatoria1.cpp)
add_executable(sumatoria2 sumatoria2.cpp)
add_executable(sumatoria3 sumatoria3.cpp)

install(TARGETS sumatorias RUNTIME DESTINATION bin)
