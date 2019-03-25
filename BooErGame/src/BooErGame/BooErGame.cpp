#include "BooErGame.h"

BooErGame::BooErGame()
{
 
}

BooErGame::~BooErGame()
{
}

boo::Controller* boo::Generate()
{
    return new BooErGame();
}
