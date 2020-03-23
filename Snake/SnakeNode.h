#ifndef _SNAKE_NODE_
#define _SNAKE_NODE_
#include "Position.h"
#define Y0	200
#define X0	200
#define TIME_BETWEEN_TWO_MOVEING	100
struct SnakeNode;
struct GameInfo;
typedef struct SnakeNode* head;
typedef struct SnakeNode* tail;
typedef struct SnakeNode* snake;
typedef struct GameInfo* game;
typedef struct SnakeNode* poisonousWeeds;
typedef struct SnakeNode* booms;
typedef struct SnakeNode* foods;
typedef struct SnakeNode* smartWeeds;//

struct SnakeNode
{
	Ptr_position posi;
	struct SnakeNode* next;
	struct SnakeNode* previous;
};


struct GameInfo
{
	//Current length
	int length;
	//Current score
	int score;
	//Current direction
	Ptr_direction direc;
	//weeds head
	poisonousWeeds Weeds;
	//weeds length
	int weeds;
	//foods head
	foods Foods;
	//foods length
	int food;
	//booms head
	booms Booms;
	//booms length
	int boom;
	//time gap
	int time;
	//snake head point
	snake head;
	//snake tail point
	snake tail;
	//is runing
	int is_on;
	//difficulty choosing
	int difficulty;
	//scene choosing
	int scene;
};

game Begin(int difficulty, int scene);
game CreateGame();
//蛇死亡并保存得分
void Die(game Game);
void Grow(game Game);
void Move(game Game, Ptr_direction d);
void Move(game Game);
void SetDirect(game Game, Ptr_direction d);
void SetScoreAndTime(game Game);
snake SnakeInit();
poisonousWeeds PoisonousWeedsInit(int n);
booms BoomsInit(int n);
foods FoodsInit(int n);
smartWeeds SmartWeedsInit(int n);
//return the poisition of food
foods CheckFoods(Ptr_position p, foods Foods);
//
poisonousWeeds CheckWeeds(Ptr_position p, poisonousWeeds Weeds);
booms CheckBooms(Ptr_position p, booms Booms);
int CheckWall(Ptr_position p);
int SplitHalf(game Game);
void Set_BorderLines(game Game);
int changeFoods(game Game);
int changeWeeds(game Game);
int changeBooms(game Game);
#endif // !_SNAKE_NODE_

