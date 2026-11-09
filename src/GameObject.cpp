//
// Created by tto415 on 11/1/26.
//

#include "GameObject.h"
#include "components/Transform.h"
#include "components/Script.h"

GameObject::GameObject() {
    transform = new Transform(this);
};

void GameObject::start() {
    for (auto &script : scripts) {
        script.start();
    }
}

void GameObject::update() {
    for (auto & script : scripts) {
        script.update();
    }
}