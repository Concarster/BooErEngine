#pragma once
#include "BooErEngine\Controller.h"

#include <iostream>

extern boo::Controller* boo::Generate();

#ifdef BOO_WINDOW

int main(int argc, char** argv)
{
    std::cout << "\n  Welcome To BooEr Engine! \n" << std::endl;

    auto Game = boo::Generate();
    Game->Begin();
    delete Game;
}

#endif // BOO_WINDOW


