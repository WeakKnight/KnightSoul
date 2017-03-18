//
//  RawImage.hpp
//  EgretWebGLFramework
//
//  Created by Knight on 2017/2/23.
//  Copyright © 2017年 Egret. All rights reserved.
//

#ifndef RawImage_hpp
#define RawImage_hpp

#include <string>

class RawImage
{
public:
    
    RawImage();
    ~RawImage();
    
public:
    
    bool beginLoad(const std::string& path);
    bool build(unsigned char* data, ssize_t dataLen);
    bool rebuild(unsigned char* data, ssize_t dataLen);
    bool setSize(int width, int height, int depth, unsigned components);
    void setData(const unsigned char* pixelData);
    inline int               getWidth() const             { return _width; }
    inline int               getHeight() const            { return _height; }
    inline unsigned char*    getData() const               { return _data; }
    inline ssize_t           getDataLen() const           { return _dataLen; }
    void dispose();
    
private:
    
    static void freeImageData(unsigned char* pixelData);
    unsigned char* getImageData(const unsigned char* data, ssize_t dataLength, int& width, int& height, unsigned& components);
    
public:
    
    std::string _path;
    unsigned _components;
    
private:
    
    int _width;
    int _height;
    int _depth;
    ssize_t _dataLen;
    unsigned char* _data;
};

#endif /* RawImage_hpp */
