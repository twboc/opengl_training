#version 430

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_textcoord;

out vec4 fs_color;

void test()
{
    fs_color = vec4(vs_color, 1.f);
}