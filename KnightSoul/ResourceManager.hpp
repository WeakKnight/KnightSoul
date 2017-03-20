//
//  ResourceManager.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/14.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <stdio.h>
#include <map>
#include <string>
#include "Shader.hpp"
#include "Texture2D.hpp"

class SpriteSheet;
class Sprite;

class ResourceManager
{
public:
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture2D> Textures;
    static std::map<std::string, SpriteSheet*> SpriteSheets;
    static std::map<std::string, Sprite*> Sprites;
    
    static Shader LoadShader(const std::string& vpath, const std::string& fpath, const std::string& name);
    static Texture2D LoadTexture(const std::string& path, const std::string& name);
    static SpriteSheet* LoadSpriteSheet(const std::string& path);
    static Sprite* LoadSprite(const std::string& path);
    
    void Clear();
};

#endif /* ResourceManager_hpp */
