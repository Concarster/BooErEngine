#include "booPCH.h"
#include "BooErGame.h"
#include "LayerList.h"

BooErGame::BooErGame()
{
    PushLayer(new TextLayer());
    PushLayer(new ImgLayer());
    PushLayer(new GuiLayer());
 
}

BooErGame::~BooErGame()
{
}

boo::Controller* boo::Generate()
{
    return new BooErGame();
}
