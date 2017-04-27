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
#include "DudeBullet.hpp"

Skeleton::Skeleton(Context* context)
:
GameObject(context)
{
}

void Skeleton::Init()
{
    GameObject::Init();
    SpritePointer = ResourceManager::Sprites["dudeIdle"];
    CollisionCom->Width = 20;
    CollisionCom->Height = 24;
    CollisionCom->OffsetX = -10;
    CollisionCom->OffsetY = 3;
}

void Skeleton::AlarmEvent(int alarmId)
{
    GameObject::AlarmEvent(alarmId);
    if(alarmId == 0)
    {
        isAttack = false;
    }
}

void Skeleton::Update(float dt)
{
    GameObject::Update(dt);
    //auto view = EngineContext->GameInstance->ActiveRoom->ActiveView;
    auto spriteIdle = ResourceManager::Sprites["dudeIdle"];
    auto spriteRun = ResourceManager::Sprites["dudeRun"];
    auto spriteJump = ResourceManager::Sprites["dudeJump"];
    auto spriteIdleAttack = ResourceManager::Sprites["dudeIdleAttack"];
    auto spriteRunAttack = ResourceManager::Sprites["dudeRunAttack"];
    auto spriteJumpAttack = ResourceManager::Sprites["dudeJumpAttack"];
    if(CollisionCom->PlaceMeeting(0, 1))
    {
        onGround = true;
        SpeedY = 0.0f;
    }
    else
    {
        onGround = false;
        SpeedY += 0.25;
    }
    
    if(Input::KeyboardPressed(SDL_SCANCODE_SPACE))
    {
        if(!isAttack)
        {
            isAttack = true;
            Alarm[0] = 30;
            auto bullet = new DudeBullet(EngineContext);
            bullet->X = X;
            bullet->Y = Y;
            EngineContext->GameInstance->ActiveRoom->AddInstance(bullet);
        }
        if(Alarm[0] < 5)
        {
            Alarm[0] = 30;
            //make bullet
            auto bullet = new DudeBullet(EngineContext);
            bullet->X = X;
            bullet->Y = Y;
            EngineContext->GameInstance->ActiveRoom->AddInstance(bullet);
        }
    }
    
    if(Input::KeyboardPressed(SDL_SCANCODE_LEFT))
    {
        SpeedX = -3.0f;
        Image_XScale = -1;
        SpritePointer = spriteRun;
        if(isAttack)
        {
            SpritePointer = spriteRunAttack;
        }
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        SpeedX = 3.0f;
        Image_XScale = 1;
        SpritePointer = spriteRun;
        if(isAttack)
        {
            SpritePointer = spriteRunAttack;
        }
    }
    if(!Input::KeyboardPressed(SDL_SCANCODE_LEFT) && !Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        SpeedX = 0.0f;
        SpritePointer = spriteIdle;
        if(isAttack)
        {
            SpritePointer = spriteIdleAttack;
        }
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_UP) && onGround)
    {
        SpeedY = -6.0f;
    }
    if(!onGround)
    {
        SpritePointer = spriteJump;
        if(isAttack)
        {
            SpritePointer = spriteJumpAttack;
        }
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
