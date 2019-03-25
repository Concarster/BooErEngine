#pragma once
#include "Def.h"

namespace boo
{

    class BOO_API Controller
    {
    private:
        bool m_Closed;

    public:
        Controller();
        virtual ~Controller();

        void Init();
        void Begin();
    };

    Controller* Generate();

}