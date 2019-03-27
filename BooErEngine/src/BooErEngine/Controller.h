#pragma once
#include "Def.h"

#include "Window.h"
#include "IncEngine.h"

namespace boo
{
    class BOO_API Controller
    {
    private:
        /* uqPtr Platform Indepedent */
        std::unique_ptr<Window> m_Window;

        bool m_Running;

        LayerSatck m_LayerStack;

    public:
        Controller();
        virtual ~Controller();

        void Init();

        void Begin();

        void OnEvent(Event& onEvent);

        void PushLayer(Layer* layer);

        void PushOverLay(Layer* overlay);

    private:
        bool OnWindowClosed(WindowCloseEvent& closeEvent);
    };

    Controller* Generate();
}