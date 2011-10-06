PROJECT(test_flow)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKE_C_FLAGS "-g -std=c99")

SET(SRC test_flow.c iio.c iio.h)
ADD_EXECUTABLE(test_flow ${SRC})
TARGET_LINK_LIBRARIES(test_flow jpeg tiff png)

IF (UNIX)
    SET(OTHER_FILES CMakeLists.txt a.png b.png flow)
    EXECUTE_PROCESS(COMMAND tar -czvf test_flow.tar.gz ${OTHER_FILES} ${SRC})
    EXECUTE_PROCESS(COMMAND zip test_flow.zip ${OTHER_FILES} ${SRC})
ENDIF (UNIX)