PROJECT(test_flow)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKE_C_FLAGS "-g -std=c99")

SET(SRC test_flow.c iio.c iio.h)
ADD_EXECUTABLE(test_flow ${SRC})
TARGET_LINK_LIBRARIES(test_flow jpeg tiff png)
