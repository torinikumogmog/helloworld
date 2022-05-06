#pragma once
#include "Common.h"


class Player 
{
public:
	Texture texture;	// スプライト
	Circle coll;	// 当たり判定
	Circle atkfield;	// 攻撃範囲
	Vec2 pos;	// 位置
	double vel;	// 移動速度
	int32 hp = 0; // HP
	int32 atk = 0; // 攻撃力
	int32 def = 0; // 防御力
	double time;
	bool isAlive = true;	// 死亡判定フラグ


	Player();
	~Player() = default;

	void update();
	void draw();
	void kill() { if (hp <= 0) { isAlive = false; } }

	Vec2 getPos() { return pos; };
};
