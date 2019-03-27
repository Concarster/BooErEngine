#pragma once
#include "Def.h"
#include "IncEngine.h"

#include "Window.h"

namespace boo
{
    class BOO_API Controller
    {
    private:
        bool m_Closed;
        bool m_Running;

        /*UPtr Platform Indepedent*/
        std::unique_ptr<Window> m_Window;

    public:
        Controller();
        virtual ~Controller();

        void Init();
        void Begin();
    };

    Controller* Generate();
}