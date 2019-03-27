#include "booPCH.h"
#include "Controller.h"

#include <GLFW\glfw3.h>

namespace boo
{
#define BIND_EVENT_FN(x) std::bind(&Controller::x, this, std::placeholders::_1)

    Controller::Controller()
        :m_Closed(false),
        m_Running(true)
    {
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

        std::cout << m_Window->GetWidth() << std::endl;
        std::cout << m_Window->GetHeight() << std::endl;


        while (m_Running)
        {
            glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Window->OnUpdate();
            
        }
           
       
    }

    bool Controller::OnWindowClosed(WindowCloseEvent & closeEvent)
    {
        m_Running = false;
        return true;
    }
   
}