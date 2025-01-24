#pragma once
#include "Reflector.h"
#include "Ball.h"

class Game {
public:
	Reflector left;
	Reflector right;
	Ball ball;
private:

public:
	Game();
	void CheckKeyPressed();
	bool CheckCollisions(int side);
	void Draw();
	void SpawnBall();
private:

};