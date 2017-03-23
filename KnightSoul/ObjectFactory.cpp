//
//  ObjectFactory.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/23.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "ObjectFactory.hpp"
#include "GameObject.hpp"
#include "Context.hpp"

ObjectFactory::ObjectFactory(Context* context)
:
Object(context)
{
    EngineContext->ObjectFactoryInstance = this;
}

GameObject* ObjectFactory::CreateInstanceByName(std::string name)
{
    /*
    if(name == "GameObject")
    {
        return GameObject::Create();
    }
    */
    return nullptr;
}
