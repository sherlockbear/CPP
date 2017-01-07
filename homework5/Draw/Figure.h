#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <vector>
#include "FigureManager.h"
#include "BlackBoard.h"

class Figure
{
protected:
	std::vector<int> _data;
public:
	void Draw(BlackBoard &board) {};
};
#endif
