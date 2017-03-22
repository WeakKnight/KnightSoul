//
//  Game.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/14.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <OpenGL/gl3.h>

class SpriteRenderer;

class Game
{
public:
    static SpriteRenderer* SpriteRendererInstance;
    GLuint Width,Height;
    Game(GLuint width,GLuint height);
    ~Game();
    void Init();
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
};

#endif /* Game_hpp */
