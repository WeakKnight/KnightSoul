//
//  main.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/6.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl3.h>
#include "Include/SDL2/SDL.h"
#include "Game.hpp"
#include "Input.hpp"

const GLuint SCREEN_WIDTH = 1024;
const GLuint SCREEN_HEIGHT = 768;
const unsigned int FPS = 60;

Game GameInstance(SCREEN_WIDTH,SCREEN_HEIGHT);

void* InitGL(SDL_Window* window)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    auto context = SDL_GL_CreateContext(window);
    return context;
}

int main(int argc, const char * argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Hello, World!\n";
    }
    auto mainWindow = SDL_CreateWindow(
                                  "My Game",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_OPENGL
                                  );
    
    auto mainContext = InitGL(mainWindow);
    
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //
    GameInstance.Init();
    GameInstance.State = GAME_ACTIVE;
    //
    SDL_GL_SetSwapInterval(1);
    //const Uint8* state = SDL_GetKeyboardState(NULL);
    Input::InitInput(SDL_GetKeyboardState(NULL));
    SDL_Event event;
    /////////
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;
    //
    float nextFrame = static_cast<float>(SDL_GetTicks());
    bool shouldExit = false;
    while(!shouldExit)
    {
        if(Input::KeyboardPressed(SDL_SCANCODE_ESCAPE))
        {
            shouldExit = true;
        }
        GLfloat currentFrame = SDL_GetTicks();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        SDL_PollEvent(&event);
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        GameInstance.ProcessInput(deltaTime);
        GameInstance.Update(deltaTime);
        if(nextFrame > static_cast<float>(SDL_GetTicks()))
        {
            GameInstance.Render();
            SDL_GL_SwapWindow(mainWindow);
        }
        float delay = static_cast<float> (nextFrame - static_cast<double>(SDL_GetTicks()));
        if(delay > 0){
            SDL_Delay(delay);
        }
        nextFrame += 1000.0 / FPS;
    }

    SDL_GL_DeleteContext(mainContext);
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();
    return 0;
}
