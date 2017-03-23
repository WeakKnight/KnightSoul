//
//  Room.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/20.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>
#include <list>
#include <string>
#include "Object.hpp"

class GameObject;
class Context;

class Room : public Object
{
public:
    Room(Context* context);
    static Room* Create(Context* context);
    void AddInstance(GameObject* object);
    std::list<GameObject*> InstanceList;
};

#endif /* Room_hpp */
