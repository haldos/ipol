PROJECT(test_clg_flow)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_C_FLAGS "-std=c99")
SET(PROJECT_SOURCE_DIR source)
SET(PROJECT_BINARY_DIR bin)

ADD_SUBDIRECTORY(source)

SET(SRC ${PROJECT_SOURCE_DIR}/clg_of.c)
ADD_EXECUTABLE(${PROJECT_BINARY_DIR}/test_clg_flow ${SRC})
TARGET_LINK_LIBRARIES(${PROJECT_BINARY_DIR}/test_clg_flow png tiff jpeg ${LIBS})

INSTALL(TARGETS ${PROJECT_BINARY_DIR}/test_clg_flow RUNTIME DESTINATION bin)
SET(CPACK_GENERATOR "TGZ")
SET(CPACK_SOURCE_GENERATOR "TGZ")
SET(CPACK_SOURCE_IGNORE_FILES "CMakeFiles;_CPack_Packages;images;bin;./*.cmake;
                ;./install_manifest.txt;./Makefile;./*.tar.gz;./CMakeCache.txt;
                ;./source/libiio.so;./source/libnrutil.so")
INCLUDE(CPack)