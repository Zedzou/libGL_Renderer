cmake_minimum_required(VERSION 3.13)
PROJECT(Renderer)
set(PROJECT_NAME Renderer)

set(CMAKE_MODULE_PATH  ${PROJECT_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(gl3w REQUIRED)

include_directories(./include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} src/main.cpp src/glad.c)

target_link_libraries(${PROJECT_NAME} glfw pthread dl)
