//
//  Game.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/14.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Game.hpp"
#include "ResourceManager.hpp"
#include "SpriteRenderer.hpp"
#include "GameObject.hpp"
#include "SpriteSheet.hpp"
#include "Sprite.hpp"
#include "Context.hpp"

Game::Game(Context* context,GLuint width, GLuint height)
:
Object(context),
Width(width),
Height(height),
SpriteRendererInstance(nullptr)
{
    context->GameInstance = this;
}

Game::~Game()
{
}

void Game::Init()
{
    //todo: move in resource.json
    ResourceManager::LoadShader("Resource/BaseShader.vsh", "Resource/BaseShader.fsh", "BaseShader");
    ResourceManager::LoadTexture("Resource/QQ20170106.png", "TestSprite");
    ResourceManager::LoadTexture("Resource/pikapika.png", "PikaSprite");
    ResourceManager::LoadTexture("Resource/windows.jpg", "WindowSprite");
    ResourceManager::LoadTexture("Resource/skeletonTexture.png", "skeletonTexture");
    ResourceManager::LoadSpriteSheet("Resource/texture1.json");
    ResourceManager::LoadSprite("Resource/testSprite.json");
    ResourceManager::LoadSprite("Resource/testSprite2.json");
    //
    auto spriteIdle = ResourceManager::Sprites["skeleton_idle"];
    
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width),
                                      static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::Shaders["BaseShader"].Use().SetInteger("image", 0);
    ResourceManager::Shaders["BaseShader"].SetMatrix4("projection", projection);
    SpriteRendererInstance = new SpriteRenderer(ResourceManager::Shaders["BaseShader"]);
    ////////
    GameObject* obj1 = GameObject::Create(EngineContext);
    obj1->X = 200.0f;
    obj1->Y = 200.0f;
    obj1->Image_XScale = 8.0;
    obj1->Image_YScale = 8.0;
    obj1->Rotation = 0.0f;
    obj1->SpritePointer = spriteIdle;
    ////////
    for(auto index = 0; index < GameObject::GameObjectList.size(); index++)
    {
        auto gameObject = GameObject::GameObjectList[index];
        gameObject->Init();
    }
}

void Game::Update(GLfloat dt)
{
    for(auto index = 0; index < GameObject::GameObjectList.size(); index++)
    {
        auto gameObject = GameObject::GameObjectList[index];
        gameObject->Update(dt);
    }
}

void Game::ProcessInput(GLfloat dt)
{
    
}

void Game::Render()
{
    glViewport(0, 0, Width, Height);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(49.0f/255.0f, 77.0f/255.0f, 121.0f/255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    for(auto index = 0; index < GameObject::GameObjectList.size(); index++)
    {
        auto gameObject = GameObject::GameObjectList[index];
        gameObject->Draw();
    }
}
