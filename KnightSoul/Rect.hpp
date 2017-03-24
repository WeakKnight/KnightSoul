//
//  Rect.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/24.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Rect_hpp
#define Rect_hpp

#include <stdio.h>
#include "glm.hpp"

class Rect
{
public:
    
    Rect()
    {
        Origin = glm::vec2(0.0f, 0.0f);
        Size = glm::vec2(0.0f, 0.0f);
    }
    
    Rect(glm::vec2 origin,glm::vec2 size)
    {
        Origin = origin;
        Size = size;
    }
    
    Rect& operator=(const Rect& other) // copy assignment
    {
        if (this != &other)
        { // self-assignment check expected
            Origin = other.Origin;
            Size = other.Size;
        }
        return *this;
    }
    
    glm::vec2 Origin;
    glm::vec2 Size;
};

#endif /* Rect_hpp */
