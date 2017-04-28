//
//  Skeleton.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/23.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Skeleton_hpp
#define Skeleton_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Context;

class Skeleton : public GameObject
{
public:
    Skeleton(Context* context);
    virtual void Init() override;
    virtual void AlarmEvent(int alarmId) override;
    virtual void Update(float dt) override;
    float SpeedX = 0;
    float SpeedY = 0;
    bool onGround = false;
    bool isAttack = false;
    void DoMove();
    Tag GameplayTag = {"Player"};
};

#endif /* Skeleton_hpp */
