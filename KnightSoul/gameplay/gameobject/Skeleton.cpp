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

Skeleton::Skeleton(Context* context)
:
GameObject(context)
{
}

void Skeleton::Init()
{
    GameObject::Init();
    X = 200.0f;
    Y = 200.0f;
    Image_XScale = 8.0;
    Image_YScale = 8.0;
    Rotation = 0.0f;
    SpritePointer = ResourceManager::Sprites["skeleton_idle"];

}

void Skeleton::Update(float dt)
{
    GameObject::Update(dt);
    auto spriteIdle = ResourceManager::Sprites["skeleton_idle"];
    auto spriteRun = ResourceManager::Sprites["skeleton_run"];
    if(Input::KeyboardPressed(SDL_SCANCODE_LEFT))
    {
        X -= 3.0f;
        SpritePointer = spriteRun;
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        X += 3.0f;
        SpritePointer = spriteRun;
    }
    if(!Input::KeyboardPressed(SDL_SCANCODE_LEFT) && !Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        SpritePointer = spriteIdle;
    }
}

