#version 330 core
layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;
uniform vec4 spriteFrame;
uniform int facing;

void main()
{
    if(facing == 1)
    {
        TexCoords = spriteFrame.xy + vertex.zw * spriteFrame.zw;
    }
    else
    {
        TexCoords = vec2(spriteFrame.x + spriteFrame.z - vertex.z * spriteFrame.z, spriteFrame.y + vertex.w * spriteFrame.w);
    }
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
}
