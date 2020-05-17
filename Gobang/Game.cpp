#include "Game.h"


Game::Game()
{
	this->player1 = Player(PlayerType::human, ChessmanType::Black);
	this->player2 = Player(PlayerType::human, ChessmanType::Black);
}

Game::~Game()
{
}