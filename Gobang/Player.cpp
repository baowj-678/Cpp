#include "Player.h"

Player::Player()
{
}

Player::Player(PlayerType player, ChessmanType chessman)
{
	this->player = player;
	this->score = 0;
	this->chessman = chessman;
}

Player::~Player()
{
}
