//
//  CollisionComponent.cpp
//  KnightSoul
//
//  Created by Knight on 2017/4/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "CollisionComponent.hpp"
#include "GameObject.hpp"
#include "Context.hpp"

static std::vector<CollisionComponent*> CollisionComPool = {};

unsigned int CollisionComponent::GlobalComID = 1;

CollisionComponent::CollisionComponent(Context* context, GameObject* parent)
:Object(context)
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

bool CollisionComponent::PlaceMeeting(int x, int y)
{
    return false;
}


