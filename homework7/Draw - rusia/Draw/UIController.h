#ifndef __UICONTROLLER__
#define __UICONTROLLER__

#include "Box.h"

#include "Figure.h"

class BlackBoard; 

class UIController
{
public:
	// 整个区域容纳的方块数量
	const static int ROWS = 40; 
	const static int COLS = 10;

	// 初始掉落位置
	const static int INITIAL_COL = COLS / 2; 

public:
	// UIController采用单子模式，整个软件中唯一
	static UIController &handle()
	{
		static UIController instance; 
		return instance; 
	}

	// 掉落速度，单位毫秒，即每X毫秒掉落一格
	int GameSpeed() { return 100; }

	// 定时器处理逻辑，此处主要用于驱动方块自动掉落
	void OnTimer(int code); 

	// 绘图逻辑，包括边框绘制，方块绘制
	void OnDraw(BlackBoard &board); 

	// 按键逻辑，主要处理用户左、右、下三个方向的操作
	void OnKey(unsigned char key, int x, int y); 

	// 判断方块是否触碰左边界、右边界、下边界、及已有固定方块
	bool HitLeft(Box &box);
	bool HitRight(Box &box);
	bool HitBottom(Box &box);
	bool HitBoxes(Box &box); 

	~UIController(); 

private:
	UIController(); 
	
	// 删除已满的行
	void EraseFullRows();

	// 删除已满行后，上方方块下落
	void PushRows(int row); 

	// 活动方块控制逻辑
	void MoveBoxLeft(); 
	void MoveBoxRight(); 
	void MoveBoxDown(); 
	
	// 活动方块插入固定方块
	void InsertBox(Box &box)
	{
		_boxes[box.Row()][box.Col()] = true; 
	}
	
private:
	bool _boxes[ROWS][COLS]; 

	int _left,  _bottom; 
	int _right, _top; 


	Box _box;

	Figure _figure;
}; 


#endif // #ifndef __UICONTROLLER__