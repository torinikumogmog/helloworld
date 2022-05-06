#pragma once
#include "Common.h"
#include "Interface.h"


class Game : public App::Scene
{
private:
	Enemy E;
	Player P;

public:

	Game(const InitData& init);


	void update();
	void draw();
};
