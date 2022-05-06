#pragma once
#include "Common.h"


class Player;

class Enemy
{
private:
	Player* player;

public:
	Enemy();
	~Enemy() = default;

	Texture texture;	// 画像
	Circle coll;		// 当たり判定
	Circle atkfield;	// 攻撃範囲
	Vec2 pos;			// 位置
	Vec2 playerPos;		// プレイヤーの位置
	Circle playerColl;	// プレイヤーの当たり判定
	double dtoP = 1;	// プレイヤーまでの距離
	double vel;			// 移動速度
	int32 hp = 0;		// HP
	int32 atk = 0;		// 攻撃力
	int32 def = 0;		// 防御力
	bool isDead = false;	// 死亡判定フラグ

	Vec2 inipos;
	Array<Enemy> enemies;


	void update(Player* P);
	void draw();

	void initialize(Player* P);
	void spawn();
	void move();
	void kill();
};
