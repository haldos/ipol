PROJECT(pgm_test)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(SRC pgm_test.c pgm.c pgm.h)
ADD_EXECUTABLE(pgm_test ${SRC})