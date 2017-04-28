//
//  CollisionComponent.cpp
//  KnightSoul
//
//  Created by Knight on 2017/4/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "CollisionComponent.hpp"
#include "Collision.hpp"
#include "GameObject.hpp"
#include "Game.hpp"
#include "Context.hpp"
#include "Room.hpp"

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

bool CollisionComponent::PlaceMeeting(float x, float y)
{
    auto objList = this->EngineContext->GameInstance->ActiveRoom->InstanceList;
    for(auto itr = objList.begin(); itr != objList.end(); itr++)
    {
        auto obj = (*itr);
        if (obj->CollisionCom->ID == ID)
        {

        }
        else
        {
            if(Type == CollisionType::CheckByGameplayTag)
            {
                if(TagTarget == obj->GameplayTag)
                {
                    if(Collision::RectIntersectRect(Parent->X + OffsetX + x,
                                                    Parent->Y + OffsetY + y,
                                                    Parent->X + OffsetX + x + Width,
                                                    Parent->Y + OffsetY + y + Height,
                                                    obj->X + obj->CollisionCom->OffsetX,
                                                    obj->Y + obj->CollisionCom->OffsetY,
                                                    obj->X + obj->CollisionCom->OffsetX + obj->CollisionCom->Width,
                                                    obj->Y + obj->CollisionCom->OffsetY + obj->CollisionCom->Height
                                                    ))
                    {
                        return true;
                    }
                }
            }
            else
            {
                if(Collision::RectIntersectRect(Parent->X + OffsetX + x,
                                         Parent->Y + OffsetY + y,
                                         Parent->X + OffsetX + x + Width,
                                         Parent->Y + OffsetY + y + Height,
                                         obj->X + obj->CollisionCom->OffsetX,
                                         obj->Y + obj->CollisionCom->OffsetY,
                                         obj->X + obj->CollisionCom->OffsetX + obj->CollisionCom->Width,
                                         obj->Y + obj->CollisionCom->OffsetY + obj->CollisionCom->Height
                                         ))
                {
                    return true;
                }
            }
        }
        
    }
    return false;
}

void CollisionComponent::SetGameplayTagTarget(const char* tagText)
{
    Tag tag = {tagText};
    TagTarget = tag;
    Type = CollisionType::CheckByGameplayTag;
}
