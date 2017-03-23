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

class Editor
{
public:
    Editor(GLuint width, GLuint height);
    GLuint Width;
    GLuint Height;
    void Init(SDL_Window* window);
    void Update(float dt);
    void Render();
    void SetGameView(GLuint textureID);
private:
    GLuint GameTextureID;
    SDL_Window* Window;
};

#endif /* Editor_hpp */
