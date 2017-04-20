//
//  Math.hpp
//  KnightSoul
//
//  Created by Knight on 2017/4/20.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include <stdlib.h>

namespace Math
{
    template <typename T> int sign(T val)
    {
        return (T(0) < val) - (val < T(0));
    }
    
    int irandom(int min, int max);
}

