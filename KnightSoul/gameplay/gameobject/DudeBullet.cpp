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
Entity(context)
{
}

void DudeBullet::Init()
{
    GameObject::Init();
    SpritePointer = ResourceManager::Sprites["bullet"];
    SpritePointer->ImageIndex = 0;
    Image_XScale = 1;
    Image_YScale = 1;
    SetGameplayTag("Bullet");
    CollisionCom->SetGameplayTagTarget("None");
}

void DudeBullet::Update(float dt)
{
    GameObject::Update(dt);
    //X+=5;
}

void DudeBullet::Draw()
{
    GameObject::Draw();
}
