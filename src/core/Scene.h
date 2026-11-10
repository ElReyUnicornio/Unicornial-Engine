//
// Created by tto415 on 11/8/26.
//

#ifndef UNICORNIALENGINE_SCENE_H
#define UNICORNIALENGINE_SCENE_H
#include <memory>

#include "GameObject.h"
#include "Script.h"
#include <string>
#include "Engine.h"

class Node {
private:
    std::string name = "node";
    Node *parent = nullptr;
    std::unique_ptr<GameObject> object;
    std::vector<std::unique_ptr<Node>> children;
public:
    Node(const std::string &name, Node *parent, std::unique_ptr<GameObject> object);
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

    template <typename F>
    void traverse(F&& func) {
        *func(this);
        for (auto& child : this->children) {
            child->traverse(func);
        }
    }

    template <typename P>
    Node* find(P&& pred) {
        if (pred(*this))
            return this;

        for (auto& child : this->children) {
            if (Node* found = child->find(pred))
                return found;
        }
        return nullptr;
    }
};

class Scene {
private:
    std::string name = "scene";
    bool dirty = true;
    public:
    Node *tree;
    Scene();
    void loadFromFile(std::string filename);
    Node* getNode(const std::string &name) const;
    bool getDirty();
    void setDirty(bool value);
};


#endif //UNICORNIALENGINE_SCENE_H
