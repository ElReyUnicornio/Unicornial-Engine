//
// Created by tto415 on 11/8/26.
//

#ifndef UNICORNIALENGINE_SCENE_H
#define UNICORNIALENGINE_SCENE_H
#include <memory>

#include "GameObject.h"
#include <string>
#include "Engine.h"

class Node {
private:
    std::string name = "node";
    Node *parent = nullptr;
    std::unique_ptr<GameObject> object = nullptr;
    std::vector<std::unique_ptr<Node>> children;
public:
    Node(const std::string &name, Node *parent, GameObject *object);
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] GameObject *getObject() const;
    [[nodiscard]] std::vector<std::unique_ptr<Node>>& getChildren();
    void setObject(std::unique_ptr<GameObject> object);
    void setName(const std::string &name);
    void addChild(std::unique_ptr<Node> node);
    void removeChild(const std::string &name);
    void removeChild(std::unique_ptr<Node> node);
    void removeAllChildren();
    void setParent(Node *parent);
    void removeParent();
    void destroy();
};

class Scene {
    public:
    Node *tree;
    Scene();
    void loadFromFile(std::string filename);
    void bind(Engine *engine);
};


#endif //UNICORNIALENGINE_SCENE_H
