#include "Game.h"


Game::Game(const InitData& init)
	: IScene{ init }
{
	E.initialize(&P);
}


void Game::update()
{
	E.update(&P);
	P.update();
}


void Game::draw()
{

}
