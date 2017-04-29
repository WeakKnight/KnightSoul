//
//  Entity.cpp
//  KnightSoul
//
//  Created by Knight on 2017/4/29.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Entity.hpp"
#include "CollisionComponent.hpp"
#include "Math.hpp"

Entity::Entity(Context* context)
:
GameObject(context)
{
    
}

void Entity::DoMove()
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

void Entity::EndUpdate(float dt)
{
    GameObject::EndUpdate(dt);
    DoMove();
}
