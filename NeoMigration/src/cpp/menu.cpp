#include "menu.h"
#include "player.h"
#include "obstacle.h"

namespace NeoMigration
{
	Player player;
	Obstacle obst1;
	Menu menu = Main;

	

	

	bool checkCollisions(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h)
	{
		if (r1x + r1w >= r2x &&    // r1 right edge past r2 left
			r1x <= r2x + r2w &&    // r1 left edge past r2 right
			r1y + r1h >= r2y &&    // r1 top edge past r2 bottom
			r1y <= r2y + r2h) {    // r1 bottom edge past r2 top
			return true;
		}
		return false;
	}

	void gameLoop()
	{
		updatePlayer(player);
		updateObstacle(obst1);
		if (checkCollisions(player.pos.x, player.pos.y, static_cast<float>(player.width), static_cast<float>(player.height), obst1.pos.x, obst1.pos.y, static_cast<float>(obst1.width), static_cast<float>(obst1.height)))
		{
			resetPlayer(player);
			resetObstacle(obst1);
		}
	}

	void gameVersion()
	{
		DrawText("0.1", 750, 550, 20, WHITE);
	}

	void runGame()
	{
		int screenWidth = 800;
		int screenHeight = 600;
		initPlayer(player);
		initObstacle(obst1);
		InitWindow(screenWidth, screenHeight, "Neo Migration");

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(BLACK);
			gameLoop();
			gameVersion();
			EndDrawing();
		}
		CloseWindow();
	}
	
}