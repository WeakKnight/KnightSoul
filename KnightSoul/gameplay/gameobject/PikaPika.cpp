//
//  PikaPika.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/24.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "PikaPika.hpp"
#include "Context.hpp"
#include "ResourceManager.hpp"
#include "CollisionComponent.hpp"
#include "Sprite.hpp"
#include "Math.hpp"

PikaPika::PikaPika(Context* context)
:
GameObject(context)
{
}

void PikaPika::Init()
{
    GameObject::Init();
    CollisionCom->Width = 48;
    CollisionCom->Height = 48;
    CollisionCom->OffsetY = 0;
    SpritePointer = ResourceManager::Sprites["block"];
    int testRand = rand()%2;
    int number = testRand;
    SpritePointer->ImageIndex = number;
}

void PikaPika::Update(float dt)
{
    GameObject::Update(dt);
}

