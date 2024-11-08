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
		float speedCap;
	};

	Obstacle initObstacle(Obstacle& obstacle);
	Obstacle resetObstacle(Obstacle& obstacle, bool resetSpeed);
	Obstacle updateObstacle(Obstacle& obstacle);
	void drawObstacle(Obstacle obstacle);
}