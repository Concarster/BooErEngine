#include "booPCH.h"
#include "WindowsInputMgr.h"

#include "BooErEngine/Controller.h"
#include <GLFW/glfw3.h>

namespace boo
{
    ImputMgr* ImputMgr::s_Instance = new WindowsInputMgr();

    bool WindowsInputMgr::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Controller::GetInstance().GetWindow().GetNativeWindow());

        auto state = glfwGetKey(window, keycode);

        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInputMgr::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Controller::GetInstance().GetWindow().GetNativeWindow());

        auto state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInputMgr::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Controller::GetInstance().GetWindow().GetNativeWindow());

        double xpos, ypos;

        glfwGetCursorPos(window, &xpos, &ypos);

        return { (float)xpos, (float)ypos };
    }

    float WindowsInputMgr::GetMouseXImpl()
    {
        auto[x, y] = GetMousePositionImpl();

        return x;
    }

    float WindowsInputMgr::GetMouseYImpl()
    {
        auto[x, y] = GetMousePositionImpl();

        return y;
    }



}
