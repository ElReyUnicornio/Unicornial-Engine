//
// Created by tto415 on 11/1/26.
//

#ifndef UNICORNIALENGINE_GAMEOBJECT_H
#define UNICORNIALENGINE_GAMEOBJECT_H
#include <glm/glm.hpp>
#include <vector>



class Transform;
class Script;

class GameObject {
private:
    std::vector<Script> scripts;
    Transform *transform{};
public:
    GameObject();
    void start();
    void update();
};

#endif //UNICORNIALENGINE_GAMEOBJECT_H