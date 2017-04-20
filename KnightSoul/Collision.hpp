//
//  Collision.hpp
//  KnightSoul
//
//  Created by Knight on 2017/4/20.
//  Copyright © 2017年 Knight. All rights reserved.
//

namespace Collision
{
bool RectIntersectRect(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
{
    if(X1 > X4 || X3 > X2 || Y1 > Y4 || Y3 > Y2)
    {
        return false;
    }
    return true;
}
}


