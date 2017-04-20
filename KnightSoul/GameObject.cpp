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
#include "CollisionComponent.hpp"

GameObject::GameObject(Context* context)
:
Object(context),
CollisionCom(nullptr)
{
    CollisionCom = new CollisionComponent(this);
}

void GameObject::Init()
{
    delete CollisionCom;
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
    //auto spriteFrame = sprite->SpriteSheetGroup->Frames[imageName];
    auto view = EngineContext->GameInstance->ActiveRoom->ActiveView;
    
    EngineContext->GameInstance->SpriteRendererInstance->DrawSprite(SpritePointer, glm::vec2(X- view->Boundary.Origin.x,Y- view->Boundary.Origin.y), glm::vec2(Image_XScale,Image_YScale), Rotation);
    //draw sprite bound
//    EngineContext->GameInstance->GeometryRendererInstance->DrawRectangle(glm::vec2(X- view->Boundary.Origin.x,Y- view->Boundary.Origin.y), glm::vec2(spriteFrame->W,spriteFrame->H));
    //draw origin x,y
    //EngineContext->GameInstance->GeometryRendererInstance->DrawRectangle(glm::vec2(X- view->Boundary.Origin.x,Y- view->Boundary.Origin.y),
    //                                                                     glm::vec2(3,3));
}

