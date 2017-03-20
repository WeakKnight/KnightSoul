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
    SpriteFrame(std::string name,
                int x,
                int y,
                int w,
                int h,
                int offsetX,
                int offsetY,
                int sourceWidth,
                int sourceHeight)
    {
        Name = name;
        X = x;
        Y = y;
        W = w;
        H = h;
        OffsetX = offsetX;
        OffsetY = offsetY;
        SourceWidth = sourceWidth;
        SourceHeight = sourceHeight;
    };
    
    std::string Name;
    int X;
    int Y;
    int W;
    int H;
    int OffsetX;
    int OffsetY;
    int SourceWidth;
    int SourceHeight;
};

class SpriteSheet
{
public:
    static SpriteSheet* Create(std::string jsonPath);
    std::map<std::string, SpriteFrame*> Frames;
    std::string Texture_Index;
    std::string Name;
private:
    SpriteSheet();
};

#endif /* SpriteSheet_hpp */
