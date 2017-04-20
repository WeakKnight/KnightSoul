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
class GameObject;
class Context;
class CollisionComponent:public Object {
public:
    static unsigned int GlobalComID;
    CollisionComponent(Context* context, GameObject* parent);
    ~CollisionComponent();
    bool PlaceMeeting(int x, int y);
private:
    GameObject* Parent = nullptr;
    int ID = 0;
    int OffsetX = 0;
    int OffsetY = 0;
    int Width = 0;
    int Height = 0;
};

#endif /* CollisionComponent_hpp */
