#pragma once
#include <Siv3D.hpp>


// シーンの名前
enum class State
{
	Game
};



// 共有データ
struct GameData
{

};


using App = SceneManager<State, GameData>;
