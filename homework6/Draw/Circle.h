#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Figure.h"

class Circle:public Figure
{
public:
	Circle(int x,int y,int r)
	{
		_data.push_back(x);
		_data.push_back(y);
		_data.push_back(r);
	}

	void Draw(BlackBoard &board) 
	{
		board.DrawCircle(_data[0], _data[1], _data[2]);
	};
};
#endif