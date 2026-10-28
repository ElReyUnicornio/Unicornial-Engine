#define STB_IMAGE_IMPLEMENTATION
#include <cmath>
#include <iostream>
#include "Utils.h"
#include "Shader.h"
#include "../external/stb/stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

float vertices[] = {
    // Cara trasera: rojo
    // Bottom-left, bottom-right, top-right, top-left
    -0.5f, -0.5f, -0.5f,  1, 0, 0,  0, 0,
     0.5f, -0.5f, -0.5f,  1, 0, 0,  1, 0,
     0.5f,  0.5f, -0.5f,  1, 0, 0,  1, 1,
    -0.5f,  0.5f, -0.5f,  1, 0, 0,  0, 1,

    // Cara frontal: verde
    -0.5f, -0.5f,  0.5f,  0, 1, 0,  0, 0,
     0.5f, -0.5f,  0.5f,  0, 1, 0,  1, 0,
     0.5f,  0.5f,  0.5f,  0, 1, 0,  1, 1,
    -0.5f,  0.5f,  0.5f,  0, 1, 0,  0, 1,

    // Cara izquierda: azul
    -0.5f, -0.5f,  0.5f,  0, 0, 1,  0, 0,
    -0.5f, -0.5f, -0.5f,  0, 0, 1,  1, 0,
    -0.5f,  0.5f, -0.5f,  0, 0, 1,  1, 1,
    -0.5f,  0.5f,  0.5f,  0, 0, 1,  0, 1,

    // Cara derecha: amarillo
     0.5f, -0.5f, -0.5f,  1, 1, 0,  0, 0,
     0.5f, -0.5f,  0.5f,  1, 1, 0,  1, 0,
     0.5f,  0.5f,  0.5f,  1, 1, 0,  1, 1,
     0.5f,  0.5f, -0.5f,  1, 1, 0,  0, 1,

    // Cara inferior: magenta
    -0.5f, -0.5f, -0.5f,  1, 0, 1,  0, 0,
     0.5f, -0.5f, -0.5f,  1, 0, 1,  1, 0,
     0.5f, -0.5f,  0.5f,  1, 0, 1,  1, 1,
    -0.5f, -0.5f,  0.5f,  1, 0, 1,  0, 1,

    // Cara superior: cian
    -0.5f,  0.5f,  0.5f,  0, 1, 1,  0, 0,
     0.5f,  0.5f,  0.5f,  0, 1, 1,  1, 0,
     0.5f,  0.5f, -0.5f,  0, 1, 1,  1, 1,
    -0.5f,  0.5f, -0.5f,  0, 1, 1,  0, 1
};

unsigned int indices[] = {
    // Trasera
    0,  1,  2,   2,  3,  0,
   // Frontal
    4,  5,  6,   6,  7,  4,
   // Izquierda
    8,  9, 10,  10, 11,  8,
   // Derecha
   12, 13, 14,  14, 15, 12,
   // Inferior
   16, 17, 18,  18, 19, 16,
   // Superior
   20, 21, 22,  22, 23, 20
};

const glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f, 0.0f, 0.0f),
    glm::vec3( 2.0f, 5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3( 2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f, 3.0f, -7.5f),
    glm::vec3( 1.3f, -2.0f, -2.5f),
    glm::vec3( 1.5f, 2.0f, -2.5f),
    glm::vec3( 1.5f, 0.2f, -1.5f),
    glm::vec3(-1.3f, 1.0f, -1.5f)
    };

int main() {
    //create window
    GLFWwindow* window;

    if (!glfwInit()) {
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(600, 600, "Unicornial Engine", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create window";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //setup glad
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize glad \n";
        return  -1;
    }
    glViewport(0, 0, 600, 600);

    //events
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //texture
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on currently bound texture)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *image = stbi_load("/home/tto415/Documents/gh/Unicornial-Engine/src/assets/pp_3.0.png", &width, &height, &nrChannels, 0);
    stbi__vertical_flip(image, width, height, nrChannels);


    if (image) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(image);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }

    //triangle
    Shader vertexGradientShader("/home/tto415/Documents/gh/Unicornial-Engine/src/vertex.vs", "/home/tto415/Documents/gh/Unicornial-Engine/src/fragment.fs");

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    for(unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle),
        glm::vec3(1.0f, 0.3f, 0.5f));
        vertexGradientShader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //3D
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    //render loop

    while (!glfwWindowShouldClose(window)) {
        //events
        processInput(window);

        //rendering
        glEnable(GL_DEPTH_TEST);
        vertexGradientShader.use();
        vertexGradientShader.setMat4("model", model);
        vertexGradientShader.setMat4("view", view);
        vertexGradientShader.setMat4("projection", projection);

        glClearColor(0.3f, 0.1f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(VAO);

        glBindVertexArray(VAO);

        for(unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle),
            glm::vec3(1.0f, 0.3f, 0.5f));
            vertexGradientShader.setMat4("model", model);
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*) 0);
        }

        // check and call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //de-allocate all resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
