#include "Interface.h"


Enemy::Enemy()
{
	hp = 1000;
	atk = 50;
	def = 50;
	vel = 1.5;
	texture = Texture{ U"🦁"_emoji }, TextureDesc::Mipped;
}


void Enemy::initialize(Player* P)
{
	playerColl = P->coll;
	playerPos = P->pos;
}


void Enemy::spawn()
{
	if (MouseL.down())
	{
		pos = Cursor::Pos();
		inipos = Cursor::Pos();
		dtoP = hypot(abs(playerPos.x - inipos.x), abs(playerPos.y - inipos.y));
		coll = Circle(pos, 20);
		enemies.push_back(*this);
	}
}


void Enemy::move()
{
	for (auto& enemy : enemies)
	{
		enemy.pos += enemy.vel * (playerPos - enemy.inipos) / enemy.dtoP;

		enemy.coll = Circle(enemy.pos, 20);
		if (enemy.coll.intersects(playerColl))
		{
			enemy.hp -= 200;
			enemy.pos -= Random(120,150) * (playerPos - enemy.inipos) / enemy.dtoP;
			if (enemy.hp <= 0) { enemy.isDead = true; }
		}
	}
}


void Enemy::draw()
{
	for (const auto& enemy : enemies)
	{
		enemy.texture.scaled(0.5).drawAt(enemy.pos);
		enemy.coll.draw(AlphaF(1));
	}
}


void Enemy::kill()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].isDead)
		{
			enemies.remove_at(i);
		}
	}
}


void Enemy::update(Player* P)
{
	spawn();
	draw();
	move();
	kill();
}
