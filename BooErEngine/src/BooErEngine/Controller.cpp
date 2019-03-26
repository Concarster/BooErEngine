#include "booPCH.h"
#include "Controller.h"


namespace boo
{
    Controller::Controller()
        :m_Closed(false)
    {

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

        }
    }
}