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
#include "GeometryRenderer.hpp"
#include "Game.hpp"
#include "Context.hpp"
#include "Room.hpp"
#include "View.hpp"

GameObject::GameObject(Context* context)
:
Object(context)
{
}

void GameObject::Init()
{
    
}

void GameObject::Update(float dt)
{
    if(SpritePointer)
    {
        SpritePointer->Update(dt);
    }
}

void GameObject::Draw()
{
    auto sprite = this->SpritePointer;
    int imageIndex = (int)(sprite->ImageIndex);
    std::string imageName = sprite->SpriteFrames[imageIndex];
    auto spriteFrame = sprite->SpriteSheetGroup->Frames[imageName];
    auto texture = ResourceManager::Textures[sprite->SpriteSheetGroup->Texture_Index];
    auto view = EngineContext->GameInstance->ActiveRoom->ActiveView;
    
    EngineContext->GameInstance->SpriteRendererInstance->DrawSprite(texture,
                                       glm::vec2(this->X - view->Boundary.Origin.x - spriteFrame->W * sprite->pivotX, this->Y - view->Boundary.Origin.y - spriteFrame->H * sprite->pivotY),
                                       glm::vec2(spriteFrame->W * this->Image_XScale, spriteFrame->H * this->Image_YScale),
                                       this->Rotation,
                                       glm::vec3(1.0f, 1.0f, 1.0f),
                                       glm::vec4((float)(spriteFrame->X)/(float)(texture.Width), (float)(spriteFrame->Y)/(float)(texture.Height), (float)(spriteFrame->W)/(float)(texture.Width), (float)(spriteFrame->H)/(float)(texture.Height)));
    //draw sprite bound
    EngineContext->GameInstance->GeometryRendererInstance->DrawRectangle(glm::vec2(X- view->Boundary.Origin.x,Y- view->Boundary.Origin.y), glm::vec2(spriteFrame->W,spriteFrame->H));
    //draw pivot
    EngineContext->GameInstance->GeometryRendererInstance->DrawRectangle(glm::vec2(X- view->Boundary.Origin.x - spriteFrame->W * sprite->pivotX,Y- view->Boundary.Origin.y- spriteFrame->H * sprite->pivotY),
                                                                         glm::vec2(5,5));
}

