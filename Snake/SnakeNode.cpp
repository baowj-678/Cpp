#include "SnakeNode.h"
#include "Position.h"
#include <random>
#include <malloc.h>
#include "SnakeFile.h"
#include "SnakeUI.h"

//
void Die(game Game)
{
	//保存得分
	newScore(Game->score);
	snake first = Game->head;
	snake second = first;
	//free nodes
	while (first != NULL)
	{
		second = first->next;
		free(first);
		first = second;
	}
}

game CreateGame()
{
	game Game = (game)malloc(sizeof(struct GameInfo));
	if (Game != NULL)
	{
		Game->difficulty = 1;
		Game->scene = 1;
		Game->is_on = 1;
		Game->length = 1;
		Game->score = 1;
		Game->time = TIME_BETWEEN_TWO_MOVEING;

		Game->direc = (Ptr_direction)malloc(sizeof(struct position));
		if (Game->direc != NULL)
		{
			Game->direc->X = 7;
			Game->direc->Y = 0;
		}
	}
	return Game;
}

game Begin(int difficulty, int scene)
{
	game Game = (game)malloc(sizeof(struct GameInfo));
	if (Game != NULL)
	{
		Game->difficulty = difficulty;
		Game->scene = scene;
		Game->is_on = 1;
		Game->length = 1;
		Game->score = 1;
		Game->time = TIME_BETWEEN_TWO_MOVEING;

		Game->direc = (Ptr_direction)malloc(sizeof(struct position));
		if (Game->direc != NULL)
		{
			Game->direc->X = 7;
			Game->direc->Y = 0;
		}

		Game->head = SnakeInit();
		Game->food = 1;
		Game->tail = Game->head;

		//炸弹初始化
		Game->Booms = BoomsInit(4);
		Game->boom = 4;
		//毒草初始化
		Game->Weeds = PoisonousWeedsInit(4);
		Game->weeds = 4;
		//食物初始化
		Game->Foods = FoodsInit(4);
		Game->food = 4;
	}
	return Game;
}

//Plus one Node
void Grow(game Game)
{
	snake temp = (snake)malloc(sizeof(struct SnakeNode));
	if (temp == NULL)
		return;
	temp->next = Game->head;
	//struct position direct;
	temp->posi = create(Game->head->posi, Game->direc);
	Game->head->previous = temp;
	Game->head = temp;
	Game->length++;
	//设置分数和时间间隔
	SetScoreAndTime(Game);
	//是否进入下一关
	if (Game->score / 10 + 1 > Game->difficulty)
	{
		Game->difficulty++;
		//改变毒草食物数量
		changeBooms(Game);
		changeFoods(Game);
		changeWeeds(Game);
	}
}

void SetDirect(game Game, Ptr_direction d)
{
	Copy(Game->direc, d);
}
void Move(game Game, Ptr_direction d)
{
	//set new Direction
	SetDirect(Game, d);
	//从尾节点开始更新坐标
	snake temp = Game->tail;
	while (temp != Game->head)
	{
		//将temp坐标更新为其前面的做标
		Copy(temp->posi, temp->previous->posi);
		temp = temp->previous;
	}
	add(temp->posi, Game->direc);
}

void Move(game Game)
{
	snake temp = Game->tail;
	while (temp != Game->head)
	{
		Copy(temp->posi, temp->previous->posi);
		temp = temp->previous;
	}
	add(temp->posi, Game->direc);
}

void SetScoreAndTime(game Game)
{
	//set score
	Game->score = Game->score + Game->difficulty;
	//set time
	if(Game->difficulty < 10)
		Game->time = TIME_BETWEEN_TWO_MOVEING - 4*Game->difficulty;

}

snake SnakeInit()
{
	snake ASnake = (snake)malloc(sizeof(struct SnakeNode));
	if (ASnake != NULL)
	{
		ASnake->posi = New_poi(X0, Y0);
		ASnake->next = NULL;
		ASnake->previous = NULL;
	}
	return ASnake;
}
poisonousWeeds PoisonousWeedsInit(int n)
{
	poisonousWeeds AWeeds = (poisonousWeeds)malloc(sizeof(struct SnakeNode));
	if (AWeeds != NULL)
	{
		AWeeds->next = NULL;
		AWeeds->previous = NULL;
		AWeeds->posi = New_poi(67, 89);//test
	}
	int i = 0;
	for (i = 1; i < n; i++)
	{
		poisonousWeeds temp = (poisonousWeeds)malloc(sizeof(struct SnakeNode));
		if (temp != NULL)
		{
			temp->next = AWeeds;
			AWeeds->previous = temp;
			AWeeds = temp;
			temp->previous = NULL;
			temp->posi = GenerateRandom(0, 0, 893, 693);
		}
	}
	return AWeeds;
}

booms BoomsInit(int n)
{
	booms Abooms = (booms)malloc(sizeof(struct SnakeNode));
	if (Abooms != NULL)
	{
		Abooms->next = NULL;
		Abooms->previous = NULL;
		Abooms->posi = New_poi(89, 79);//test
	}
	int i = 0;
	for (i = 1; i < n; i++)
	{
		foods temp = (foods)malloc(sizeof(struct SnakeNode));
		if (temp != NULL)
		{
			temp->next = Abooms;
			Abooms->previous = temp;
			Abooms = temp;
			temp->previous = NULL;
			temp->posi = GenerateRandom(0, 0, 893, 693);
		}
	}
	return Abooms;
}

