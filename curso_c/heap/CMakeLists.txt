project(heap)

cmake_minimum_required(VERSION 2.8)

set(EXE heaptest)
set(SOURCES heaptest.c heap.c)

set(CMAKE_C_FLAGS "-std=c99")

add_executable(${EXE} ${SOURCES})


