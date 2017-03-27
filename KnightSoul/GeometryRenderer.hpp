//
//  GeometryRenderer.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/24.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef GeometryRenderer_hpp
#define GeometryRenderer_hpp

#include <stdio.h>
#include "glm.hpp"

class GeometryRenderer
{
public:
    GeometryRenderer();
    ~GeometryRenderer();
    void DrawRectangle(glm::vec2 origin, glm::vec2 size);
};

#endif /* GeometryRenderer_hpp */
