#ifndef _LINE_H_
#define _LINE_H_

#include "Figure.h"

class Line :public Figure
{
public:
	Line(int x1, int y1, int x2, int y2)
	{
		_data.push_back(x1);
		_data.push_back(y1);
		_data.push_back(x2);
		_data.push_back(y2);
	}

	void Draw(BlackBoard &board)
	{
		board.DrawLine(_data[0], _data[1], _data[2], _data[3]);
	};
};
#endif
