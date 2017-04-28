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
#include "Tag.hpp"

class Sprite;
class CollisionComponent;
class Context;
class GameObject : public Object
{
public:
    GameObject(Context* context);
    ~GameObject();
    virtual void Init();
    void CalcAlarm();
    virtual void AlarmEvent(int alarmId);
    virtual void Update(float dt);
    virtual void Draw();
    float X;
    float Y;
    float Rotation;
    float Image_XScale;
    float Image_YScale;
    Sprite* SpritePointer;
    CollisionComponent* CollisionCom;
    int Alarm[12] = {};
    Tag GameplayTag = Tag("GameObject");
};

#endif /* GameObject_hpp */
