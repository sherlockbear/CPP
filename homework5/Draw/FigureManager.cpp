#include "stdafx.h" 

#include "FigureManager.h"
#include "BlackBoard.h"


using std::cout; 


void FigureManager::input(std::istream &is)
{
    // 1、打印菜单，让用户选择输入图形
	// 菜单格式为
	// input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)

	// 输入不要用std::cin
	// 用本函数的输入参数is，用法同cin

	// 2、用户输入数字(1/2/3/0)选择后，根据不同的图形，提示输入图形的参数
	
	char oneinput;
	Line* L;
	Circle* C;
	Rectangle* R;
	for(;;)
	{
		is >> oneinput;
		switch (oneinput)
		{
		case '1':		// 其中圆的参数依次为圆心x、y、半径，因此包含提示的输入代码类似以下结果
		{
			int _x,_y,_radius;
			std::cout << "Center X: ";
			is >> _x;

			std::cout << "Center Y: ";
			is >> _y;

			std::cout << "Radius: ";
			is >> _radius;

			C = new Circle(_x, _y, _radius);
			cir.push_back(C);
			break;
		}
	
		case '2':		// 线参数为端点1 X、Y坐标，端点2 X坐标、Y坐标。
		{
			int _x1, _y1, _x2,_y2;
#if 1
			std::cout << "X1: ";
			is >> _x1;
			std::cout << "Y1: ";
			is >> _y1;

			std::cout << "X2: ";
			is >> _x2;
			std::cout << "Y2: ";
			is >> _y2;
#endif

			L = new Line(_x1, _y1, _x2, _y2);
			li.push_back(L);
			break;
		}

		case '3':		// 矩形参数为左上顶点x、y，右下顶点x、y
		{
			int _left, _top, _right, _bottom;
#if 1
			std::cout << "Left: ";
			is >> _left;
			std::cout << "Top: ";
			is >> _top;

			std::cout << "Right: ";
			is >> _right;
			std::cout << "Bottom: ";
			is >> _bottom;
#endif

			R = new Rectangle(_left, _top, _right, _bottom);
			rec.push_back(R);
			break;
		}

		case '0':
		{
			return;
		}
	// 3，输入好参数后，将图形保存下来，用于之后绘制

	// 4，回到1，继续打印菜单，直到用户选择0，退出input函数

		default:
			continue;
		}
	}
}

void FigureManager::display(BlackBoard &board)
{
	// 将所有input中输入的图形在这里依次画出
	for (unsigned int i = 0; i<li.size(); ++i) {
		li[i]->Draw(board);
	}

	for (unsigned int i = 0; i<rec.size(); ++i) {
		rec[i]->Draw(board);
	}
	for (unsigned int i = 0; i<cir.size(); ++i) {
		cir[i]->Draw(board);
	}
    
#if 0
	// 借助board提供的DrawCircle和DrawLine函数画图，举例，画一个圆心在30,30位置，半径为100的圆
	board.DrawCircle(30, 30, 100); 

	// 再举例，画矩形，该矩形左上角为(30, 20)，右下角为（200,300）
	board.DrawLine(30, 20, 30, 300); 
	board.DrawLine(30, 300, 200, 300); 
	board.DrawLine(200, 300, 200, 20); 
	board.DrawLine(200, 20, 30, 20); 
#endif
}


// 如果你的实现需要一些必要的初始化，可放在这个函数中，main函数会调用
// 如果没有，则忽略
void InitiateFigureManager()
{

}
