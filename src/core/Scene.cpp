//
// Created by tto415 on 11/8/26.
//

#include "Scene.h"

Node::Node(const std::string &name, Node *parent, std::unique_ptr<GameObject> object) {
    this->name = name;
    this->object = std::move(object);
    this->parent = parent;
}

std::string Node::getName() const {
    return this->name;
}

GameObject *Node::getObject() const {
    return this->object.get();
}

std::vector<std::unique_ptr<Node>>& Node::getChildren() {
    return this->children;
}

void Node::setObject(std::unique_ptr<GameObject> object) {
    this->object = std::move(object);
}

void Node::setName(const std::string &name) {
    this->name = name;
}

void Node::addChild(std::unique_ptr<Node> child) {
    child->setParent(this);
    this->children.push_back(std::move(child));
}

void Node::removeAllChildren() {
    for (auto& node : this->children) {
        node->destroy();
    }
    children.clear();
}

void Node::removeChild(const std::string &name) {
    for (auto node = this->children.begin(); node != this->children.end(); ++node) {
        if (node->get()->getName() == name) {
            children.erase(node);
        }
    }
}

void Node::removeChild(std::unique_ptr<Node> child) {
    removeChild(child->getName());
}

void Node::setParent(Node *parent) {
    this->parent = parent;
}

void Node::removeParent() {
    this->parent = nullptr;
}

void Node::destroy() {
    if (this->parent != nullptr) {
        this->parent->removeChild(this->getName());
    }
}
