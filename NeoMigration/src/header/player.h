#pragma once
#include "raylib.h"

namespace NeoMigration
{
	struct Player
	{
		Vector2 pos;
		int height;
		int width;
		int score;
		float speed;
		float gravity;
	};

	Player initPlayer(Player& player);
	Player resetPlayer(Player& player);
	Player updatePlayer(Player& player);
	void drawPlayer(Player player);
}
