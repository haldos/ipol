PROJECT(iio_test)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKE_C_FLAGS "-std=c99")

SET(SRC iio_test.c iio.c iio.h)
ADD_EXECUTABLE(iio_test ${SRC})
TARGET_LINK_LIBRARIES(iio_test jpeg tiff png)