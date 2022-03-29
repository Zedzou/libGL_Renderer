#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

namespace RD
{
    // 窗口定义
    struct GLFWWindowContainer
    {
        GLFWwindow* window;
        std::string name_;
        int width_, height_;
        GLFWWindowContainer(std::string name, 
                            int width, 
                            int height):name_(name), width_(width),height_(height)
        {
            window = glfwCreateWindow(width, height, name_.c_str(), nullptr, nullptr);
            if (window == NULL){
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
            }
        }
    };

    // 渲染器
    class MakeRenderer
    {
        public:
            MakeRenderer(std::string &name, int width, int height)
            {
                glfwInit();
                glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
                glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
                glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
                Set_Window(name, width, height);
            };

            // 析构函数
            ~MakeRenderer()
            {
                glfwTerminate();
            };

            // 窗口设置
            void Set_Window(std::string& name, int width, int height)
            {
                window_ = new RD::GLFWWindowContainer(name, width, height);
                glfwMakeContextCurrent(window_->window);
                glfwSetFramebufferSizeCallback(window_->window, framebuffer_size_callback);
                // glad准备
                if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
                    std::cout << "Failed to initialize GLAD" << std::endl;
                }  
            }

            // 获取窗口
            GLFWWindowContainer* GetWindow(){return window_;};

            // 渲染循环
            void Render_Circulate()
            {
                // 渲染循环
                while (!glfwWindowShouldClose(window_->window))
                {
                    this->processInput(window_->window);
                    glfwSwapBuffers(window_->window);
                    glfwPollEvents();
                }
            }

        private:
            GLFWWindowContainer* window_;

            void processInput(GLFWwindow *window)
            {
                if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                    glfwSetWindowShouldClose(window, true);
            };



    };
}

int main()
{
    std::string window_name = "test";
    RD::MakeRenderer* render = new RD::MakeRenderer(window_name, 800, 600);
    render->Render_Circulate();
    return 0;
}



