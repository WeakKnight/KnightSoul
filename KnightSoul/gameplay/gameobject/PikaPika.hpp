//
//  PikaPika.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/24.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef PikaPika_hpp
#define PikaPika_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Context;

class PikaPika : public GameObject
{
public:
    PikaPika(Context* context);
    void Init() override;
    void Update(float dt) override;
    Tag GameplayTag = Tag("Block");
};

#endif /* PikaPika_hpp */
