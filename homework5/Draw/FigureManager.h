#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_

#include <vector>
#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

class BlackBoard; 

class FigureManager
{
private:
	std::vector<Circle*> cir;
	std::vector<Line*> li;
	std::vector<Rectangle*> rec;

public:
	static FigureManager &handle()
	{
		static FigureManager manager; 
		return manager; 
	}
    
    // FigureManager����������
    virtual ~FigureManager() { }
 
    // FigureManager��ӿ�.
public:
	void input(std::istream &is); 
    void display(BlackBoard &board); 

}; // class FigureManager�ඨ�����.

void InitiateFigureManager(); 

#endif // #ifndef _FIGUREMANAGER_H_
