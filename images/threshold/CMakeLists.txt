PROJECT(threshold)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKE_C_FLAGS "-std=c99")

SET(SRC threshold.c iio.c iio.h)
ADD_EXECUTABLE(threshold ${SRC})
TARGET_LINK_LIBRARIES(threshold jpeg tiff png)