//
// Created by tto415 on 11/1/26.
//

#ifndef UNICORNIALENGINE_SCRIPT_H
#define UNICORNIALENGINE_SCRIPT_H
#include "GameObject.h"

class Script {
private:
    GameObject *gameObject;
    public:
    Script(GameObject *gameObject) {
        this->gameObject = gameObject;
    }
    void start();
    void update();
};

#endif //UNICORNIALENGINE_SCRIPT_H
