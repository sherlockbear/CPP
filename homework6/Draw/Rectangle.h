#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Figure.h"

class Rectangle :public Figure
{
public:
	Rectangle(int left, int top, int right, int bottom)
	{
		_data.push_back(left);
		_data.push_back(top);
		_data.push_back(right);
		_data.push_back(bottom);
	}

	void Draw(BlackBoard &board)
	{
		board.DrawLine(_data[0], _data[1], _data[2], _data[1]);
		board.DrawLine(_data[0], _data[1], _data[0], _data[3]);
		board.DrawLine(_data[0], _data[3], _data[2], _data[3]);
		board.DrawLine(_data[2], _data[1], _data[2], _data[3]);
	};
};
#endif
