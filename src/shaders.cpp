#include "libs.h"

GLuint load_shader(const char* path)
{
    char info_log[512];
    GLint success;

    std::string temp = "";
    std::string src = "";
    std::ifstream in_file;

    in_file.open(path);

    if(in_file.is_open())
    {
        while(std::getline(in_file, temp))
        {
            src += temp + "\n";
        }
    }
    else
    {
        std::cout << "ERROR: Could not open shaderfile " + *path << std::endl;
    }

    in_file.close();

    GLuint shader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* shader_src = src.c_str();
    glShaderSource(shader, 1, &shader_src, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        std::cout << "ERROR: Could not compile shaderfile " + *path << std::endl;
        std::cout << info_log << std::endl;
    }
    return shader;

}

bool load_shaders(GLuint &program)
{

    char info_log[512];
    GLint success;

    std::string temp = "";
    std::string src = "";
    std::ifstream in_file;

    const char* vertex_core_path = "./shaders/vertex_core.glsl";
    const char* fragment_core_path = "./shaders/fragment_core.glsl";

    GLuint vertex = load_shader(vertex_core_path);
    GLuint fragment = load_shader(fragment_core_path);

    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program, 512, NULL, info_log);
        std::cout << "ERROR: Shaders could not link" << std::endl;
        std::cout << info_log << std::endl;

        glGetShaderInfoLog(vertex, 512, NULL, info_log);
        std::cout << "ERROR: Shaders could not link" << std::endl;
        std::cout << info_log << std::endl;

        glGetShaderInfoLog(fragment, 512, NULL, info_log);
        std::cout << "ERROR: Shaders could not link" << std::endl;
        std::cout << info_log << std::endl;
    }

    // delete shaders
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    //delete progran
    glUseProgram(0);

    return true;
}
