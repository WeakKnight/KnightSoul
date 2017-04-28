//
//  GameplayTag.hpp
//  KnightSoul
//
//  Created by Knight on 2017/4/28.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef GameplayTag_hpp
#define GameplayTag_hpp

#include <stdio.h>
#include <string>

class GameplayTag
{
public:
    bool operator ==(GameplayTag& other){
        return (HashCode == other.HashCode);
    }
    GameplayTag(const char* tagStr);
    std::string TagText = {};
    std::size_t HashCode = 0;
};

#endif /* GameplayTag_hpp */
