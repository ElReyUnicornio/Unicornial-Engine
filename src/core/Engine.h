//
// Created by tto415 on 11/8/26.
//

#ifndef UNICORNIALENGINE_ENGINE_H
#define UNICORNIALENGINE_ENGINE_H

inline float deltaTime;

class Engine {
    public:
    Engine();
    void init();
    void update();
    void render();
    void fixedUpdate();
};


#endif //UNICORNIALENGINE_ENGINE_H
