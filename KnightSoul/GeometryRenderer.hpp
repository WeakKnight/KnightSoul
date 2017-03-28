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
#include "Shader.hpp"

class GeometryRenderer
{
public:
    GeometryRenderer(Shader &shader);
    ~GeometryRenderer();
    void DrawRectangle(glm::vec2 origin, glm::vec2 size);
private:
    GLuint quadVAO;
    Shader shader;
    void initRenderData();
};

#endif /* GeometryRenderer_hpp */
