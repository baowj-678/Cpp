#include "Game.h"


Game::Game()
{
	this->player1 = Player(PlayerType::human, ChessmanType::Black);
	this->player2 = Player(PlayerType::human, ChessmanType::Black);
}

Game::~Game()
{
}

/**
* @brief	返回player1指针
* @param	void
* @return	player1的指针
*/
Player* Game::getPlayerOne()
{
	return (&this->player1);
}


/**
* @brief	返回player2指针
* @param	void
* @return	player2的指针
*/
Player* Game::getPlayerTwo()
{
	return (&this->player2);
}