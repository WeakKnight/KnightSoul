//
//  SpriteSheet.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/18.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "SpriteSheet.hpp"
#include "json.hpp"
#include "File.hpp"
#include "ResourceManager.hpp"
#include "StringUtil.hpp"

using namespace nlohmann;

SpriteSheet::SpriteSheet()
{
}

SpriteSheet* SpriteSheet::Create(const std::string& jsonPath)
{
    auto str = File::ReadString(jsonPath);
    json j = json::parse(str);
    
    std::string texFileName = j["file"];
    std::string texName = StringUtil::Split(texFileName, '.')[0];
    auto spriteSheet = new SpriteSheet();
    ResourceManager::LoadTexture( StringUtil::Format("Resource/%s",texFileName.c_str()), texName.c_str());
    auto frames = j["frames"];
    for (auto itr = frames.begin(); itr != frames.end(); itr++)
    {
        std::string key = std::string(itr.key().c_str());
        int x = itr.value()["frame"]["x"];
        int y = itr.value()["frame"]["y"];
        int w = itr.value()["frame"]["w"];
        int h = itr.value()["frame"]["h"];
        SpriteFrame* spriteFrame = new SpriteFrame(key, x, y, w, h);
        spriteSheet->Frames[key] = spriteFrame;
    }
    spriteSheet->Texture_Index = texName;
    spriteSheet->Name = j["name"];
    return spriteSheet;
}
