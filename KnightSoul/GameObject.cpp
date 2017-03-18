//
//  GameObject.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/16.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "GameObject.hpp"

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
    
}
