cmake_minimum_required(VERSION 4.2)
project(UnicornialEngine)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

add_executable(UnicornialEngine src/main.cpp
        external/glad/glad.h
        external/glad/glad.c
        external/stb/stb_image.h
        src/Utils.cpp
        src/Utils.h
        src/Shader.cpp
        src/Shader.h
)

target_link_libraries(UnicornialEngine glfw)
target_link_libraries(UnicornialEngine glm)
