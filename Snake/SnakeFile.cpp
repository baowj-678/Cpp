#include "SnakeFile.h"
#include "SnakeUI.h"
#include <stdio.h>
#include <malloc.h>
#define IMAGE_SIZE	16
static char score[] = ".\\score.snake";
static char gameInfo[] = ".\\info.snake";


void getScore(int s[])
{
	FILE* fp;
	fopen_s(&fp, score, "r+");
	if (fp != NULL)
	{
		fscanf_s(fp, "%d%d%d%d%d", s, s + 1, s + 2, s + 3, s + 4);
		fclose(fp);
	}
}

void storeScore(int s[])
{
	FILE* fp;
	fopen_s(&fp, score, "w+");
	if (fp != NULL)
	{
		fprintf(fp, "%d %d %d %d %d", s[0], s[1], s[2], s[3], s[4]);
		fclose(fp);
	}
}

void newScore(int score)
{
	int s[5];
	getScore(s);
	int i = 0;
	if (score > s[4])
	{
		for (i = 4; i >= 0; i--)
		{
			if (score > s[i] && i != 0)
			{
				s[i] = s[i - 1];
			}
			else
			{
				s[i] = score;
			}
		}
	}
	storeScore(s);
}

game getGameInfo()
{
	game Game;
	FILE* fp;
	fopen_s(&fp, gameInfo, "r+");
	Game = CreateGame();
	if (fp != NULL)
	{
		fscanf_s(fp, "%d", &Game->is_on);
		fscanf_s(fp, "%d%d", &Game->difficulty, &Game->scene);
		fscanf_s(fp, "%d%d", &Game->score, &Game->length);
		fscanf_s(fp, "%d%d", &Game->direc->X, &Game->direc->Y);
		fscanf_s(fp, "%d", &Game->time);
		int i;
		//食物初始化
		foods tail = Game->Foods;
		fscanf_s(fp, "%d", &Game->food);
		for (i = 0; i < Game->food; i++)
		{
			foods food = (foods)malloc(sizeof(struct SnakeNode));
			food->posi = (Ptr_position)malloc(sizeof(struct position));
			if(food->posi != NULL)
				fscanf_s(fp, "%d%d", &(food->posi->X), &(food->posi->Y));
			food->next = NULL;
			if (i == 0)
			{
				Game->Foods = food;
				tail = food;
				food->previous = NULL;

			}
			else
			{
				tail->next = food;
				food->previous = tail;
				tail = food;
			}
		}
		//毒草初始化
		fscanf_s(fp, "%d", &Game->weeds);
		for (i = 0; i < Game->weeds; i++)
		{
			poisonousWeeds weed = (poisonousWeeds)malloc(sizeof(struct SnakeNode));
			weed->posi = (Ptr_position)malloc(sizeof(struct position));
			if(weed->posi != NULL)
				fscanf_s(fp, "%d%d", &(weed->posi->X), &(weed->posi->Y));
			weed->next = NULL;
			if (i == 0)
			{
				Game->Weeds = weed;
				tail = weed;
				weed->previous = NULL;

			}
			else
			{
				tail->next = weed;
				weed->previous = tail;
				tail = weed;
			}
		}
		fscanf_s(fp, "%d", &Game->boom);
		for (i = 0; i < Game->boom; i++)
		{
			booms boom = (booms)malloc(sizeof(struct SnakeNode));
			boom->posi = (Ptr_position)malloc(sizeof(struct position));
			if(boom->posi != NULL)
				fscanf_s(fp, "%d%d", &(boom->posi->X), &(boom->posi->Y));
			boom->next = NULL;
			if (i == 0)
			{
				Game->Booms = boom;
				tail = boom;
				boom->previous = NULL;

			}
			else
			{
				tail->next = boom;
				boom->previous = tail;
				tail = boom;
			}
		}
		for (i = 0; i < Game->length; i++)
		{
			snake node = (foods)malloc(sizeof(struct SnakeNode));
			node->posi = (Ptr_position)malloc(sizeof(struct position));
			if(node->posi != NULL)
				fscanf_s(fp, "%d%d", &(node->posi->X), &(node->posi->Y));
			node->next = NULL;
			if (i == 0)
			{
				Game->head = node;
				tail = node;
				node->previous = NULL;

			}
			else
			{
				tail->next = node;
				node->previous = tail;
				tail = node;
			}
		}
		Game->tail = tail;
	}
	fclose(fp);
	return Game;
}

void storeGameInfo(game Game)
{
	FILE* fp;
	fopen_s(&fp, gameInfo, "w+");
	if (fp != NULL)
	{
		fprintf(fp, "%d ", Game->is_on);
		fprintf(fp, "%d %d ", Game->difficulty, Game->scene);
		fprintf(fp, "%d %d ", Game->score, Game->length);
		fprintf(fp, "%d %d ", Game->direc->X, Game->direc->Y);
		fprintf(fp, "%d ", Game->time);
		foods Foods = Game->Foods;
		fprintf(fp, "%d ", Game->food);
		while (Foods != NULL)
		{
			fprintf(fp, "%d %d ", Foods->posi->X, Foods->posi->Y);
			Foods = Foods->next;
		}
		poisonousWeeds Weeds = Game->Weeds;
		fprintf(fp, "%d ", Game->weeds);
		while (Weeds != NULL)
		{
			fprintf(fp, "%d %d ", Weeds->posi->X, Weeds->posi->Y);
			Weeds = Weeds->next;
		}
		booms Booms = Game->Booms;
		fprintf(fp, "%d ", Game->boom);
		while (Booms != NULL)
		{
			fprintf(fp, "%d %d ", Booms->posi->X, Booms->posi->Y);
			Booms = Booms->next;
		}
		snake Snake = Game->head;
		while (Snake != NULL)
		{
			fprintf(fp, "%d %d ", Snake->posi->X, Snake->posi->Y);
			Snake = Snake->next;
		}
		fclose(fp);
	}
}

void loadingImage(IMAGE* bomb, IMAGE* weed, IMAGE* food, IMAGE* background, int scene)
{
	if (scene == 1)
	{
		loadimage(bomb, _T(".//source//bomb1.ico"), IMAGE_SIZE, IMAGE_SIZE);
		loadimage(weed, _T(".//source//weed1.png"), IMAGE_SIZE, IMAGE_SIZE);
		loadimage(food, _T(".//source//food1.gif"), IMAGE_SIZE, IMAGE_SIZE);
		loadimage(background, _T(".//source//bk1.png"), GAME_WIDTH, GAME_HEIGHT);
	}
	else if (scene == 2)
	{
		loadimage(bomb, _T(".//source//bomb2.png"), IMAGE_SIZE, IMAGE_SIZE);
		loadimage(weed, _T(".//source//weed2.png"), IMAGE_SIZE, IMAGE_SIZE);
		loadimage(food, _T(".//source//food2.png"), IMAGE_SIZE, IMAGE_SIZE);
		loadimage(background, _T(".//source//bk2.jpg"), GAME_WIDTH, GAME_HEIGHT);
	}
	else if (scene == 3)
	{
		loadimage(bomb, _T(".//source//bomb3.png"), IMAGE_SIZE, IMAGE_SIZE);
		loadimage(weed, _T(".//source//weed3.png"), IMAGE_SIZE, IMAGE_SIZE);
		loadimage(food, _T(".//source//food3.png"), IMAGE_SIZE, IMAGE_SIZE);
		loadimage(background, _T(".//source//bk3.png"), GAME_WIDTH, GAME_HEIGHT);
	}
}
