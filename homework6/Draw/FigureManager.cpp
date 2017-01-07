#include "stdafx.h" 

#include "FigureManager.h"
#include "BlackBoard.h"

using std::cout; 

void FigureManager::input(std::istream &is)
{
    // 1����ӡ�˵������û�ѡ������ͼ��
	// �˵���ʽΪ
	std::cout << "input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)"<<std::endl;

	// ���벻Ҫ��std::cin
	// �ñ��������������is���÷�ͬcin

	// 2���û���������(1/2/3/0)ѡ��󣬸��ݲ�ͬ��ͼ�Σ���ʾ����ͼ�εĲ���
	
	char oneinput;
	for(;;)
	{
		is >> oneinput;
		switch (oneinput)
		{
		case '0':
		{
			return;
		}
		default:
			factory.getFigure(oneinput,is);
		}
	}
}

void FigureManager::display(BlackBoard &board)
{
	// ������input�������ͼ�����������λ���
	factory.Draw(board);
}


// ������ʵ����ҪһЩ��Ҫ�ĳ�ʼ�����ɷ�����������У�main���������
// ���û�У������
void InitiateFigureManager()
{

}
