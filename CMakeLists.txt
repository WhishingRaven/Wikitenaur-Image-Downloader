cmake_minimum_required(VERSION 3.10)

# Specify the project name
project(Wikitenaur-Image-Downloader)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/downloader.cpp
    src/file_utils.cpp
)

# Create the executable
add_executable(main ${SOURCES})
target_link_libraries(main curl)