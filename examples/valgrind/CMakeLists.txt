project(segunda_parte)

cmake_minimum_required(VERSION 2.8)

set(EXAMPLES primero segundo tercero cuarto  quinto)
set(SOURCES )
foreach(var ${EXAMPLES})
add_executable(${var} ${var}.c)
set(SOURCES ${var}.c)
endforeach()

SOURCE_GROUP(EJEMPLOS_SOURCES ${SOURCES})
