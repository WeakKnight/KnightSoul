//
//  Room.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/20.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>
#include <list>
#include <string>
#include "Object.hpp"
#include <OpenGL/gl3.h>

class GameObject;
class Context;

class View;

class Room : public Object
{
public:
    Room(Context* context);
    Room(Context* context, const std::string& path);
    void LoadRoomSetting(const std::string& path);
    void Init();
    void Update(GLfloat dt);
    void Destoroy(GLfloat dt);
    void Render();
    void AddInstance(GameObject* object);
    std::list<GameObject*> AddingInstanceList = {};
    std::list<GameObject*> InstanceList = {};
    std::list<GameObject*> DestroyInstanceList = {};
    View* ActiveView;
    std::string Name;
};

#endif /* Room_hpp */
