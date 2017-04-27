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
    ResourceManager::LoadTexture("Resource/Tiles.png", "Tiles");
    ResourceManager::LoadTexture("Resource/Character.png", "Character");
    ResourceManager::LoadShader("Resource/BaseShader.vsh", "Resource/BaseShader.fsh", "BaseShader");
    ResourceManager::LoadShader("Resource/LineShader.vsh", "Resource/LineShader.fsh", "LineShader");
    ResourceManager::LoadTexture("Resource/skeletonTexture.png", "skeletonTexture");
    ResourceManager::LoadSpriteSheet("Resource/texture1.json");
    ResourceManager::LoadSpriteSheet("Resource/texture2.json");
    ResourceManager::LoadSpriteSheet("Resource/texture3.json");
    ResourceManager::LoadSprite("Resource/testSprite.json");
    ResourceManager::LoadSprite("Resource/testSprite2.json");
    ResourceManager::LoadSprite("Resource/testSprite3.json");
    auto dudeIdleSpr = Sprite::Create();
    dudeIdleSpr->SpriteSheetGroup = ResourceManager::SpriteSheets["sheet_2"];
    dudeIdleSpr->SpriteFrames[0] = "dude0";
    dudeIdleSpr->SpriteFrames[1] = "dude1";
    //dudeIdleSpr->SpriteFrames[2] = "dude2";
    dudeIdleSpr->ImageNumber = 2;
    dudeIdleSpr->ImageSpeed = 0.1;
    dudeIdleSpr->pivotX = 0.5;
    ResourceManager::Sprites["dudeIdle"] = dudeIdleSpr;
    //
    auto dudeRunSpr = Sprite::Create();
    dudeRunSpr->SpriteSheetGroup = ResourceManager::SpriteSheets["sheet_2"];
    dudeRunSpr->SpriteFrames[0] = "dude8";
    dudeRunSpr->SpriteFrames[1] = "dude9";
    dudeRunSpr->SpriteFrames[2] = "dude10";
    dudeRunSpr->ImageNumber = 3;
    dudeRunSpr->ImageSpeed = 0.15;
    dudeRunSpr->pivotX = 0.5;
    ResourceManager::Sprites["dudeRun"] = dudeRunSpr;
    //
    auto dudeJumpSpr = Sprite::Create();
    dudeJumpSpr->SpriteSheetGroup = ResourceManager::SpriteSheets["sheet_2"];
    dudeJumpSpr->SpriteFrames[0] = "dude4";
    dudeJumpSpr->ImageNumber = 1;
    dudeJumpSpr->ImageSpeed = 0;
    dudeJumpSpr->pivotX = 0.5;
    ResourceManager::Sprites["dudeJump"] = dudeJumpSpr;
    //
    auto dudeIdleAttackSpr = Sprite::Create();
    dudeIdleAttackSpr->SpriteSheetGroup = ResourceManager::SpriteSheets["sheet_2"];
    dudeIdleAttackSpr->SpriteFrames[0] = "dude3";
    dudeIdleAttackSpr->ImageNumber = 1;
    dudeIdleAttackSpr->ImageSpeed = 0;
    dudeIdleAttackSpr->pivotX = 0.5;
    ResourceManager::Sprites["dudeIdleAttack"] = dudeIdleAttackSpr;
    //
    auto dudeRunAttackSpr = Sprite::Create();
    dudeRunAttackSpr->SpriteSheetGroup = ResourceManager::SpriteSheets["sheet_2"];
    dudeRunAttackSpr->SpriteFrames[0] = "dude11";
    dudeRunAttackSpr->SpriteFrames[1] = "dude12";
    dudeRunAttackSpr->SpriteFrames[2] = "dude13";
    dudeRunAttackSpr->ImageNumber = 3;
    dudeRunAttackSpr->ImageSpeed = 0.15;
    dudeRunAttackSpr->pivotX = 0.5;
    ResourceManager::Sprites["dudeRunAttack"] = dudeRunAttackSpr;
    //
    auto dudeJumpAttackSpr = Sprite::Create();
    dudeJumpAttackSpr->SpriteSheetGroup = ResourceManager::SpriteSheets["sheet_2"];
    dudeJumpAttackSpr->SpriteFrames[0] = "dude5";
    dudeJumpAttackSpr->ImageNumber = 1;
    dudeJumpAttackSpr->ImageSpeed = 0.15;
    dudeJumpAttackSpr->pivotX = 0.5;
    ResourceManager::Sprites["dudeJumpAttack"] = dudeJumpAttackSpr;
    //
    auto blockSpr = Sprite::Create();
    blockSpr->SpriteSheetGroup = ResourceManager::SpriteSheets["sheet_3"];
    blockSpr->SpriteFrames[0] = "Block0";
    blockSpr->SpriteFrames[1] = "Block1";
    blockSpr->SpriteFrames[2] = "Block2";
    blockSpr->ImageNumber = 3;
    blockSpr->ImageSpeed = 0;
    blockSpr->pivotX = 0.0;
    ResourceManager::Sprites["block"] = blockSpr;
    //
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
