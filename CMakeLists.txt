cmake_minimum_required(VERSION 3.10.2)

project(floyd)

set(library_SOURCES
    src/floyd.cpp
)

add_library(floyd_library STATIC ${library_SOURCES})

target_include_directories(floyd_library
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create an executable
############################################################

# Source fles for the binary
set(binary_SOURCES
    src/main.cpp
)

# Add an executable with the above sources
add_executable(floyd_binary ${binary_SOURCES})

# link the new hello_library target with the hello_binary target
target_link_libraries( floyd_binary
    PRIVATE floyd_library
)