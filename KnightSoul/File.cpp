//
//  File.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/6.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "File.hpp"
#include "MemoryBuffer.h"
#include <memory.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <assert.h>

namespace File
{
    MemoryBuffer ReadFile(const std::string& path)
    {
        
        unsigned char* data = nullptr;
        
        FILE* fp = fopen(path.c_str(), "rb");
        if (fp == nullptr)
        {
            return MemoryBuffer::Null;
        }
        
        auto descriptor = fileno(fp);
        struct stat statBuf;
        if (fstat(descriptor, &statBuf) == -1)
        {
            fclose(fp);
            return MemoryBuffer::Null;
        }
        size_t size = statBuf.st_size;
        
        data = (unsigned char*)malloc(size);
        memset(data , 0 , size);
        size_t readSize = fread(data, sizeof(unsigned char), size, fp);
        
        fclose(fp);
        
        MemoryBuffer ret;
        if (data == nullptr || readSize == 0 || readSize < size)
        {
            assert(0);
            //        std::string msg = "Get data from file(";
            //        msg.append(path).append(") failed!");
        }
        else
        {
            ret.fastSet(data, readSize);
        }
        
        return ret;
    }
    
    char* ReadString(const std::string& path)
    {
        assert(!path.empty());
        
        unsigned char* data = nullptr;
        
        FILE* fp = fopen(path.c_str(), "rb");
        if (fp == nullptr)
        {
            return nullptr;
        }
        
        auto descriptor = fileno(fp);

        struct stat statBuf;
        if (fstat(descriptor, &statBuf) == -1)
        {
            fclose(fp);
            return nullptr;
        }
        size_t size = statBuf.st_size;
        
        data = (unsigned char*)malloc(size + 1);
        memset(data , 0 , size + 1);
        data[size] = '\0';
        size += 1;
        fread(data, sizeof(unsigned char), size, fp);
        
        fclose(fp);
        
        return (char*)data;
    }
}
