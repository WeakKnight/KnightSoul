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
#include "Entity.hpp"

class Context;

class DudeBullet : public Entity
{
public:
    DudeBullet(Context* context);
    virtual void Init() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
};


#endif /* DudeBullet_hpp */
