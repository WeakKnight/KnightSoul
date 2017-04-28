//
//  CollisionComponent.hpp
//  KnightSoul
//
//  Created by Knight on 2017/4/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef CollisionComponent_hpp
#define CollisionComponent_hpp

#include <stdio.h>
#include <vector>
#include "Object.hpp"
#include "Tag.hpp"

class GameObject;
class Context;

enum class CollisionType : char
{
    CheckAll = 1,
    CheckByGameplayTag = 2,
    CheckByInstance = 3
};

class CollisionComponent:public Object {
public:
    static unsigned int GlobalComID;
    CollisionComponent(Context* context, GameObject* parent);
    ~CollisionComponent();
    bool PlaceMeeting(float x, float y);
    float OffsetX = 0;
    float OffsetY = 0;
    float Width = 0;
    float Height = 0;
    void SetGameplayTagTarget(const char* tagText);
private:
    CollisionType Type = CollisionType::CheckAll;
    GameObject* Parent = nullptr;
    unsigned int ID = 0;
    Tag TagTarget = {""};
};

#endif /* CollisionComponent_hpp */
