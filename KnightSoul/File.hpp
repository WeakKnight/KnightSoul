//
//  File.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/6.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include <stdio.h>
#include <string>

class MemoryBuffer;
namespace File
{
    MemoryBuffer ReadFile(const std::string& path);
    char* ReadString(const std::string& path);
}
#endif /* File_hpp */
