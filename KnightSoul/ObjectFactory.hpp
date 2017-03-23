//
//  ObjectFactory.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/23.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef ObjectFactory_hpp
#define ObjectFactory_hpp

#include <stdio.h>
#include <string>
#include "Object.hpp"

class GameObject;
class Context;

class ObjectFactory : public Object
{
public:
    ObjectFactory(Context* context);
    GameObject* CreateInstanceByName(std::string name);
};

#endif /* ObjectFactory_hpp */
