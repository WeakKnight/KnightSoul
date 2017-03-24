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
#include "ObjectFactory.hpp"

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
    //TODO: move in resource.json
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
    ActiveRoom = new Room(EngineContext, "Resource/room0.json");
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

void Game::ProcessInput(GLfloat dt)
{
    
}

void Game::Update(GLfloat dt)
{
    ActiveRoom->Update(dt);
}

void Game::Destoroy(GLfloat dt)
{
    ActiveRoom->Destoroy(dt);
}

void Game::Render()
{
    ActiveRoom->Render();
}
