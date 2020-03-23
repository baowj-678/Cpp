#ifndef _SNAKE_UI_
#define _SNAKE_UI_
#include <graphics.h> 
#include <easyx.h>
#include "Position.h"
#include "SnakeNode.h"
#define R	7
#define CHOOSE_HEIGHT	480
#define CHOOSE_WIDTH	640
#define GAME_HEIGHT		700
#define GAME_WIDTH		900


void DrawSnake(game Game);
void DrawPoisonousWeeds(poisonousWeeds PoisonousWeeds);
void DrawBooms(booms Booms);
void DrawFoods(foods Foods);
void DrawBorder(BorderLine borderLine, int direction);
//绘制游戏选项
void DrawChoose();
//初始化窗口
void InitGraph();
void DrawGameInfo(game Game);
void DrawGameWindow(int difficulty, int scene, int is_new);
void DrawRank();
void GameInit(game Game, HRGN* Snake_RGN, HRGN* Info_RGN);
void DrawGameOver();
int DrawScene();

#endif // !SNAKE_UI_

