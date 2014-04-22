project(segunda_parte)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)
set(EXAMPLES primero segundo tercero)
set(SOURCES )
foreach(var ${EXAMPLES})
add_executable(${var} ${var}.c)
set(SOURCES ${var}.c)
endforeach()

SOURCE_GROUP(EJEMPLOS_SOURCES ${SOURCES})
