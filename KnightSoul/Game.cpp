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
#include "Room.hpp"

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
    InitSpriteRenderer();
    //
    auto spriteIdle = ResourceManager::Sprites["skeleton_idle"];
    ActiveRoom = new Room(EngineContext);
    
    ////////
    GameObject* obj1 = new GameObject(EngineContext);
    obj1->X = 200.0f;
    obj1->Y = 200.0f;
    obj1->Image_XScale = 8.0;
    obj1->Image_YScale = 8.0;
    obj1->Rotation = 0.0f;
    obj1->SpritePointer = spriteIdle;
    ////////
    ActiveRoom->AddInstance(obj1);
    //
    ActiveRoom->Init();
}

void Game::InitSpriteRenderer()
{
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width),
                                      static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::Shaders["BaseShader"].Use().SetInteger("image", 0);
    ResourceManager::Shaders["BaseShader"].SetMatrix4("projection", projection);
    SpriteRendererInstance = new SpriteRenderer(ResourceManager::Shaders["BaseShader"]);
}

void Game::Update(GLfloat dt)
{
    ActiveRoom->Update(dt);
}

void Game::ProcessInput(GLfloat dt)
{
    
}

void Game::Render()
{
    ActiveRoom->Render();
}
