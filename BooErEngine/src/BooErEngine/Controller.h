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

        /* uqPtr Platform Indepedent */
        std::unique_ptr<Window> m_Window;

    public:
        Controller();
        virtual ~Controller();

        void Init();

        void Begin();

        void OnEvent(Event& onEvent);

    private:
        bool OnWindowClosed(WindowCloseEvent& closeEvent);
    };

    Controller* Generate();
}