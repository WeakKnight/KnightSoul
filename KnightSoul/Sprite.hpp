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
//Todo: correct do with Sprite pivot and Sprite Size
class Sprite
{
public:
    static Sprite* Create();
    static Sprite* Create(const std::string& jsonPath);
    void Update(float dt);
    void SetFrame(int imageIndex, const std::string& imageName);
    std::map<int, std::string> SpriteFrames;
    SpriteSheet* SpriteSheetGroup;
    std::string SpriteName;
    float ImageSpeed;
    float ImageIndex;
    float ImageNumber;
    int pivotX;
    int pivotY;
};

#endif /* Sprite_hpp */
