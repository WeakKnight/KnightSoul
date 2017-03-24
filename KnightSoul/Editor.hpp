//
//  Editor.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/23.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Editor_hpp
#define Editor_hpp

#include <stdio.h>
#include "SDL.h"
#include <OpenGL/gl3.h>
#include "Object.hpp"

class Context;

class Editor : public Object
{
public:
    Editor(Context* context,GLuint width, GLuint height);
    GLuint Width;
    GLuint Height;
    void Init(SDL_Window* window);
    void Update(float dt);
    void Render();
private:
    SDL_Window* Window;
};

#endif /* Editor_hpp */
