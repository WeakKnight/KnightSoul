//
//  Room.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/20.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Room.hpp"
#include "Context.hpp"

Room::Room(Context* context)
:
Object(context)
{
}

Room* Room::Create(Context* context)
{
    auto room = new Room(context);
    return room;
}

void Room::AddInstance(GameObject* object)
{
    InstanceList.push_back(object);
}
