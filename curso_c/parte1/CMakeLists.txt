 project(EJEMPLOS)

cmake_minimum_required(VERSION 2.8)

set(EXAMPLES primer segundo tercer cuarto segundo2)
set(SOURCES )
foreach(var ${EXAMPLES})
add_executable(${var} ${var}.c)
set(SOURCES ${var}.c)
endforeach()

SOURCE_GROUP(EJEMPLOS_SOURCES ${SOURCES})

add_executable(quinto quinto.c auxiliares.c)
