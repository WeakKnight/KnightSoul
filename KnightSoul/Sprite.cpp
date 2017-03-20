//
//  Sprite.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Sprite.hpp"
#include "json.hpp"

using namespace nlohmann;

Sprite* Sprite::Create()
{
    auto sprite = new Sprite();
    sprite->ImageIndex = 0;
    sprite->ImageSpeed = 0;
    sprite->ImageNumber = 0;
    return sprite;
}

Sprite* Sprite::Create(std::string jsonPath)
{
    json j = json::parse(jsonPath);
    std::string spriteName = j["file"];
    
    auto sprite = new Sprite();
    return sprite;
}

void Sprite::Update(float dt)
{
    if(ImageIndex + ImageSpeed > ImageNumber)
    {
        ImageIndex = ImageIndex + ImageSpeed - ImageNumber;
    }
    else
    {
        ImageIndex = ImageIndex + ImageSpeed;
    }
}

void Sprite::SetFrame(int imageIndex, std::string imageName)
{
    SpriteFrames[imageIndex] = imageName;
}



