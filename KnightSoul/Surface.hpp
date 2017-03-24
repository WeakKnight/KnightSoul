//
//  Surface.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/24.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Surface_hpp
#define Surface_hpp

#include <stdio.h>
#include <OpenGL/gl3.h>
#include "Texture2D.hpp"

class Surface
{
public:
    Surface(GLuint width, GLuint height);
    GLuint Width;
    GLuint Height;
    GLuint ID;
    Texture2D Texture;
    static void SetTarget(Surface* surface);
    static void ResetTarget();
};

#endif /* Surface_hpp */
