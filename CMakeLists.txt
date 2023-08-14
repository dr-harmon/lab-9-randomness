cmake_minimum_required(VERSION 3.20)

set(TARGET_NAME lab9)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)

project("${TARGET_NAME}" VERSION 1.0 LANGUAGES CXX)

# Target
file(GLOB TARGET_SRC_FILES CONFIGURE_DEPENDS src/*)
add_library("${TARGET_NAME}" ${TARGET_SRC_FILES})
target_include_directories("${TARGET_NAME}" PUBLIC src)

# Main application
add_executable("${TARGET_NAME}_main" main.cpp)
target_link_libraries("${TARGET_NAME}_main" PRIVATE "${TARGET_NAME}")
