cmake_minimum_required(VERSION 3.10)

# Specify the project name
project(Wikitenaur-Image-Downloader)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

# libcurl 설정
find_package(CURL REQUIRED)
target_include_directories(main PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${CURL_LIBRARIES})