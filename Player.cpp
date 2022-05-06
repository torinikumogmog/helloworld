#include "Interface.h"

Player::Player()
{
	texture = Texture{ U"🏯"_emoji };
	pos = Scene::Center();
	coll = Circle(pos, 40);
	hp = 10000;
}


void Player::draw()
{
	texture.drawAt(pos);
	coll.draw(AlphaF(0));
}


void Player::update()
{
	draw();
}
