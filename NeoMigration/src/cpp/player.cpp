#include "player.h"

namespace NeoMigration
{
	
	

	Player initPlayer(Player& player)
	{
		int screenHeight = 600;
		player.gravity = 9.8f;
		player.score = 0;
		player.speed = 0.0f;
		player.pos.x = 50.0f;
		player.pos.y = static_cast<float>((screenHeight / 2));
		player.height = 20;
		player.width = 20;
			
		
		return player;
	}

	Player resetPlayer(Player& player)
	{
		int screenHeight = 600;
		player.score = 0;
		player.speed = 0.0f;
		player.pos.y = static_cast<float>((screenHeight / 2));

		return player;
	}


	Player updatePlayer(Player& player)
	{
		drawPlayer(player);
		
		if (IsKeyPressed(KEY_W))
		{
			player.pos.y -= 20.0f * GetFrameTime();
		}
		return player;
	}

	void drawPlayer(Player player)
	{
		DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), player.width, player.height, RED);
	}
}