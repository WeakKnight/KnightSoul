//
//  StringUtil.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/19.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef StringUtil_hpp
#define StringUtil_hpp

#include <stdio.h>
#include <string>
#include <vector>

namespace StringUtil
{
    std::string Format(const std::string fmt_str, ...);
    std::vector<std::string> Split(const std::string& str, char delim);
}

#endif /* StringUtil_hpp */
