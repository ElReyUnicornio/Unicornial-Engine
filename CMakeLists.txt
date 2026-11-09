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
        src/core/Shader.cpp
        src/core/Shader.h
        src/core/GameObject.cpp
        src/core/GameObject.h
        src/core/Script.h
        src/core/Transform.h
        src/core/Engine.cpp
        src/core/Engine.h
        src/core/Scene.cpp
        src/core/Scene.h
)

target_link_libraries(UnicornialEngine glfw)
target_link_libraries(UnicornialEngine glm)
