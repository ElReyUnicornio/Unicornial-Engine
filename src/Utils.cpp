//
// Created by tto415 on 1/17/26.
//

#include "./Utils.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

}

void toggleDebug() {
    debugPressed = true;
    if (debug) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    debug = !debug;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && !debugPressed)
        toggleDebug();
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
        debugPressed = false;
}



