//
//  Skeleton.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/23.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Skeleton.hpp"
#include "Context.hpp"
#include "ResourceManager.hpp"
#include "Input.hpp"
#include "Room.hpp"
#include "View.hpp"
#include "Game.hpp"

Skeleton::Skeleton(Context* context)
:
GameObject(context)
{
}

void Skeleton::Init()
{
    GameObject::Init();
    SpritePointer = ResourceManager::Sprites["skeleton_idle"];
}

void Skeleton::Update(float dt)
{
    GameObject::Update(dt);
    //auto view = EngineContext->GameInstance->ActiveRoom->ActiveView;
    auto spriteIdle = ResourceManager::Sprites["skeleton_idle"];
    auto spriteRun = ResourceManager::Sprites["skeleton_run"];
    auto spriteRoll = ResourceManager::Sprites["skeleton_roll"];
    if(Input::KeyboardPressed(SDL_SCANCODE_LEFT))
    {
        X -= 3.0f;
        Image_XScale = -1;
        SpritePointer = spriteRun;
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        X += 3.0f;
        Image_XScale = 1;
        SpritePointer = spriteRun;
    }
    if(!Input::KeyboardPressed(SDL_SCANCODE_LEFT) && !Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        SpritePointer = spriteIdle;
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_DOWN))
    {
        SpritePointer = spriteRoll;
    }
    //view->Boundary.Origin = glm::vec2(X - 300, Y - 200);
}

