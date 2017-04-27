//
//  DudeBullet.hpp
//  KnightSoul
//
//  Created by Knight on 2017/4/27.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef DudeBullet_hpp
#define DudeBullet_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Context;

class DudeBullet : public GameObject
{
public:
    DudeBullet(Context* context);
    void Init() override;
    void Update(float dt) override;
};


#endif /* DudeBullet_hpp */
