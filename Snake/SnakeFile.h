#include "SnakeNode.h"
#include <easyx.h>
#ifndef _SNAKE_FILE_
#define _SNAKE_FILE_





void getScore(int s[]);
void storeScore(int s[]);
void newScore(int score);
void storeGameInfo(game Game);
game getGameInfo();
void loadingImage(IMAGE* bomb, IMAGE* weed, IMAGE* food, IMAGE* background, int scene);

#endif