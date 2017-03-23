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
#include "Object.hpp"

class Sprite;
class Context;
class GameObject : public Object
{
    GameObject(Context* context);
public:
    static GameObject* Create(Context* context);
    virtual void Init();
    virtual void Update(float dt);
    virtual void Draw();
    float X;
    float Y;
    float Rotation;
    float Image_XScale;
    float Image_YScale;
    float MoveSpeed;
    static std::vector<GameObject*> GameObjectList;
    Sprite* SpritePointer;
};

#endif /* GameObject_hpp */
