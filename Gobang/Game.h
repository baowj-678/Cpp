#pragma once
#include "Point.h"
#include "Player.h"
#include "Game.h"


class Game
{
public:
	Game();
	~Game();

private:
	Player player1;
	Player player2;

private:
	void putChessman(Point&p, Player&player);
};

