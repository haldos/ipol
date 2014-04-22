PROJECT(DemoABC)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(LIBSRC a b c libabc.h)
ADD_LIBRARY(abc SHARED ${LIBSRC})


#setup Config.cmake
SET(ABC_BASE_DIR "${PROJECT_SOURCE_DIR}")
set(ABC_CMAKE_DIR "${PROJECT_BINARY_DIR}")
configure_file(abcConfig.cmake.in
  "${PROJECT_BINARY_DIR}/abcConfig.cmake" @ONLY)