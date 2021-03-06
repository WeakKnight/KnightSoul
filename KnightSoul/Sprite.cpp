//
//  Sprite.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Sprite.hpp"
#include "json.hpp"
#include "File.hpp"
#include "ResourceManager.hpp"

using namespace nlohmann;

Sprite* Sprite::Create()
{
    auto sprite = new Sprite();
    sprite->ImageIndex = 0;
    sprite->ImageSpeed = 0;
    sprite->ImageNumber = 0;
    return sprite;
}

Sprite* Sprite::Create(const std::string& jsonPath)
{
    auto sprite = new Sprite();
    
    auto str = File::ReadString(jsonPath);
    json j = json::parse(str);
    std::string spriteName = j["name"];
    auto frames = j["frames"];
    sprite->ImageNumber = 0;
    for (auto index = 0; index < frames.size(); index++)
    {
        std::string imageName = frames[index];
        sprite->SetFrame(index, imageName);
        sprite->ImageNumber += 1;
    }
    sprite->pivotX = j["pivotX"];
    sprite->pivotY = j["pivotY"];
    sprite->ImageSpeed = j["image_speed"];
    sprite->SpriteName = spriteName;
    sprite->ImageIndex = 0.0f;
    std::string sheetName = j["sheet_name"];
    sprite->SpriteSheetGroup = ResourceManager::SpriteSheets[sheetName];
    return sprite;
}

void Sprite::Update(float dt)
{
    if((ImageSpeed - 0.0f)*(ImageSpeed - 0.0f) < 0.000000001f)
    {
        return;
    }
    if(ImageIndex + ImageSpeed >= ImageNumber)
    {
        ImageIndex = ImageIndex + ImageSpeed - ImageNumber;
    }
    else
    {
        ImageIndex = ImageIndex + ImageSpeed;
    }
}

void Sprite::SetFrame(int imageIndex, const std::string& imageName)
{
    SpriteFrames[imageIndex] = imageName;
}



