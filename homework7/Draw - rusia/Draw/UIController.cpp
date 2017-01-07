#include "stdafx.h"

#include <iostream>

#include "UIController.h"
#include "BlackBoard.h"

extern BlackBoard board; 

UIController::UIController() : _left(-(COLS * Box::BOX_SIZE / 2)), _bottom(-ROWS * Box::BOX_SIZE / 2), _right(COLS * Box::BOX_SIZE / 2), _top(ROWS * Box::BOX_SIZE / 2), _box(_left, _top, 0, INITIAL_COL), _figure(_left, _top, INITIAL_COL)
{
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			// ��ʼû�й̶�����
			_boxes[r][c] = false; 
		}
	}
	_figure.Set();
}

UIController::~UIController()
{
}

void UIController::OnDraw(BlackBoard &board) 
{ 
	board.SetColor(1, 0, 1); 
	board.DrawLine(_left,  _top,   _left,  _bottom);
	board.DrawLine(_left,  _top,   _right, _top);
	board.DrawLine(_left,  _bottom,_right, _bottom);
	board.DrawLine(_right, _top,   _right, _bottom);

	board.SetColor(1, 0, 0); 
	_box.OnDraw(board); 

	board.SetColor(0, 1, 1); 
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			if (_boxes[r][c])
			{
				// ����Box����ƹ̶�����
				Box box(_left, _top, r, c); 
				box.OnDraw(board); 
			}
		}
	}
}


void UIController::OnTimer(int code)
{
	MoveBoxDown(); 
}

void UIController::OnKey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		exit(0);
		break; 
	case 's':
		MoveBoxDown(); 
		break; 
	case 'a':
		MoveBoxLeft(); 
		break; 
	case 'd':
		MoveBoxRight(); 
		break; 
	}
}

bool UIController::HitLeft(Box &box)
{
	return box.LeftTo(_left); 
}

bool UIController::HitRight(Box &box)
{
	return box.RightTo(_right); 
}

bool UIController::HitBottom(Box &box)
{
	return box.LowerTo(_bottom); 
}

bool UIController::HitBoxes(Box &box)
{
	return _boxes[box.Row()][box.Col()]; 
}

void UIController::EraseFullRows()
{
	for (int r = 0; r < ROWS; ++r)
	{
		bool fulled = true; 
		for (int c = 0; c < COLS; ++c)
		{
			if (!_boxes[r][c]) 
			{
				// ����һ��λ���޹̶����飬���������������㣬����
				fulled = false; 
				break; 
			}
		}

		if (fulled)
		{
			PushRows(r); 
		}
	}
}

void UIController::PushRows(int row)
{
	for (int r = row; r > 0; --r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			// row��֮�Ϸ�������
			_boxes[r][c] = _boxes[r - 1][c]; 
		}
	}

	for (int c = 0; c < COLS; ++c)
	{
		// ���һ���ÿ�
		_boxes[0][c] = false; 
	}
}

#if 1

void UIController::MoveBoxLeft()
{
	if (_box.CanMove(0, -1))
	{
		_box.Move(0, -1); 
		board.Update(); 
	}
}

void UIController::MoveBoxRight()
{
	if (_box.CanMove(0, 1))
	{
		_box.Move(0, 1); 
		board.Update(); 
	}
}

void UIController::MoveBoxDown()
{
	if (_box.CanMove(1, 0))
	{
		_box.Move(1, 0); 
		board.Update(); 
	}
	else
	{
		// �޷����ƣ���˵���·����ϰ����߽��̶����飩�����������̶�������
		InsertBox(_box);
		
		// �������
		EraseFullRows(); 

		// ��������ã��൱��������һ���µĻ����
		_box.Reset(0, INITIAL_COL); 
		
		board.Update(); 
	}
}

#else

void UIController::MoveBoxLeft()
{
	if (_figure.CanMove(0, -1))
	{
		_figure.Move(0, -1);
		board.Update();
	}
}

void UIController::MoveBoxRight()
{
	if (_figure.CanMove(0, 1))
	{
		_figure.Move(0, 1);
		board.Update();
	}
}

void UIController::MoveBoxDown()
{
	if (_figure.CanMove(1, 0))
	{
		_figure.Move(1, 0);
		board.Update();
	}
	else
	{
		// �޷����ƣ���˵���·����ϰ����߽��̶����飩�����������̶�������
		InsertBox(_box);

		// �������
		EraseFullRows();

		// ��������ã��൱��������һ���µĻ����
		_box.Reset(0, INITIAL_COL);

		board.Update();
	}
}

#endif