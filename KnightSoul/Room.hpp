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

class GameObject;

class InstanceInfo
{
    int X;
    int Y;
    float Rotation;
    float Image_XScale;
    float Image_YScale;
    std::string ObjectName;
};

class Room
{
    static Room* Create();
    std::list<InstanceInfo> InstanceList;
};

#endif /* Room_hpp */
