//
// Created by tto415 on 11/1/26.
//

#include "GameObject.h"
#include "Transform.h"
#include "Script.h"
#include "Scene.h"

GameObject::GameObject(Node *node) {
    transform = new Transform(this);
    this->node = node;
};

void GameObject::start() {
    for (auto& script : scripts) {
        script->start();
    }
}

void GameObject::update() {
    for (auto & script : scripts) {
        script->update();
    }
}

Node* GameObject::getNode() {
    return this->node;
}

void GameObject::destroy() {
    this->node->destroy();
}
