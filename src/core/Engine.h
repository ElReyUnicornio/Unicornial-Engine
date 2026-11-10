//
// Created by tto415 on 11/8/26.
//

#ifndef UNICORNIALENGINE_ENGINE_H
#define UNICORNIALENGINE_ENGINE_H
#include <vector>
#include <string>

class Scene;
class GameObject;
inline float deltaTime;

class Engine {
private:
    Scene *scene;
    std::vector<GameObject*> objects;
    public:
    Engine();
    void init();
    void update();
    void render();
    void fixedUpdate();
    void loadScene(const std::string &filename);
    void setScene(Scene *scene);
};


#endif //UNICORNIALENGINE_ENGINE_H
