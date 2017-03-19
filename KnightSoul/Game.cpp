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

SpriteRenderer  *Renderer;

Game::Game(GLuint width, GLuint height)
:
State(GAME_ACTIVE),
Width(width),
Height(height)
{
}

Game::~Game()
{
}

void Game::Init()
{
    auto sheet = SpriteSheet::Create("Resource/texture1.json");
    //
    ResourceManager::LoadShader("Resource/BaseShader.vsh", "Resource/BaseShader.fsh", "BaseShader");
    ResourceManager::LoadTexture("Resource/QQ20170106.png", "TestSprite");
    ResourceManager::LoadTexture("Resource/pikapika.png", "PikaSprite");
    ResourceManager::LoadTexture("Resource/windows.jpg", "WindowSprite");
    ResourceManager::LoadTexture("Resource/skeletonTexture.png", "skeletonTexture");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width),
                                      static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::Shaders["BaseShader"].Use().SetInteger("image", 0);
    ResourceManager::Shaders["BaseShader"].SetMatrix4("projection", projection);
    Renderer = new SpriteRenderer(ResourceManager::Shaders["BaseShader"]);
    ////////
    GameObject* obj1 = GameObject::Create();
    obj1->X = 200.0f;
    obj1->Y = 100.0f;
    obj1->Image_XScale = 8.0;
    obj1->Image_YScale = 8.0;
    obj1->Rotation = 0.0f;
    obj1->Image_Index = "skeletonTexture";
    obj1->Sprite_Frame = glm::vec4(0.0f,0.0f,24.0f/49.0f,35.0f/72.0f);
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
    for(auto index = 0; index < GameObject::GameObjectList.size(); index++)
    {
        auto gameObject = GameObject::GameObjectList[index];
        Renderer->DrawSprite(ResourceManager::Textures[gameObject->Image_Index], glm::vec2(gameObject->X, gameObject->Y), glm::vec2(ResourceManager::Textures[gameObject->Image_Index].Width * gameObject->Sprite_Frame.z * gameObject->Image_XScale, ResourceManager::Textures[gameObject->Image_Index].Height* gameObject->Sprite_Frame.w * gameObject->Image_YScale), gameObject->Rotation, glm::vec3(1.0f, 1.0f, 1.0f),gameObject->Sprite_Frame);
    }
    //Renderer->DrawSprite(ResourceManager::Textures["TestSprite"], glm::vec2(200, 100), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    //Renderer->DrawSprite(ResourceManager::Textures["TestSprite"], glm::vec2(400, 400), glm::vec2(150, 200), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}
