cmake_minimum_required(VERSION 3.21)
project(SnakeGame VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(src)

set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/assets)
file(GLOB IMAGE_FILES ${RESOURCE_DIR}/*.jpg ${RESOURCE_DIR}/*.png)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

find_package(Raylib REQUIRED)

add_executable(SnakeGame src/main.cpp)

add_custom_command(
    TARGET SnakeGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${IMAGE_FILES} ${CMAKE_BINARY_DIR}/assets   
)
target_link_libraries(SnakeGame Application raylib)