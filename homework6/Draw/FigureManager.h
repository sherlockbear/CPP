#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_

#include <iostream>
#include "Factory.h"

class BlackBoard; 

class FigureManager
{
private:
	Factory factory;
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
