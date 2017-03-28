//
//  GeometryRenderer.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/24.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "GeometryRenderer.hpp"
#include <OpenGL/gl3.h>
#include "glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

GeometryRenderer::GeometryRenderer(Shader &shader)
{
    this->shader = shader;
    this->initRenderData();
}

GeometryRenderer::~GeometryRenderer()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}

void GeometryRenderer::initRenderData()
{
    // Configure VAO/VBO
    GLuint VBO;
    GLfloat vertices[] = {
        // Pos
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };
    
    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void GeometryRenderer::DrawRectangle(glm::vec2 origin, glm::vec2 size)
{
    this->shader.Use();
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(origin, 0.0f));
    
    //model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    //model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
    
    model = glm::scale(model, glm::vec3(size, 1.0f));
    
    this->shader.SetMatrix4("model", model);

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
