//
//  ResourceManager.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/14.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "ResourceManager.hpp"
#include "RawImage.hpp"
#include "File.hpp"
#include "SpriteSheet.hpp"
#include "Sprite.hpp"

std::map<std::string, Texture2D>    ResourceManager::Textures;
std::map<std::string, Shader>       ResourceManager::Shaders;
std::map<std::string, SpriteSheet*> ResourceManager::SpriteSheets;
std::map<std::string, Sprite*>      ResourceManager::Sprites;

Shader ResourceManager::LoadShader(const std::string& vpath, const std::string& fpath, const std::string& name)
{
    auto vStr = File::ReadString(vpath);
    auto fStr = File::ReadString(fpath);
    Shader shader;
    shader.Compile(vStr, fStr);
    Shaders[name] = shader;
    return shader;
}

Texture2D ResourceManager::LoadTexture(const std::string& path, const std::string& name)
{
    auto image = new RawImage();
    image->beginLoad(path);
    Texture2D texture;
    if(image->_components == 4)
    {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    else
    {
        texture.Internal_Format = GL_RGB;
        texture.Image_Format = GL_RGB;
    }
    texture.Generate(image->getWidth(), image->getHeight(), image->getData());
    delete image;
    Textures[name] = texture;
    return texture;
}

SpriteSheet* ResourceManager::LoadSpriteSheet(const std::string& path)
{
    auto spriteSheet = SpriteSheet::Create(path);
    SpriteSheets[spriteSheet->Name] = spriteSheet;
    return spriteSheet;
}

Sprite* ResourceManager::LoadSprite(const std::string& path)
{
    auto sprite = Sprite::Create(path);
    Sprites[sprite->SpriteName] = sprite;
    return sprite;
}

void ResourceManager::Clear()
{
    // (Properly) delete all shaders
    for (auto iter : Shaders)
    {
        glDeleteProgram(iter.second.ID);
    }
    // (Properly) delete all textures
    for (auto iter : Textures)
    {
        glDeleteTextures(1, &iter.second.ID);
    }
}
