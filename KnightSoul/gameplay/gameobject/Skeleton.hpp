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
    void Init() override;
    void Update(float dt) override;
    float SpeedX = 0;
    float SpeedY = 0;
    void DoMove();
};

#endif /* Skeleton_hpp */
