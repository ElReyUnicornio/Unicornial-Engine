//
// Created by tto415 on 11/8/26.
//

#ifndef UNICORNIALENGINE_ENGINE_H
#define UNICORNIALENGINE_ENGINE_H
#include <vector>
#include <string>
#include <GLFW/glfw3.h>

class Scene;
class GameObject;

GLFWwindow *window;
inline float deltaTime;

class Engine {
private:
    std::string name;
    Scene *scene;
    std::vector<GameObject*> objects;
    void buildScene();
    public:
    Engine(Scene *scene, const std::string &name);
    void init();
    void update();
    //void render();
    //void fixedUpdate();
    //void loadScene(const std::string &filename);
    void setScene(Scene *scene);
    void close();
};


#endif //UNICORNIALENGINE_ENGINE_H
