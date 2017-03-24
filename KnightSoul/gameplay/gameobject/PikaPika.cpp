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

PikaPika::PikaPika(Context* context)
:
GameObject(context)
{
}

void PikaPika::Init()
{
    GameObject::Init();
    SpritePointer = ResourceManager::Sprites["skeleton_idle"];
}

void PikaPika::Update(float dt)
{
    GameObject::Update(dt);
}

