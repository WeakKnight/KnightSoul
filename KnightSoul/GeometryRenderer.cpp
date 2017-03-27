//
//  GeometryRenderer.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/24.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "GeometryRenderer.hpp"
#include <OpenGL/gl3.h>

GeometryRenderer::GeometryRenderer()
{
}

GeometryRenderer::~GeometryRenderer()
{
}

void GeometryRenderer::DrawRectangle(glm::vec2 origin, glm::vec2 size)
{
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
    glDrawArrays;
    glDrawElements;
    glDrawBuffer;
}
