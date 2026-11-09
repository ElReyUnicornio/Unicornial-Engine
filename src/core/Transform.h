//
// Created by tto415 on 11/1/26.
//

#ifndef UNICORNIALENGINE_TRANSFORM_H
#define UNICORNIALENGINE_TRANSFORM_H
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <utility>

#include "GameObject.h"

#endif //UNICORNIALENGINE_TRANSFORM_H

class Transform {
private:
    GameObject *parent;
public:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 _scale;

    Transform(GameObject *parent) {
        this->parent = std::move(parent);
        this->_scale = glm::vec3(1.0f, 1.0f, 1.0f);
        this->rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    }

    void translate(const glm::vec3& vector) {
        this->position += vector;
    }

    void rotate(const glm::vec3& vector) {
        this->rotation += vector;
    }

    void scale(const glm::vec3& vector) {
        this->_scale = vector;
    }

    glm::mat4 calculate() {
        glm::mat4 transform = glm::mat4();
        transform = glm::translate(transform, this->position);
        transform = glm::rotate(transform, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(this->rotation.y), glm::vec3(0.0f, 0.0f, 1.0f));
        transform = glm::rotate(transform, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 0.0f));
        transform = glm::scale(transform, this->_scale);
        return transform;
    }
};