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
#include "GameObject.hpp"

Editor::Editor(GLuint width, GLuint height)
:
Width(width),
Height(height)
{
    MoveSpeed = nullptr;
}

void Editor::Init(SDL_Window* window)
{
    Window = window;
    ImGui_ImplSdlGL3_Init(window);
    MoveSpeed = &GameObject::GameObjectList[0]->MoveSpeed;
}

void Editor::Update(float dt)
{
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoResize;
    bool Show = true;
    
    ImGui_ImplSdlGL3_NewFrame(Window);
    {
        ImGui::Begin("Game",&Show, window_flags);
        ImGui::SetWindowPos(ImVec2(0.0f, 0.0f));
        ImGui::SetWindowSize(ImVec2(Width/2+20.0f,Height/2+40.0f),ImGuiSetCond_Once);
        //ImGui::Text("Hello, world!");
        ImGui::Image((void*)GameTextureID,ImVec2(Width/2,Height/2), ImVec2(0,1), ImVec2(1,0));
        ImGui::End();
    }
    {
        ImGui::Begin("Console",&Show, window_flags);
        ImGui::SetWindowPos(ImVec2(0.0f, Height/2 + 42.0f));
        ImGui::SetWindowSize(ImVec2(Width,Height/2 - 42.0f),ImGuiSetCond_Once);
        ImGui::Text("Hello World");
        ImGui::End();
    }
    {
        ImGui::Begin("Inspector",&Show, window_flags);
        ImGui::SetWindowPos(ImVec2(Width/2+22.0f, 0));
        ImGui::SetWindowSize(ImVec2(Width/2-22.0f,Height/2 + 40.0f),ImGuiSetCond_Once);
        if(MoveSpeed)
        {
            
            //ImGui::InputFloat("Move Speed", MoveSpeed);
            ImGui::DragFloat("Move Speed", MoveSpeed, 0.5f);
            ImGui::Text("Current Move Speed is %f", *MoveSpeed);
        }
        ImGui::End();
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
