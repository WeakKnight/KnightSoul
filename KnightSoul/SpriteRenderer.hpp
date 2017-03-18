//
//  SpriteRenderer.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/16.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef SpriteRenderer_hpp
#define SpriteRenderer_hpp

#include <stdio.h>
#include <OpenGL/gl3.h>
#include "Shader.hpp"
#include "Texture2D.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class SpriteRenderer
{
public:
    SpriteRenderer(Shader &shader);
    ~SpriteRenderer();
    
    void DrawSprite(Texture2D &texture,
                    glm::vec2 position,
                    glm::vec2 size = glm::vec2(10, 10),
                    GLfloat rotate = 0.0f,
                    glm::vec3 color = glm::vec3(1.0f),
                    glm::vec4 spriteFrame = glm::vec4(0.0f, 0.0f,1.0f,1.0f));
private:
    Shader shader;
    GLuint quadVAO;
    
    void initRenderData();
};

#endif /* SpriteRenderer_hpp */
