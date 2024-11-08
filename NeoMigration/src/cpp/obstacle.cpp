#include"obstacle.h"

namespace NeoMigration
{
	

	Obstacle initObstacle(Obstacle& obstacle)
	{
		int screenWidth = 800;
		int screenHeight = 600;
		obstacle.speed = 0.0f;
		obstacle.pos.x = static_cast<float>(screenWidth);
		obstacle.initPos.x = obstacle.pos.x;
		obstacle.pos.y = static_cast<float>((screenHeight / 2) +50);
		obstacle.initPos.y = obstacle.pos.y;
		obstacle.width = 60;
		obstacle.height = screenWidth;

		return obstacle;
	}

	Obstacle resetObstacle(Obstacle& obstacle)
	{
		obstacle.speed = 0.0f;
		obstacle.pos.x = obstacle.initPos.x;
		obstacle.pos.y = obstacle.initPos.y;

		return obstacle;
	}

	Obstacle updateObstacle(Obstacle& obstacle)
	{
		drawObstacle(obstacle);

		obstacle.pos.x -= obstacle.speed * GetFrameTime();

		obstacle.speed += 25.0f * GetFrameTime();

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