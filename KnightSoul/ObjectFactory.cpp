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
#include "Skeleton.hpp"
#include "PikaPika.hpp"
#include "DudeBullet.hpp"

ObjectFactory::ObjectFactory(Context* context)
:
Object(context)
{
    EngineContext->ObjectFactoryInstance = this;
}

GameObject* ObjectFactory::CreateInstanceByName(std::string name)
{
    if(name == "oSkeleton")
    {
        return new Skeleton(EngineContext);
    }
    else if(name == "oPikaPika")
    {
        return new PikaPika(EngineContext);
    }
    else if(name == "oDudeBullet")
    {
        return new DudeBullet(EngineContext);
    }
    return nullptr;
}
