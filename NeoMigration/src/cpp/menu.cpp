#include "menu.h"
#include "player.h"
#include "obstacle.h"

namespace NeoMigration
{
	Player player;
	Obstacle obst1;
	Menu menu = Main;

	

	void runGame()
	{
		int screenWidth = 800;
		int screenHeight = 600;
		initPlayer(player);
		initObstacle(obst1);
		InitWindow(screenWidth, screenHeight, "Neo Migration");

		while (!WindowShouldClose())
		{
			ClearBackground(BLACK);
			gameLoop();
		}
		CloseWindow();
	}
	void gameLoop()
	{
		updatePlayer(player);
		updateObstacle(obst1);
	}
}