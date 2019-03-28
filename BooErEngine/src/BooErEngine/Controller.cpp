#include "booPCH.h"
#include "Controller.h"

#include "ImputMgr.h"
#include <glad\glad.h>

namespace boo
{
#define BIND_EVENT_FN(x) std::bind(&Controller::x, this, std::placeholders::_1)

    Controller* Controller::s_Instance = nullptr;

    Controller::Controller()
        :m_Running(true)
    {
        BOO_ENGINE_ASSERT(!s_Instance, "Instance Controller already exist!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));
    }

    Controller::~Controller()
    {

    }

    void Controller::OnEvent(Event & onEvent)
    {
        EventDispatcher distpatcher(onEvent);
        distpatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

        BOO_ENGINE_TRACE("{0}", onEvent);

        for (auto iterate = m_LayerStack.end(); iterate != m_LayerStack.begin(); )
        {
            (*--iterate)->OnEvent(onEvent);
            if (onEvent.Handled)
                break;
        }

    }

    void Controller::PushLayer(Layer * layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Controller::PushOverLay(Layer * overlay)
    {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    void Controller::Init()
    {

    }

    void Controller::Begin()
    {
        boo::WindowResizeEvent booEvent(1440, 900);
       
        if (booEvent.IsInCategory(EventCategoryApp))
        {
            BOO_ENGINE_TRACE(booEvent);
        }

        if (booEvent.IsInCategory(EventCategoryInput))
        {
            BOO_ENGINE_TRACE(booEvent);
        }


        while (m_Running)
        {
            glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            /*std::cout << m_Window->GetWidth() << std::endl;
            std::cout << m_Window->GetHeight() << std::endl;*/

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            auto[x, y] = ImputMgr::GetMousePosition();
            BOO_ENGINE_TRACE("{0}, {1}", x, y);

            m_Window->OnUpdate();
            
        }
           
    }

    bool Controller::OnWindowClosed(WindowCloseEvent & closeEvent)
    {
        m_Running = false;
        return true;
    }
   
}