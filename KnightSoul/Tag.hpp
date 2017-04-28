//
//  Tag.hpp
//  KnightSoul
//
//  Created by Knight on 2017/4/28.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Tag_hpp
#define Tag_hpp

#include <stdio.h>
#include <string>

class Tag
{
public:
    
    void operator =(const Tag& other)
    {
        TagText = other.TagText;
        HashCode = other.HashCode;
    }
    
    bool operator !=(const Tag& other) const
    {
        return (HashCode != other.HashCode);
    }
    
    bool operator ==(const Tag& other) const
    {
        return (HashCode == other.HashCode);
    }
    
    Tag(const char* tagStr);
    std::string TagText = {};
    std::size_t HashCode = 0;
};

#endif /* Tag_hpp */
