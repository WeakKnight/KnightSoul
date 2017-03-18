//
//  RawImage.cpp
//  EgretWebGLFramework
//
//  Created by Knight on 2017/2/23.
//  Copyright © 2017年 Egret. All rights reserved.
//

#include "RawImage.hpp"
#include "File.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "MemoryBuffer.h"

RawImage::RawImage():
_path(),
_width(0),
_height(0),
_depth(0),
_components(0),
_dataLen(0),
_data(nullptr)
{
}

RawImage::~RawImage()
{
    dispose();
}

bool RawImage::beginLoad(const std::string& path)
{
    _path = path;
    auto source = File::ReadFile(_path);
    return build(source.getBytes(), source.getSize());
}

bool RawImage::rebuild(unsigned char* data, ssize_t dataLen)
{
    dispose();
    return build(data, dataLen);
}
    
bool RawImage::build(unsigned char* data, ssize_t dataLen)
{
    int width = 0;
    int height = 0;
    unsigned components = 0;
    unsigned char* pixelData = getImageData(data, dataLen, width, height, components);
    if (!pixelData)
    {
        return false;
    }
    setSize(width, height, 1, components);
    setData(pixelData);
    freeImageData(pixelData);
    return true;
}
    
void RawImage::setData(const unsigned char* pixelData)
{
    if (!_data)
    {
        return;
    }
    
    memcpy(_data, pixelData, _width * _height * _depth * _components);
}

unsigned char* RawImage::getImageData(const unsigned char* data, ssize_t dataLength, int& width, int& height, unsigned& components)
{
    return stbi_load_from_memory(data, (int)dataLength, &width, &height, (int*)&components, 0);
}

void RawImage::freeImageData(unsigned char* pixelData)
{
    if (!pixelData)
    {
        return;
    }
    
    stbi_image_free(pixelData);
}
    
bool RawImage::setSize(int width, int height, int depth, unsigned components)
{
    if (width == _width && height == _height && depth == _depth && components == _components)
    {
        return true;
    }
    
    if (width <= 0 || height <= 0 || depth <= 0)
    {
        return false;
    }
    
    if (components > 4)
    {
        return false;
    }
    
    _dataLen = width * height * depth * components;
    _data = new unsigned char[_dataLen];
    _width = width;
    _height = height;
    _depth = depth;
    _components = components;
    
    return true;
}

void RawImage::dispose()
{
    _width = 0;
    _height = 0;
    _depth = 0;
    _path.clear();
    _components = 0;
    _dataLen = 0;
    
    if (_data != nullptr)
    {
        delete _data;
        _data = nullptr;
    }
}

