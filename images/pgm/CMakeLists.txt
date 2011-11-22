PROJECT(pgm_ppm_test)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(SRC pgm_test.c pgm.c pgm.h)
SET(SRC2 ppm_test.c ppm.c ppm.h)
ADD_EXECUTABLE(pgm_test ${SRC})
ADD_EXECUTABLE(ppm_test ${SRC2})
