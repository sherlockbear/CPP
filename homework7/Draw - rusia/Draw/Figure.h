#ifndef __FIGURE__
#define __FIGURE__

#include "Box.h"

class Figure
{
public:
	Figure(int left, int top, int c);
	~Figure();
	void Set();
	void Spin();
	bool CanMove(int dx, int dy);
	void Move(int dx, int dy);

private:
	Box _b1, _b2, _b3, _b4;
};

void Figure::Set()
{
	_b1.Reset(0, 1);
	_b2.Reset(0, 2);
	_b3.Reset(0, 3);
	_b4.Reset(0, 4);
}

void Figure::Spin()
{

}

bool Figure::CanMove(int dx, int dy)
{
	return (_b1.CanMove(dx, dy) | _b2.CanMove(dx, dy) | _b3.CanMove(dx, dy) | _b4.CanMove(dx, dy));
}

void Figure::Move(int dx, int dy)
{
	_b1.Move(dx, dy);
	_b2.Move(dx, dy);
	_b3.Move(dx, dy);
	_b4.Move(dx, dy);
}

Figure::Figure(int left, int top, int c) :_b1(left, top, 0, c), _b2(left, top, 0, c+1), _b3(left, top, 0, c+2), _b4(left, top, 0, c+3)
{
}

Figure::~Figure()
{
}

#endif // !__FIGURE__

