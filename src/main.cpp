#include "./libs.h"
#include "./shaders.cpp"

void framebuffer_resize_callback(GLFWwindow* window, int fbw, int fbh)
{
    glViewport(0, 0, fbw, fbh);
};

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
};

int main(int argc, char* argv[])
{

    // std::filesystem::path cwd = std::filesystem::current_path();

    std::cout << argv[0] << std::endl;

    

    // std::cout << filesystem::current_path() << std::endl;

    //init glfw
    glfwInit();

    //create window
    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 480;
    int frameBufferWidth = 0;
    int frameBufferHeight = 0;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL - Training", NULL, NULL);
    glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);

    glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
    glViewport(0, 0, frameBufferWidth, frameBufferHeight);
    glfwMakeContextCurrent(window);

    // // inti glew need window and opengl context

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK)
    {
        glfwTerminate();
        std::cout << "ERROR: Glew not initialized!" << std::endl;
    }

    // shaders
    GLuint shaders_core_program;
    load_shaders(shaders_core_program);


    //main loop
    while(!glfwWindowShouldClose(window))
    {
        // check update input
        processInput(window);
        // update
        // DRAW
        // clear

        glClearColor(0.f, 1.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        // draw

        // END DRAW
        glfwSwapBuffers(window);
        glFlush();

    }

    //end of program
    glfwDestroyWindow(window);
    glfwTerminate();

    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(3));

    std::cout << "Finished" << std::endl;

    return 0;
}