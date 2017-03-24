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
#include "json.hpp"
#include "File.hpp"
#include "View.hpp"
#include "ObjectFactory.hpp"

Room::Room(Context* context)
:
Object(context)
{
}

Room::Room(Context* context, const std::string& path)
:
Object(context)
{
    LoadRoomSetting(path);
}

void Room::LoadRoomSetting(const std::string& path)
{
    //"Resource/room0.json"
    auto str = File::ReadString(path);
    nlohmann::json j = nlohmann::json::parse(str);
    Name = j["name"];
    float viewX = j["view"]["x"];
    float viewY = j["view"]["y"];
    float viewWidth = j["view"]["width"];
    float viewHeight = j["view"]["height"];
    auto view = new View(Rect(glm::vec2(viewX, viewY), glm::vec2(viewWidth, viewHeight)));
    ActiveView = view;
    auto instances = j["instances"];
    for(int index = 0; index < instances.size(); index++)
    {
        std::string gameObjectName = instances[index]["name"];
        float xPos = instances[index]["x"];
        float yPos = instances[index]["y"];
        float xscale = instances[index]["xscale"];
        float yscale = instances[index]["yscale"];
        float rotation = instances[index]["rotation"];
        auto gameObject = EngineContext->ObjectFactoryInstance->CreateInstanceByName(gameObjectName);
        gameObject->X = xPos;
        gameObject->Y = yPos;
        gameObject->Image_XScale = xscale;
        gameObject->Image_YScale = yscale;
        gameObject->Rotation = rotation;
        AddInstance(gameObject);
    }
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

//TODO: View control Game Port
void Room::Render()
{
    auto view = EngineContext->GameInstance->ActiveRoom->ActiveView;
    glViewport(0, 0, 640, 480);
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
