//
//  Math.cpp
//  KnightSoul
//
//  Created by Knight on 2017/4/20.
//  Copyright © 2017年 Knight. All rights reserved.
//
#include "Math.hpp"
#include <stdio.h>

namespace Math
{    
    int irandom(int min, int max)
    {
        return min + (rand() % (int)(max - min + 1));
    }
}
