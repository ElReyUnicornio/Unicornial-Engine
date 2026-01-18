cmake_minimum_required(VERSION 4.2)
project(UnicornialEngine)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

add_executable(UnicornialEngine src/main.cpp
        src/glad.h
        src/glad.c
        src/Utils.cpp
        src/Utils.h
)

target_link_libraries(UnicornialEngine glfw)
