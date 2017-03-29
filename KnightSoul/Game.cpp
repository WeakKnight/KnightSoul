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
#include "View.hpp"
#include "GeometryRenderer.hpp"

Game::Game(Context* context)
:
Object(context),
SpriteRendererInstance(nullptr),
GameSurface(nullptr)
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
    ResourceManager::LoadShader("Resource/LineShader.vsh", "Resource/LineShader.fsh", "LineShader");
    ResourceManager::LoadTexture("Resource/skeletonTexture.png", "skeletonTexture");
    ResourceManager::LoadSpriteSheet("Resource/texture1.json");
    ResourceManager::LoadSprite("Resource/testSprite.json");
    ResourceManager::LoadSprite("Resource/testSprite2.json");
    ResourceManager::LoadSprite("Resource/testSprite3.json");
    ActiveRoom = new Room(EngineContext, "Resource/room0.json");
    ActiveRoom->Init();
    
    GameSurface = new Surface(ActiveRoom->ActiveView->Boundary.Size.x, ActiveRoom->ActiveView->Boundary.Size.y);
    InitSpriteRenderer();
    InitGeometryRenderer();
}

void Game::InitSpriteRenderer()
{
    auto view = EngineContext->GameInstance->ActiveRoom->ActiveView;
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(view->Boundary.Size.x),
                                      static_cast<GLfloat>(view->Boundary.Size.y), 0.0f, -1.0f, 1.0f);
    ResourceManager::Shaders["BaseShader"].Use().SetInteger("image", 0);
    ResourceManager::Shaders["BaseShader"].SetMatrix4("projection", projection);
    SpriteRendererInstance = new SpriteRenderer(ResourceManager::Shaders["BaseShader"]);
}

void Game::InitGeometryRenderer()
{
    auto view = EngineContext->GameInstance->ActiveRoom->ActiveView;
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(view->Boundary.Size.x),
                                      static_cast<GLfloat>(view->Boundary.Size.y), 0.0f, -1.0f, 1.0f);
    ResourceManager::Shaders["LineShader"].Use().SetInteger("image", 0);
    ResourceManager::Shaders["LineShader"].SetMatrix4("projection", projection);
    GeometryRendererInstance = new GeometryRenderer(ResourceManager::Shaders["LineShader"]);
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
    Surface::SetTarget(GameSurface);
    ActiveRoom->Render();
    Surface::ResetTarget();
}
