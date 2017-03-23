//
//  Context.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/23.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Context_hpp
#define Context_hpp

#include <stdio.h>

class Game;
class Editor;
class ObjectFactory;

class Context
{
public:
    Context();
    Game* GameInstance;
    Editor* EditorInstance;
    ObjectFactory* ObjectFactoryInstance;
};

#endif /* Context_hpp */
