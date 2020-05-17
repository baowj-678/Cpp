#pragma once

enum PlayerType
{
	human = 1,
	robot = 2
};

enum ChessmanType
{
	White = 0,
	Black = 1
};

class Player
{
public:
	Player();
	Player(PlayerType player, ChessmanType chessman);
	~Player();

private:
	//玩家类型：机器人/人类
	PlayerType player;
	//得分
	int score;
	//所执棋子的颜色
	ChessmanType chessman;

public:
	int getScore();
	int addScore();
};
