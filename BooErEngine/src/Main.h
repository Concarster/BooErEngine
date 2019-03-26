#pragma once
#include "BooErEngine\Controller.h"

#include <iostream>

extern boo::Controller* boo::Generate();

#ifdef BOO_WINDOW

int main(int argc, char** argv)
{
    boo::Log::Init();
    BOO_ENGINE_INFO(" Welcome To BooEr Engine!");
    BOO_ENGINE_WARN("Initializing Engine Logger!");
    BOO_ENGINE_TRACE("Engine Logger Initialized!");
    BOO_CLIENT_WARN("Initializing Client Logger!");
    BOO_CLIENT_TRACE("Client Logger Initialized!");

    auto Game = boo::Generate();
    Game->Begin();
    delete Game;
}

#endif // BOO_WINDOW


