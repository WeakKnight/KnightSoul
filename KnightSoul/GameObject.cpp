//
//  GameObject.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/16.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Input.hpp"
#include "ResourceManager.hpp"

std::vector<GameObject*> GameObject::GameObjectList;

GameObject* GameObject::Create()
{
    auto gameObject = new GameObject();
    GameObjectList.push_back(gameObject);
    return gameObject;
}

GameObject::GameObject()
{
    
}

void GameObject::Init()
{
    
}

void GameObject::Update(float dt)
{
    auto spriteIdle = ResourceManager::Sprites["skeleton_idle"];
    auto spriteRun = ResourceManager::Sprites["skeleton_run"];
    if(SpritePointer)
    {
        SpritePointer->Update(dt);
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_LEFT))
    {
        X -= 3;
        SpritePointer = spriteRun;
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        X += 3;
        SpritePointer = spriteRun;
    }
    if(!Input::KeyboardPressed(SDL_SCANCODE_LEFT) && !Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        SpritePointer = spriteIdle;
    }
}
