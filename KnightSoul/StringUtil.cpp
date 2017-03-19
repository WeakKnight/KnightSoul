//
//  StringUtil.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "StringUtil.hpp"
#include <stdlib.h>
#include <sstream>

namespace StringUtil
{

std::string Format(const std::string fmt_str, ...)
{
    auto finaln = 0;
    auto n = ((int)fmt_str.size()) * 2; // reserve 2 times as much as the length of the fmt_str
    std::unique_ptr<char[]> formatted;
    va_list ap;
    while(true)
    {
        //wrap the plain char array into the unique_ptr
        formatted.reset(new char[n]);
        strcpy(&formatted[0], fmt_str.c_str());
        va_start(ap, fmt_str);
        finaln = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
        va_end(ap);
        
        if (finaln < 0 || finaln >= n)
        {
            n += abs(finaln - n + 1);
        }
        else
        {
            break;
        }
    }
    
    return std::string(formatted.get());
}

std::vector<std::string> Split(const std::string& str, char delim)
{
    std::vector<std::string> elems;
    std::stringstream ss(str);
    
    std::string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    
    return elems;
}
    
}
