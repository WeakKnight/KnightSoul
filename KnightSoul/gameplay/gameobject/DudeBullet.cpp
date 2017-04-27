//
//  DudeBullet.cpp
//  KnightSoul
//
//  Created by Knight on 2017/4/27.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "DudeBullet.hpp"
#include "Context.hpp"
#include "ResourceManager.hpp"
#include "CollisionComponent.hpp"
#include "Sprite.hpp"
#include "Math.hpp"

DudeBullet::DudeBullet(Context* context)
:
GameObject(context)
{
}

void DudeBullet::Init()
{
    GameObject::Init();
    CollisionCom->Width = 48;
    CollisionCom->Height = 48;
    CollisionCom->OffsetY = 0;
    SpritePointer = ResourceManager::Sprites["block"];
    SpritePointer->ImageIndex = 0;
}

void DudeBullet::Update(float dt)
{
    GameObject::Update(dt);
}

