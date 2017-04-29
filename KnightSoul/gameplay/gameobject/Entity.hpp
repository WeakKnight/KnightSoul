//
//  Entity.hpp
//  KnightSoul
//
//  Created by Knight on 2017/4/29.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Context;

class Entity : public GameObject
{
public:
    Entity(Context* context);
    float SpeedX = 0;
    float SpeedY = 0;
    virtual void DoMove();
    virtual void EndUpdate(float dt) override;
};



#endif /* Entity_hpp */
