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
#include "Context.hpp"
#include "Game.hpp"
#include "SpriteEditor.hpp"
#include "ResourceManager.hpp"
#include "json.hpp"
#include "StringUtil.hpp"
#include <iostream>
#include "File.hpp"

Editor::Editor(Context* context,GLuint width, GLuint height)
:
Object(context),
Width(width),
Height(height)
{
    context->EditorInstance = this;
}

void Editor::Init(SDL_Window* window)
{
    ResourceManager::LoadTexture("Resource/Character.png", "Character");
    Window = window;
    ImGui_ImplSdlGL3_Init(window);
}

void Editor::Update(float dt)
{
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoResize;
    bool Show = true;
    
    ImGui_ImplSdlGL3_NewFrame(Window);
    {
        ImGui::Begin("Game",&Show, window_flags);
        ImGui::SetWindowPos(ImVec2(0.0f, 0.0f));
        ImGui::SetWindowSize(ImVec2(800+20.0f,600+40.0f),ImGuiSetCond_Once);
        ImGui::Image((void*)(EngineContext->GameInstance->GameSurface->Texture.ID),ImVec2(800,600), ImVec2(0,1), ImVec2(1,0));
        ImGui::End();
    }
    {
        static int rowCount = 0;
        static int columnCount = 0;
        static int gridWidth = 0;
        static int gridHeight = 0;
        static int imageCount = 0;
        static char* imageName = new char[50];
        auto texture = ResourceManager::Textures["Character"];
        ImGui::Begin("SpriteEditor",&Show, 0);
        ImGui::Image((void*)(texture.ID),
                     ImVec2(texture.Width,texture.Height),
                     ImVec2(0,0),
                     ImVec2(1,1),
                     ImVec4(1.0, 1.0, 1.0, 1.0),
                     ImVec4(1.0, 1.0, 1.0, 1.0));
        
        ImGui::InputInt("RowCount", &rowCount);
        ImGui::InputInt("ColumnCount", &columnCount);
        ImGui::InputInt("GridWidth", &gridWidth);
        ImGui::InputInt("GridHeight", &gridHeight);
        ImGui::InputInt("ImageCount", &imageCount);
        ImGui::InputText("ImageName", imageName, 50);
        if(gridWidth > 0 && gridHeight > 0 && texture.Width > 0 && texture.Height > 0)
        {
            int count = 0;
            for(int y = 0; y < rowCount; y ++)
            {
                for(int x = 0; x < columnCount; x++)
                {
                    count+=1;
                    if(count > imageCount)
                    {
                        break;
                    }
                    float singleTexWidth = (float)gridWidth/texture.Width;
                    float singleTexHeight = (float)gridHeight/texture.Height;
                    auto leftTopPos = ImVec2((float)x * singleTexWidth, (float)y * singleTexHeight);
                    auto rightBottomPos = ImVec2((float)x * singleTexWidth + singleTexWidth, (float)y * singleTexHeight + singleTexHeight);
                    ImGui::Image((void*)(ResourceManager::Textures["Character"].ID),
                                 ImVec2(32, 32),
                                 leftTopPos,
                                 rightBottomPos,
                                 ImVec4(1.0, 1.0, 1.0, 1.0),
                                 ImVec4(1.0, 1.0, 1.0, 1.0));
                    if(x != columnCount - 1)
                    {
                        ImGui::SameLine();
                    }
                }
            }
        }
        if(ImGui::Button("Build"))
        {
            nlohmann::json j;
            j["name"] = "sheet_2";
            j["file"] = "Character.png";
            int count = 0;
            for(int y = 0; y < rowCount; y ++)
            {
                for(int x = 0; x < columnCount; x++)
                {
                    count+=1;
                    if(count > imageCount)
                    {
                        break;
                    }
                    float singleTexWidth = (float)gridWidth;
                    float singleTexHeight = (float)gridHeight;
                    auto leftTopPos = ImVec2((float)x * singleTexWidth, (float)y * singleTexHeight);
                    //auto rightBottomPos = ImVec2((float)x * singleTexWidth + singleTexWidth, (float)y * singleTexHeight + singleTexHeight);
                    j["frames"][StringUtil::Format("%s%d",imageName,count - 1)]["frame"]["w"] = gridWidth;
                    j["frames"][StringUtil::Format("%s%d",imageName,count - 1)]["frame"]["h"] = gridHeight;
                    j["frames"][StringUtil::Format("%s%d",imageName,count - 1)]["frame"]["x"] = leftTopPos.x;
                    j["frames"][StringUtil::Format("%s%d",imageName,count - 1)]["frame"]["y"] = leftTopPos.y;
                    j["frames"][StringUtil::Format("%s%d",imageName,count - 1)]["pivot"]["x"] = 0.5;
                    j["frames"][StringUtil::Format("%s%d",imageName,count - 1)]["pivot"]["y"] = 0.5;
                    if(x != columnCount - 1)
                    {
                        ImGui::SameLine();
                    }
                }
            }
            auto str = j.dump();
            File::WriteFile("/Users/knight/Documents/KnightSoulWorkSpace/KnightSoul/Resource/texture2.json", (const uint8_t*)str.c_str(), str.size());
        }
        ImGui::End();
    }
    /*
    {
        ImGui::Begin("Console",&Show, window_flags);
        ImGui::SetWindowPos(ImVec2(0.0f, Height/2 + 42.0f));
        ImGui::SetWindowSize(ImVec2(Width,Height/2 - 42.0f),ImGuiSetCond_Once);
        ImGui::Text("Hello World");
        ImGui::End();
    }
     */
    /*
    {
        ImGui::Begin("Inspector",&Show, window_flags);
        ImGui::SetWindowPos(ImVec2(Width/2+22.0f, 0));
        ImGui::SetWindowSize(ImVec2(Width/2-22.0f,Height/2 + 40.0f),ImGuiSetCond_Once);
        ImGui::End();
    }
     */
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

