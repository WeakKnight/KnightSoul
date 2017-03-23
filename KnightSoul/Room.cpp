//
//  Room.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/20.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Room.hpp"
#include "Context.hpp"
#include "GameObject.hpp"
#include "Game.hpp"

Room::Room(Context* context)
:
Object(context)
{
}

void Room::AddInstance(GameObject* object)
{
    InstanceList.push_back(object);
}

void Room::Init()
{
    for(auto itr = InstanceList.begin(); itr != InstanceList.end(); itr++)
    {
        auto gameObject = (*itr);
        gameObject->Init();
    }
}
void Room::Update(GLfloat dt)
{
    for(auto itr = InstanceList.begin(); itr != InstanceList.end(); itr++)
    {
        auto gameObject = (*itr);
        gameObject->Update(dt);
    }
}
//TODO: remove gameobject from linked list here
void Room::Destoroy(GLfloat dt)
{
    
}

void Room::Render()
{
    glViewport(0, 0, EngineContext->GameInstance->Width, EngineContext->GameInstance->Height);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(49.0f/255.0f, 77.0f/255.0f, 121.0f/255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    for(auto itr = InstanceList.begin(); itr != InstanceList.end(); itr++)
    {
        auto gameObject = (*itr);
        gameObject->Draw();
    }
}
