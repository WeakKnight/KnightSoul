//
//  Input.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/20.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Input.hpp"

namespace Input
{
    static const Uint8* State;
    void InitInput(const Uint8* state)
    {
        State = state;
    }
    bool KeyboardPressed(SDL_Scancode keycode)
    {
        return State[keycode] == SDL_PRESSED;
    }
    bool KeyboardReleased(SDL_Scancode keycode)
    {
        return State[keycode] == SDL_RELEASED;
    }
}
