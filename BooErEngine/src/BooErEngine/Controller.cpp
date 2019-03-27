#include "booPCH.h"
#include "Controller.h"

#include <GLFW\glfw3.h>

namespace boo
{
    Controller::Controller()
        :m_Closed(false),
        m_Running(true)
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Controller::~Controller()
    {

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

        while (!m_Closed)
        {
            while (m_Running)
            {
                glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                    
                m_Window->OnUpdate();
            }
        }
    }
}