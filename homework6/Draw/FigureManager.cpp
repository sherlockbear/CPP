#include "stdafx.h" 

#include "FigureManager.h"
#include "BlackBoard.h"

using std::cout; 

void FigureManager::input(std::istream &is)
{
    // 1、打印菜单，让用户选择输入图形
	// 菜单格式为
	std::cout << "input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)"<<std::endl;

	// 输入不要用std::cin
	// 用本函数的输入参数is，用法同cin

	// 2、用户输入数字(1/2/3/0)选择后，根据不同的图形，提示输入图形的参数
	
	char oneinput;
	for(;;)
	{
		is >> oneinput;
		switch (oneinput)
		{
		case '0':
		{
			return;
		}
		default:
			factory.getFigure(oneinput,is);
		}
	}
}

void FigureManager::display(BlackBoard &board)
{
	// 将所有input中输入的图形在这里依次画出
	factory.Draw(board);
}


// 如果你的实现需要一些必要的初始化，可放在这个函数中，main函数会调用
// 如果没有，则忽略
void InitiateFigureManager()
{

}
