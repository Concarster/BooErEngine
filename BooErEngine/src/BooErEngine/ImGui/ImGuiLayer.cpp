#include "booPCH.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "BooErEngine\Platforms\OpenGL\ImGuiGLRender.h"

//We REMOVE this
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "BooErEngine\Utils\BooApiCode.h"

#include "BooErEngine\Controller.h"

namespace boo
{

    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer")
    {
    }


    ImGuiLayer::~ImGuiLayer()
    {
    }

    void ImGuiLayer::OnAttach()
    {
        /* Setup ImGui Context Creation */
        ImGui::CreateContext();

        /* Setting BgColor */
        //ImGui::StyleColorsDark();
        //ImGui::StyleColorsLight();
        ImGui::StyleColorsClassic ();

        /* Setup back-end capabilities flags */
        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        //io.BackendPlatformName = "imgui_impl_glfw";

        //Temporary
        /* Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array. */
        io.KeyMap[ImGuiKey_Tab]           = BOO_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow]     = BOO_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow]    = BOO_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow]       = BOO_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow]     = BOO_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp]        = BOO_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown]      = BOO_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home]          = BOO_KEY_HOME;
        io.KeyMap[ImGuiKey_End]           = BOO_KEY_END;
        io.KeyMap[ImGuiKey_Insert]        = BOO_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete]        = BOO_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace]     = BOO_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space]         = BOO_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter]         = BOO_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape]        = BOO_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_A]             = BOO_KEY_A;
        io.KeyMap[ImGuiKey_C]             = BOO_KEY_C;
        io.KeyMap[ImGuiKey_V]             = BOO_KEY_V;
        io.KeyMap[ImGuiKey_X]             = BOO_KEY_X;
        io.KeyMap[ImGuiKey_Y]             = BOO_KEY_Y;
        io.KeyMap[ImGuiKey_Z]             = BOO_KEY_Z;

        /*Initiliaze ImGuiGL*/
        ImGui_ImplOpenGL3_Init("#version 420");
    }

    void ImGuiLayer::OnDetach()
    {
    }

    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO& io = ImGui::GetIO();
        Controller& control = Controller::GetInstance();
        io.DisplaySize = ImVec2((float)control.GetWindow().GetWidth(), (float)control.GetWindow().GetHeight());

        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event & event)
    {
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<MouseButtonPressedEvent>(BOO_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));

        dispatcher.Dispatch<MouseButtonReleasedEvent>(BOO_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));

        dispatcher.Dispatch<MouseMovedEvent>(BOO_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));

        dispatcher.Dispatch<MouseScrolledEvent>(BOO_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));

        dispatcher.Dispatch<KeyPressedEvent>(BOO_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));

        dispatcher.Dispatch<KeyReleasedEvent>(BOO_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));

        dispatcher.Dispatch<KeyTypedEvent>(BOO_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));

        dispatcher.Dispatch<WindowResizeEvent>(BOO_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
    }

    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.MouseDown[event.GetMouseButton()] = true;

        return false;
    }

    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.MouseDown[event.GetMouseButton()] = false;

        return false;
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.MousePos = ImVec2(event.GetX(), event.GetY());

        return false;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.MouseWheelH += event.GetXOffset();
        io.MouseWheel += event.GetYOffset();

        return false;
    }

    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.KeysDown[event.GetKeyCode()] = true;

        io.KeyCtrl = io.KeysDown[BOO_KEY_LEFT_CONTROL] || io.KeysDown[BOO_KEY_RIGHT_CONTROL];
        
        io.KeyShift = io.KeysDown[BOO_KEY_LEFT_SHIFT] || io.KeysDown[BOO_KEY_RIGHT_SHIFT];

        io.KeyAlt = io.KeysDown[BOO_KEY_LEFT_ALT] || io.KeysDown[BOO_KEY_RIGHT_ALT];

        /*KeySuper is the WindowsKey*/
        io.KeySuper = io.KeysDown[BOO_KEY_LEFT_SUPER] || io.KeysDown[BOO_KEY_RIGHT_SUPER];


        return false;
    }

    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.KeysDown[event.GetKeyCode()] = true;

        return false;
    }

    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        int keyCode = event.GetKeyCode();

        if (keyCode > 0 && keyCode < 0x10000)
            io.AddInputCharacter((unsigned short)keyCode);

        return false;
    }

    bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent & event)
    {
        ImGuiIO& io = ImGui::GetIO();

        io.DisplaySize = ImVec2((float)event.GetWidth(), (float)event.GetHeight());

        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

        glViewport(0, 0, event.GetWidth(), event.GetHeight());

        return false;
    }

}