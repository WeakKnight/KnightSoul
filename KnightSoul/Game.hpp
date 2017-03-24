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
#include "Object.hpp"
#include "Surface.hpp"

class SpriteRenderer;
class Context;
class Room;

class Game: public Object
{
public:
    SpriteRenderer* SpriteRendererInstance;
    Game(Context* context);
    ~Game();
    void Init();
    void InitSpriteRenderer();
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Destoroy(GLfloat dt);
    void Render();
    Room* ActiveRoom;
    Surface* GameSurface;
};

#endif /* Game_hpp */
