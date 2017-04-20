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
#include "CollisionComponent.hpp"
#include "Sprite.hpp"
#include "SpriteSheet.hpp"
#include "Math.hpp"

Skeleton::Skeleton(Context* context)
:
GameObject(context)
{
}

void Skeleton::Init()
{
    GameObject::Init();
    SpritePointer = ResourceManager::Sprites["dudeIdle"];
    CollisionCom->Width = 32;
    CollisionCom->Height = 32;
}

void Skeleton::Update(float dt)
{
    GameObject::Update(dt);
    //auto view = EngineContext->GameInstance->ActiveRoom->ActiveView;
    auto spriteIdle = ResourceManager::Sprites["dudeIdle"];
    auto spriteRun = ResourceManager::Sprites["dudeRun"];
    auto spriteRoll = ResourceManager::Sprites["skeleton_roll"];
    if(Input::KeyboardPressed(SDL_SCANCODE_LEFT))
    {
        SpeedX = -3.0f;
        Image_XScale = -1;
        SpritePointer = spriteRun;
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        SpeedX = 3.0f;
        Image_XScale = 1;
        SpritePointer = spriteRun;
    }
    if(!Input::KeyboardPressed(SDL_SCANCODE_LEFT) && !Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        SpeedX = 0.0f;
        SpritePointer = spriteIdle;
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_DOWN))
    {
        SpritePointer = spriteRoll;
    }
    if(CollisionCom->PlaceMeeting(0, 1))
    {
        SpeedY = 0.0f;
    }
    else
    {
        SpeedY += 0.75;
    }
    //view->Boundary.Origin = glm::vec2(X - 300, Y - 200);
    DoMove();
}

void Skeleton::DoMove()
{
    int xValue = floorf(std::abs(SpeedX));
    int yValue = floorf(std::abs(SpeedY));
    
    for(int x = 0; x < xValue; x++)
    {
        if(!CollisionCom->PlaceMeeting(1 * Math::sign(SpeedX), 0))
        {
            X += Math::sign(SpeedX);
        }
    }
    
    for(int y = 0; y < yValue; y++)
    {
        if(!CollisionCom->PlaceMeeting(0,1 * Math::sign(SpeedY)))
        {
            Y += Math::sign(SpeedY);
        }
    }
}
