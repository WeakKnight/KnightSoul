//
//  Editor.cpp
//  KnightSoul
//
//  Created by Knight on 2017/3/23.
//  Copyright © 2017年 Knight. All rights reserved.
//

#include "Editor.hpp"
#include "imgui.h"
#include "imgui_impl_sdl_gl3.h"
#include "ResourceManager.hpp"



Editor::Editor(GLuint width, GLuint height)
:
Width(width),
Height(height)
{
    
}

void Editor::Init(SDL_Window* window)
{
    Window = window;
    ImGui_ImplSdlGL3_Init(window);
}

void Editor::Update(float dt)
{
    ImGui_ImplSdlGL3_NewFrame(Window);
    {
        ImGui::Text("Hello, world!");
        ImGui::Image((void*)(ResourceManager::Textures["PikaSprite"].ID),ImVec2(ResourceManager::Textures["PikaSprite"].Width, ResourceManager::Textures["PikaSprite"].Height), ImVec2(0,0));
        ImGui::Image((void*)GameTextureID,ImVec2(Width/2,Height/2), ImVec2(0,0));
    }
}

void Editor::Render()
{
    glViewport(0, 0, Width, Height);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(162.0f/255.0f, 162.0f/255.0f, 162.0f/255.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
}

void Editor::SetGameView(GLuint textureID)
{
    GameTextureID = textureID;
}
