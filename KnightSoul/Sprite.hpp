//
//  Sprite.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <stdio.h>
#include "SpriteSheet.hpp"
#include <map>

class Sprite
{
public:
    static Sprite* Create();
    void Update(float dt);
    void SetFrame(int frameIndex, std::string frameName);
    std::map<int, std::string> SpriteFrames;
    SpriteSheet* SpriteSheetGroup;
    float Image_Speed;
    float Image_Index;
};

#endif /* Sprite_hpp */
