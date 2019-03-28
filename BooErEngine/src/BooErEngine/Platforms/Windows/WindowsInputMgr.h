#pragma once
#include "BooErEngine\ImputMgr.h"

namespace boo
{
    class WindowsInputMgr : public ImputMgr
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonPressedImpl(int button) override;

        virtual std::pair<float, float> GetMousePositionImpl() override;

        virtual float GetMouseXImpl() override;

        virtual float GetMouseYImpl() override;
    };

}

