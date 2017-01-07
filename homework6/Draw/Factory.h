#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Figure.h"
#include "BlackBoard.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

class Factory
{
private:
	std::vector<Figure*> fig;
	Figure* F;
public:
	void getFigure(char num, std::istream &is)
	{
		switch (num)
		{
		case '1':		// 其中圆的参数依次为圆心x、y、半径，因此包含提示的输入代码类似以下结果
		{
			int _x, _y, _radius;
			std::cout << "Center X: ";
			is >> _x;

			std::cout << "Center Y: ";
			is >> _y;

			std::cout << "Radius: ";
			is >> _radius;

			F = new Circle(_x, _y, _radius);
			fig.push_back(F);
			break;
		}

		case '2':		// 线参数为端点1 X、Y坐标，端点2 X坐标、Y坐标。
		{
			int _x1, _y1, _x2, _y2;
			std::cout << "X1: ";
			is >> _x1;
			std::cout << "Y1: ";
			is >> _y1;

			std::cout << "X2: ";
			is >> _x2;
			std::cout << "Y2: ";
			is >> _y2;

			F = new Line(_x1, _y1, _x2, _y2);
			fig.push_back(F);
			break;
		}

		case '3':		// 矩形参数为左上顶点x、y，右下顶点x、y
		{
			int _left, _top, _right, _bottom;
			std::cout << "Left: ";
			is >> _left;
			std::cout << "Top: ";
			is >> _top;

			std::cout << "Right: ";
			is >> _right;
			std::cout << "Bottom: ";
			is >> _bottom;

			F = new Rectangle(_left, _top, _right, _bottom);
			fig.push_back(F);
			break;
		}

		default:
			return;
		}
		return;
	}

	void Draw(BlackBoard &board)
	{
		for (unsigned int i = 0; i<fig.size(); ++i) {
			fig[i]->Draw(board);
		}
	}
};
#endif