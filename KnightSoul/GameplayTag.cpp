//
//  GameplayTag.cpp
//  KnightSoul
//
//  Created by Knight on 2017/4/28.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "GameplayTag.hpp"

GameplayTag::GameplayTag(const char* tagStr)
{
    HashCode = std::hash<std::string>{}(tagStr);
}
