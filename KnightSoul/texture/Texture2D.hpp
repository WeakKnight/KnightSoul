//
//  Texture2D.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/14.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Texture2D_hpp
#define Texture2D_hpp

#include <stdio.h>
#include <OpenGL/gl3.h>

class Texture2D
{
public:
    GLuint ID;
    GLuint Width, Height;
    GLuint Internal_Format;
    GLuint Image_Format;
    GLuint Wrap_S;
    GLuint Wrap_T;
    GLuint Filter_Min;
    GLuint Filter_Max;
    Texture2D();
    void Generate(GLuint width, GLuint height, unsigned char* data);
    void Bind() const;
};

#endif /* Texture2D_hpp */
