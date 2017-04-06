//
//  SpriteEditor.cpp
//  KnightSoul
//
//  Created by Knight on 2017/4/5.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "SpriteEditor.hpp"
#include "File.hpp"
#include "MemoryBuffer.h"
#include "RawImage.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void SliceByOffset(int offsetX, int offsetY, int w, int h, RawImage* image)
{
    auto newImageData = new unsigned char[w * h * image->_components];
    auto data = image->getData();
    for(int x = 0; x < w * image->_components; x++)
    {
        for(int y = 0; y < h; y++)
        {
            auto index = x + offsetX * image->_components + (y + offsetY) * (image->_components * image->getWidth());
            newImageData[x + y * w * image->_components] = data[index];
        }
    }
    stbi_write_png("/Users/knight/Documents/KnightSoulWorkSpace/KnightSoul/Resource/Character_1.png", w, h, image->_components, newImageData, w * image->_components);
    delete[] newImageData;
}

void SliceImage()
{
    RawImage image;
    image.beginLoad("Resource/Character.png");
    SliceByOffset(32 * 2, 32, 32, 32, &image);
}
