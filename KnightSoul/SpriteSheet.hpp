//
//  SpriteSheet.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/18.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef SpriteSheet_hpp
#define SpriteSheet_hpp

#include <stdio.h>
#include <string>
#include <map>

class SpriteFrame
{
public:
    SpriteFrame(const std::string& name,
                int x,
                int y,
                int w,
                int h)
    {
        Name = name;
        X = x;
        Y = y;
        W = w;
        H = h;
    };
    
    std::string Name;
    int X;
    int Y;
    int W;
    int H;
};

class SpriteSheet
{
public:
    static SpriteSheet* Create(const std::string& jsonPath);
    std::map<std::string, SpriteFrame*> Frames;
    std::string Texture_Index;
    std::string Name;
private:
    SpriteSheet();
};

#endif /* SpriteSheet_hpp */