foods FoodsInit(int n)
{
	foods AFoods = (foods)malloc(sizeof(struct SnakeNode));
	if (AFoods != NULL)
	{
		AFoods->next = NULL;
		AFoods->previous = NULL;
		AFoods->posi = New_poi(90, 12);//test
	}
	int i = 0;
	for (i = 1; i < n; i++)
	{
		foods temp = (foods)malloc(sizeof(struct SnakeNode));
		if (temp != NULL)
		{
			temp->next = AFoods;
			AFoods->previous = temp;
			AFoods = temp;
			temp->previous = NULL;
			temp->posi = GenerateRandom(0, 0, 893, 693);
		}
	}
	return AFoods;
}

foods CheckFoods(Ptr_position p, foods Foods)
{
	foods crash = NULL;
	while (Foods != NULL)
	{
		if (Is_Crash(p, Foods->posi) == 1)
		{
			crash = Foods;
			break;
		}
		Foods = Foods->next;
	}
	//更换食物位置
	if (crash != NULL)
	{
		crash->posi->X = rand() % 898;
		crash->posi->Y = rand() % 698;
	}
	return crash;
}
smartWeeds SmartWeedsInit(int n)
{
	smartWeeds ASmartWeeds = (smartWeeds)malloc(sizeof(struct SnakeNode));
	if (ASmartWeeds != NULL)
	{
		ASmartWeeds->next = NULL;
		ASmartWeeds->previous = NULL;
		ASmartWeeds->posi = New_poi(78, 56);//test

	}
	return ASmartWeeds;
}

//从尾部开始删除
int SplitHalf(game Game)
{
	int mid = Game->length / 2;
	Game->score = Game->score / 2;

	if (mid <= 0)
		return 1;

	int i;
	snake now = Game->tail;
	snake pre = now;
	for (i = 0; i < mid; i++)
	{
		now = pre;
		if (pre != NULL)
		{
			pre = pre->previous;
			pre->next = NULL;
		}
		if (now != NULL)
		{
			free(now->posi);
			free(now);
		}
	}
	Game->tail = pre;
	Game->length -= Game->length / 2;
	return 0;
}

void Set_BorderLines(game Game)
{
	int x0 = 0;
	int y0 = 0;//左上角
	int width = 500;
	int height = 300;
	int n = 3;//转折的个数


}

poisonousWeeds CheckWeeds(Ptr_position p, poisonousWeeds Weeds)
{
	poisonousWeeds crash = NULL;
	while (Weeds != NULL)
	{
		if (Is_Crash(p, Weeds->posi) == 1)
		{
			crash = Weeds;
			break;
		}
		Weeds = Weeds->next;
	}
	if (crash != NULL)
	{
		crash->posi->X = rand() % 898;
		crash->posi->Y = rand() % 700;
	}
	return crash;
}

booms CheckBooms(Ptr_position p, booms Booms)
{
	poisonousWeeds crash = NULL;
	while (Booms != NULL)
	{
		if (Is_Crash(p, Booms->posi) == 1)
		{
			crash = Booms;
			break;
		}
		Booms = Booms->next;
	}
	if (crash != NULL)
	{
		crash->posi->X = rand() % 898;
		crash->posi->Y = rand() % 700;
	}
	return crash;
}

int CheckWall(Ptr_position p)
{
	if (p->X < 2 || p->X > GAME_WIDTH - 2 || p->Y < 3 || p->Y > GAME_HEIGHT - 2)
		return 1;
	return 0;
}

int changeFoods(game Game)
{
	if (Game->difficulty + Game->food == 5 || ((Game->food == 1) && (Game->difficulty >= 4)))
	{
		return 0;
	}
	else
	{
		Game->food--;
		Game->Foods = Game->Foods->next;
		Game->Foods->previous = NULL;
	}
}
int changeWeeds(game Game)
{
	if (Game->difficulty + 3 == Game->weeds)
	{
		return 0;
	}
	else
	{
		Game->weeds++;
		poisonousWeeds temp = (poisonousWeeds)malloc(sizeof(struct SnakeNode));
		if (temp != NULL)
		{
			temp->posi = (Ptr_position)malloc(sizeof(struct position));
			if (temp->posi != 0)
			{
				temp->posi->X = rand() % (GAME_WIDTH - 6);
				temp->posi->Y = rand() % (GAME_HEIGHT - 6);
			}
			temp->next = Game->Weeds;
			Game->Weeds->previous = temp;
			Game->Weeds = temp;
		}
		return 1;
	}
}
int changeBooms(game Game)
{
	if (Game->difficulty + 3 == Game->boom)
	{
		return 0;
	}
	else
	{
		Game->boom++;
		booms temp = (booms)malloc(sizeof(struct SnakeNode));
		if (temp != NULL)
		{
			temp->posi = (Ptr_position)malloc(sizeof(struct position));
			if (temp->posi != 0)
			{
				temp->posi->X = rand() % (GAME_WIDTH - 6);
				temp->posi->Y = rand() % (GAME_HEIGHT - 6);
			}
			temp->next = Game->Booms;
			Game->Booms->previous = temp;
			Game->Booms = temp;
		}
	}
}