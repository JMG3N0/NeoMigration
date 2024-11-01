#include"obstacle.h"

namespace NeoMigration
{
	

	Obstacle initObstacle(Obstacle& obstacle)
	{
		int screenWidth = 800;
		int screenHeight = 600;
		obstacle.speed = 0.0f;
		obstacle.pos.x = static_cast<float>(screenWidth);
		obstacle.pos.y = static_cast<float>(screenHeight / 2);
		obstacle.width = 40;
		obstacle.height = 60;

		return obstacle;
	}

	Obstacle resetObstacle(Obstacle& obstacle)
	{
		int screenWidth = 800;
		int screenHeight = 600;
		obstacle.speed = 0.0f;
		obstacle.pos.x = static_cast<float>(screenWidth);
		obstacle.pos.y = static_cast<float>(screenHeight / 2);

		return obstacle;
	}

	Obstacle updateObstacle(Obstacle& obstacle)
	{
		drawObstacle(obstacle);

		obstacle.pos.x -= obstacle.speed * GetFrameTime();

		obstacle.speed += 5.0f * GetFrameTime();

		if (obstacle.pos.x <= 0)
		{
			resetObstacle(obstacle);
		}

		return obstacle;
	}

	void drawObstacle(Obstacle obstacle)
	{
		DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), obstacle.width, obstacle.height, BLUE);
	}
}