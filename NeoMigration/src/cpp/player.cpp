#include "player.h"

namespace NeoMigration
{
	
	

	Player initPlayer(Player& player)
	{
		int screenHeight = 600;
		player.gravity = 200.0f;
		player.score = 0;
		player.speed = 0.0f;
		player.pos.x = 50.0f;
		player.pos.y = static_cast<float>((screenHeight / 2));
		player.height = 40;
		player.width = 40;
		player.jump = 100000.0f;
		
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
		
		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
		{
			player.pos.y -= player.jump * GetFrameTime();
			if (player.pos.y <= 0)
			{
				player.pos.y = 0;
			}
			player.speed = 0.0f;
		}
		
		player.speed += player.gravity * GetFrameTime();

		player.pos.y += player.speed * GetFrameTime();

		
		return player;
	}

	void drawPlayer(Player player)
	{
		DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), player.width, player.height, RED);
	}

	
}