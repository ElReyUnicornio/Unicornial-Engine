//
// Created by tto415 on 1/17/26.
//

#ifndef UNICORNIALENGINE_UTILS_H
#define UNICORNIALENGINE_UTILS_H
#include "glad.h"
#include <GLFW/glfw3.h>

inline bool debug = false;
inline bool debugPressed = false;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

void toggleDebug();

#endif //UNICORNIALENGINE_UTILS_H