#pragma once
#include "raylib.h"

namespace NeoMigration
{
	struct Obstacle
	{
		Vector2 pos;
		Vector2 initPos;
		int height;
		int width;
		float speed;
	};

	Obstacle initObstacle(Obstacle& obstacle);
	Obstacle resetObstacle(Obstacle& obstacle);
	Obstacle updateObstacle(Obstacle& obstacle);
	void drawObstacle(Obstacle obstacle);
}