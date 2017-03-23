//
//  Object.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/23.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>

class Context;

class Object
{
public:
    Object(Context* context);
    Context* EngineContext;
};

#endif /* Object_hpp */
