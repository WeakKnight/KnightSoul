//
//  View.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/23.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include "Rect.hpp"

class View
{
public:
    View(Rect boundary)
    {
        Boundary = boundary;
    }
    
    Rect Boundary;
};

#endif /* View_hpp */
