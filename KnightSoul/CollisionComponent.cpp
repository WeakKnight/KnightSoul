//
//  CollisionComponent.cpp
//  KnightSoul
//
//  Created by Knight on 2017/4/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "CollisionComponent.hpp"
#include "GameObject.hpp"

static std::vector<CollisionComponent*> CollisionComPool = {};

unsigned int CollisionComponent::GlobalComID = 1;

CollisionComponent::CollisionComponent(GameObject* parent)
{
    CollisionComPool.push_back(this);
    Parent = parent;
    ID = GlobalComID++;
}

CollisionComponent::~CollisionComponent()
{
    for(auto itr = CollisionComPool.begin(); itr!= CollisionComPool.end(); itr++)
    {
        if ((*itr)->ID == ID)
        {
            CollisionComPool.erase(itr);
            return;
        }
    }
}

std::vector<CollisionComponent*> CollisionComponent::CheckCollision()
{
    return {};
}




