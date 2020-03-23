#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "SnakeNode.h"
#include "SnakeUI.h"



int main()
{
	//初始化窗口
	InitGraph();
	//主菜单界面
	DrawChoose();
	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
}

