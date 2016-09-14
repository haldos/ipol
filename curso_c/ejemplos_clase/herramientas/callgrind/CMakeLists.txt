project(segunda_parte)

cmake_minimum_required(VERSION 2.8)

set(EXAMPLES primero)
set(SOURCES )
foreach(var ${EXAMPLES})
add_executable(${var} ${var}.c)
target_link_libraries(${var} m)
set(SOURCES ${var}.c)
endforeach()

SOURCE_GROUP(EJEMPLOS_SOURCES ${SOURCES})

add_definitions("-std=c99")


