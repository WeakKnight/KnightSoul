//
//  GameObject.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/16.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Texture2D.hpp"
#include <vector>
#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

class Sprite;

class GameObject
{
    GameObject();
public:
    static GameObject* Create();
    virtual void Init();
    virtual void Update(float dt);
    float X;
    float Y;
    float Rotation;
    float Image_XScale;
    float Image_YScale;
    std::string Image_Index;
    static std::vector<GameObject*> GameObjectList;
    Sprite* SpritePointer;
    glm::vec4 Sprite_Frame;
};

#endif /* GameObject_hpp */
