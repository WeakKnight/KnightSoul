//
//  GameObject.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/16.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Input.hpp"
#include "ResourceManager.hpp"
#include "SpriteSheet.hpp"
#include "SpriteRenderer.hpp"
#include "Game.hpp"

std::vector<GameObject*> GameObject::GameObjectList;

GameObject* GameObject::Create()
{
    auto gameObject = new GameObject();
    GameObjectList.push_back(gameObject);
    return gameObject;
}

GameObject::GameObject()
{
    
}

void GameObject::Init()
{
    
}

void GameObject::Update(float dt)
{
    auto spriteIdle = ResourceManager::Sprites["skeleton_idle"];
    auto spriteRun = ResourceManager::Sprites["skeleton_run"];
    if(SpritePointer)
    {
        SpritePointer->Update(dt);
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_LEFT))
    {
        X -= 3.0;
        SpritePointer = spriteRun;
    }
    if(Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        X += 3.0;
        SpritePointer = spriteRun;
    }
    if(!Input::KeyboardPressed(SDL_SCANCODE_LEFT) && !Input::KeyboardPressed(SDL_SCANCODE_RIGHT))
    {
        SpritePointer = spriteIdle;
    }
}

void GameObject::Draw()
{
    auto sprite = this->SpritePointer;
    int imageIndex = (int)(sprite->ImageIndex);
    std::string imageName = sprite->SpriteFrames[imageIndex];
    auto spriteFrame = sprite->SpriteSheetGroup->Frames[imageName];
    auto texture = ResourceManager::Textures[sprite->SpriteSheetGroup->Texture_Index];
    Game::SpriteRendererInstance->DrawSprite(texture,
                                       glm::vec2(this->X, this->Y),
                                       glm::vec2(spriteFrame->W * this->Image_XScale, spriteFrame->H * this->Image_YScale),
                                       this->Rotation,
                                       glm::vec3(1.0f, 1.0f, 1.0f),
                                       glm::vec4((float)(spriteFrame->X)/(float)(texture.Width), (float)(spriteFrame->Y)/(float)(texture.Height), (float)(spriteFrame->W)/(float)(texture.Width), (float)(spriteFrame->H)/(float)(texture.Height)));
}

