//
//  Sprite.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Sprite.hpp"

Sprite* Sprite::Create()
{
    auto sprite = new Sprite();
    return sprite;
}

void Sprite::SetFrame(int frameIndex, std::string frameName)
{
    SpriteFrames[frameIndex] = frameName;
}



