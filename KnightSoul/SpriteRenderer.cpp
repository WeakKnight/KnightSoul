//
//  SpriteRenderer.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/16.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "SpriteRenderer.hpp"
#include "Sprite.hpp"
#include "ResourceManager.hpp"
#include "glm.hpp"

SpriteRenderer::SpriteRenderer(Shader &shader)
{
    this->shader = shader;
    this->initRenderData();
}

SpriteRenderer::~SpriteRenderer()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}

void SpriteRenderer::initRenderData()
{
    // Configure VAO/VBO
    GLuint VBO;
    GLfloat vertices[] = {
        // Pos      // Tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };
    
    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SpriteRenderer::DrawSprite(Texture2D &texture,
                                glm::vec2 position,
                                glm::vec2 size,
                                GLfloat rotate,
                                glm::vec3 color,
                                glm::vec4 spriteFrame)
{
    int facingX = 1;
    if(size.x < 0)
    {
        facingX = -1;
    }
    size.x = fabsf(size.x);
    
    this->shader.Use();
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));
    
    this->shader.SetMatrix4("model", model);
    this->shader.SetVector3f("spriteColor", color);
    this->shader.SetVector4f("spriteFrame", spriteFrame);
    this->shader.SetInteger("facing", facingX);
    
    glActiveTexture(GL_TEXTURE0);
    texture.Bind();
    
    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::DrawSprite(Sprite* sprite, glm::vec2 position, glm::vec2 scale, GLfloat rotate, glm::vec3 color)
{
    int imageIndex = (int)(sprite->ImageIndex);
    std::string imageName = sprite->SpriteFrames[imageIndex];
    auto spriteFrame = sprite->SpriteSheetGroup->Frames[imageName];
    auto texture = ResourceManager::Textures[sprite->SpriteSheetGroup->Texture_Index];
    auto spriteWidth = scale.x * spriteFrame->W;
    auto spriteHeight = scale.y * spriteFrame->H;
    auto pivotX = sprite->pivotX;
    auto pivotY = sprite->pivotY;
    auto finalX = position.x - pivotX * spriteWidth;
    if(scale.x < 0)
    {
        finalX = position.x + (spriteWidth - pivotX * spriteWidth);
    }
    DrawSprite(texture,
               glm::vec2(finalX, position.y - pivotY * spriteHeight),
               glm::vec2(spriteWidth, spriteHeight),
               rotate,
               color,
               glm::vec4((float)(spriteFrame->X)/(float)(texture.Width), (float)(spriteFrame->Y)/(float)(texture.Height), (float)(spriteFrame->W)/(float)(texture.Width), (float)(spriteFrame->H)/(float)(texture.Height)));
}
