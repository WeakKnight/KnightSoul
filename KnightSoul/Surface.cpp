//
//  Surface.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/24.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Surface.hpp"

Surface::Surface(GLuint width, GLuint height)
:
ID(0)
{
    glGenFramebuffers(1, &ID);
    Texture.Generate(width, height, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, ID);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, Texture.ID, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Surface::SetTarget(Surface* surface)
{
    glBindFramebuffer(GL_FRAMEBUFFER, surface->ID);
}

void Surface::ResetTarget()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
