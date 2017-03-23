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
#include "Editor.hpp"
#include "Input.hpp"
#include "imgui.h"
#include "imgui_impl_sdl_gl3.h"
#include "Texture2D.hpp"
#include "Context.hpp"
#include "ObjectFactory.hpp"

const GLuint SCREEN_WIDTH = 1024;
const GLuint SCREEN_HEIGHT = 768;
const unsigned int FPS = 60;

void* InitGL(SDL_Window* window)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    auto context = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1);
    return context;
}

int main(int argc, const char * argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Hello, World!\n";
    }
    auto mainWindow = SDL_CreateWindow(
                                  "KnightSoul",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_OPENGL
                                  );
    
    auto mainContext = InitGL(mainWindow);
    //
    Context* context = new Context();
    Game* GameInstance = new Game(context,SCREEN_WIDTH,SCREEN_HEIGHT);
    Editor* EditorInstance = new Editor(context,SCREEN_WIDTH,SCREEN_HEIGHT);
    new ObjectFactory(context);
    //
    GameInstance->Init();
    EditorInstance->Init(mainWindow);
    //const Uint8* state = SDL_GetKeyboardState(NULL);
    Input::InitInput(SDL_GetKeyboardState(NULL));
    SDL_Event event;
    /////////
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;
    //
    Texture2D GameRendererTarget;
    GameRendererTarget.Generate(SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    GLuint frameBuffer;
    glGenFramebuffers(1, &frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, GameRendererTarget.ID, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    EditorInstance->SetGameView(GameRendererTarget.ID);
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
        while(SDL_PollEvent(&event))
        {
            ImGui_ImplSdlGL3_ProcessEvent(&event);
        }
        GameInstance->ProcessInput(deltaTime);
        GameInstance->Update(deltaTime);
        EditorInstance->Update(deltaTime);
        
        if(nextFrame > static_cast<float>(SDL_GetTicks()))
        {
            glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
            GameInstance->Render();
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
            EditorInstance->Render();
            SDL_GL_SwapWindow(mainWindow);
        }
        float delay = static_cast<float> (nextFrame - static_cast<double>(SDL_GetTicks()));
        if(delay > 0){
            SDL_Delay(delay);
        }
        nextFrame += 1000.0 / FPS;
    }
    ImGui_ImplSdlGL3_Shutdown();
    SDL_GL_DeleteContext(mainContext);
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();
    return 0;
}
