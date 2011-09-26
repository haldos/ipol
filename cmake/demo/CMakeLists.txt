include_directories ($QUINTO_SOURCE_DIR}/code) 
link_directories (${QUINTO_BINARY_DIR}/code) 

add_executable (quinto quinto.c auxiliares.c)
target_link_libraries (quintoDemo quinto) 