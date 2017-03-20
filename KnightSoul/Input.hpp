//
//  Input.hpp
//  KnightSoul
//
//  Created by Knight on 2017/3/20.
//  Copyright © 2017年 Knight. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>
#include "SDL.h"

namespace Input
{
    void InitInput(const Uint8* state);
    bool KeyboardPressed(SDL_Scancode keycode);
    bool KeyboardReleased(SDL_Scancode keycode);
}

#endif /* Input_hpp */
