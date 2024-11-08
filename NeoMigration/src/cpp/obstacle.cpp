#include"obstacle.h"

namespace NeoMigration
{
	

	Obstacle initObstacle(Obstacle& obstacle)
	{
		int screenWidth = 800;
		int screenHeight = 600;
		obstacle.speed = 0.0f;
		obstacle.speedCap = 600.f;
		obstacle.pos.x = static_cast<float>(screenWidth);
		obstacle.initPos.x = obstacle.pos.x;
		obstacle.pos.y = static_cast<float>((screenHeight / 2) +50);
		obstacle.initPos.y = obstacle.pos.y;
		obstacle.width = 60;
		obstacle.height = screenWidth;

		return obstacle;
	}

	Obstacle resetObstacle(Obstacle& obstacle, bool resetSpeed)
	{
		if (resetSpeed == true)
		{
			obstacle.speed = 0.0f;
		}
		
		obstacle.pos.x = obstacle.initPos.x;
		obstacle.pos.y = obstacle.initPos.y;

		return obstacle;
	}

	Obstacle updateObstacle(Obstacle& obstacle)
	{
		drawObstacle(obstacle);


		obstacle.pos.x -= obstacle.speed * GetFrameTime();

		if (obstacle.speed < obstacle.speedCap)
		{

			obstacle.speed += 50.0f * GetFrameTime();
		}

		if (obstacle.speed >= obstacle.speedCap)
		{
			obstacle.speed = obstacle.speedCap;
		}
		

		if (obstacle.pos.x <= 0)
		{
			resetObstacle(obstacle, false);
		}

		return obstacle;
	}

	void drawObstacle(Obstacle obstacle)
	{
		if (obstacle.speed >= obstacle.speedCap)
		{
			DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), obstacle.width, obstacle.height, RED);
		}
		else
		{
			DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), obstacle.width, obstacle.height, BLUE);
		}
		
	}
}