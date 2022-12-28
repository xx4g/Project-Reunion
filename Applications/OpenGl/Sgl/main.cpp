#include "StdAfx.h"
class ShaderCompiler
{
public:
    static int ICompileShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
};
class CameraController
{
public:
    void start();
    void Update();
    glm::mat4 GetViewMatrix() const;
private:
};
glm::mat4 CameraController::GetViewMatrix() const
{
    return glm::lookAt(glm::vec3(0, 0, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}

void CameraController::start()
{
}
void CameraController::Update()
{
}
//global data
HWND global_hwnd = 0;
WPARAM global_wparam = 0;
HDC s_DC = 0;
HGLRC s_RC = 0;
CameraController cameraController = {};
bool initialized = false;
unsigned int shaderProgram = {};
GLuint triangleVAO = {}, triangleVBO = {}, VertexArrayID = {};
std::vector<float>triangleVertices = {
    0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
    0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
};
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void Render(const HWND& hWnd, bool& initialized, GLuint& VertexArrayID, unsigned int& shaderProgram, GLuint& triangleVAO, GLuint& triangleVBO, std::vector<float>& triangleVertices, CameraController& cameraController);
class Window
{
public:
    Window(HINSTANCE hInstance, int nCmdShow)
    {
        WNDCLASSEX wcex = {};
        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WndProc;
        wcex.hInstance = hInstance;
        wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszClassName = L"MyWindowClass";
        RegisterClassEx(&wcex);
        hWnd_ = CreateWindow(L"MyWindowClass", L"OpenGl", WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, nullptr, nullptr, hInstance, nullptr);
        if (hWnd_)
        {



            ShowWindow(hWnd_, nCmdShow);
            UpdateWindow(hWnd_);
        }
    }
    ~Window()
    {
        DestroyWindow(hWnd_);
    }

    operator HWND() const
    {
        return hWnd_;
    }

private:
    HWND hWnd_;
};
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {   if (hWnd > 0)
        {
        if (WglFunctionLoader::GetDcRc(hWnd, &s_DC, &s_RC))
        {
            WglFunctionLoader::GetGlFunctionPtrs();
                cameraController.start();
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                glEnable(GL_DEPTH_TEST);
                glDepthFunc(GL_LESS);
        }
        }
        break;
    }
    case WM_PAINT:
    {
        Render(hWnd, initialized, VertexArrayID, shaderProgram, triangleVAO, triangleVBO, triangleVertices, cameraController);
        break;
    }
    case WM_TIMER:
        if (hWnd > 0)
        {
            global_wparam = wParam;
            global_hwnd = hWnd;
            SendMessage(hWnd, WM_PAINT, NULL, NULL);
        }
        break;
    case WM_SIZE:
    {
        int width = LOWORD(lParam);
        int height = HIWORD(lParam);
        glViewport(0, 0, width, height);
        break;
    }
    case WM_DESTROY:
    {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(wglGetCurrentContext());
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void Render(const HWND& hWnd, bool& initialized, GLuint& VertexArrayID, unsigned int& shaderProgram, GLuint& triangleVAO, GLuint& triangleVBO, std::vector<float>& triangleVertices, CameraController& cameraController)
{
    if (hWnd > 0)
    {
        if (!initialized)
        {
            glGenVertexArrays(1, &VertexArrayID);
            glBindVertexArray(VertexArrayID);
            const char* vertexShaderSource = "#version 330 core\n"
                "layout (location = 0) in vec3 aPos;\n"
                "uniform mat4 MVP;\n"
                "void main()\n"
                "{\n"
                "    gl_Position = MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                "}\0";
            const char* fragmentShaderSource = "#version 330 core\n"
                "out vec4 FragColor;\n"
                "void main()\n"
                "{\n"
                "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                "}\0";
            shaderProgram = ShaderCompiler::ICompileShaderProgram(vertexShaderSource, fragmentShaderSource);
            glGenVertexArrays(1, &triangleVAO);
            glBindVertexArray(triangleVAO);
            glGenBuffers(1, &triangleVBO);
            glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
            glBufferData(GL_ARRAY_BUFFER, triangleVertices.size() * sizeof(float), triangleVertices.data(), GL_STATIC_DRAW);

            initialized = true;
        }
        else
        {


            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            RECT ClientRect = {};

            GetClientRect(hWnd, &ClientRect);

            int width = ClientRect.right - ClientRect.left;

            int height = ClientRect.bottom - ClientRect.top;

            //Resize the screen here before we clear the screen
            if (height == 0)
            {
                height = 1;
            }
            if (width == 0)
            {
                width = 1;
            }
            glViewport(ClientRect.left, ClientRect.top, width, height);
            // Use our shader
            glUseProgram(shaderProgram);
            cameraController.Update();
            glm::mat4 model = glm::mat4(1.0f);
            glm::mat4 view = cameraController.GetViewMatrix();
            glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.001f, 1000.0f);
            glm::mat4 MVP = projection * view * model; // Remember, matrix multiplication is the other way around 
            GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
            glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
            glVertexAttribPointer(
                0,
                3,
                GL_FLOAT,
                GL_FALSE,
                0,
                (void*)0
            );
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glDisableVertexAttribArray(0);
        }

        SwapBuffers(GetDC(hWnd));
    }
}
int main(int argc, char* argv[])
{
    Window window(GetModuleHandle(NULL), SW_SHOW);
    while (true)
    {
        MSG msg;
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Sleep(50);
    }
    return 0;
}
int ShaderCompiler::ICompileShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
{
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return 0;
    }
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        return 0;
    }
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        return 0;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}