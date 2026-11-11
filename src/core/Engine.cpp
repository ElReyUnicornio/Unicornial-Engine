//
// Created by tto415 on 11/8/26.
//

#include "Engine.h"

#include "Scene.h"
#include "Logger.h"
#include "../Utils.h"
#include "../../external/glad/glad.h"


Engine::Engine(Scene *scene, const std::string &name) {
    this->scene = scene;
    this->name = name;
}

void Engine::init() {
    //Init window
    if (!glfwInit()) {
        Logger::error("FAILED TO INITIALIZE GLFW");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1920, 1080, name.c_str(), glfwGetPrimaryMonitor(), NULL);
    if (window == nullptr) {
        Logger::error("FAILED TO CREATE GLFW WINDOW");
        glfwTerminate();
        return;
    }

    //init glad
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        Logger::error("FAILED TO INITIALIZE GLAD");
    }
    glViewport(0, 0, 1920, 1080);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //build object vector
    if (this->scene == nullptr)
        Logger::warn("NO SCENE");
    else {
        buildScene();
    }

    for (auto& obj : objects) {
        if (obj->getScriptCount() == 0)
            continue;
        obj->start();
    }

    //start game loop
    this->update();
}

void Engine::update() {
    while (!glfwWindowShouldClose(window)) {
        //rebuild scene
        if (this->scene == nullptr)
            continue;
        if (this->scene->getDirty())
            this->buildScene();

        //run programs
        for (auto& obj : objects) {
            if (obj->getScriptCount() == 0)
                continue;
            obj->start();
        }

        //clear buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    this->close();
}

void Engine::buildScene() {
    if (this->scene == nullptr)
        return;

    this->scene->tree->traverse([&](Node *node) {
        if (node->getObject() != nullptr) {
            this->objects.push_back(node->getObject());
        }
    });

    this->scene->setDirty(false);
}

void Engine::setScene(Scene *scene) {
    this->scene = scene;
}

void Engine::close() {
    if (!glfwWindowShouldClose(window)) {
        glfwDestroyWindow(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
