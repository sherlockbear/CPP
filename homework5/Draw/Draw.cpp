// Draw.cpp : �������̨Ӧ�ó������ڵ㡣
//��ҵ�ύ��

#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "BlackBoard.h"
#include "FigureManager.h"

// �������ҵ�ύʱ�䣺11��27��24:00��ǰ
// ���Ǳ�����ҵ�Ĳ��Դ��룬��Ҫ��ͬѧ����Ϥ�̳е��÷�
// ������ҵĿ�ģ�ʵ��һ����ͼϵͳ���û��������ͼ��(Բ���߶Σ�������)�Ĳ�����һ���Ի�����������ͼ��
// ������ʵ��һ����Figure��������ͼ�ζ���Figure��������
// ���⣬����Ҫʵ��FigureManager.h(cpp)�����ṩͼ�β�������Ľ���Ϳ��ƣ�����Ҫ���FigureManager.cpp
// BlackBoard.h(cpp)����Ҫ�޸ġ�����һ��ʵ�ֻ�ͼ�������࣬
// �����ύFigureManager.h(cpp),Figure.h(cpp),Circle.h(cpp),Line.h(cpp),Rectangle.h(cpp)���ļ����̶�

// ��ҵ�����ļ������.zip��.rarѹ���������ʼ�������ʽ�����͵����� esecpp2016@163.com���ʼ�������ѹ������һ��
// ѹ���������淶��ѧ��+����+�ڼ�����ҵ+�ڼ��棻���磺141180000+�ܿ�+�������ҵ+��һ�棨ע����ӼӺš�+��������ҵ�������һ���ύ��Ϊ׼




// �ṩ��ͼ�����Ķ���
BlackBoard board; 

// �ɺ���
void ReshapeCallback(int width, int height)
{
	board.UpdateWindowSize(width, height); 
}

// �������ڴ����������Ļص�������ڣ�����ֻ������һ���£���q�˳����򣬿ɺ���
// ע�⣬����ļ��������Ǵ��ڵļ������룬�����������е�
void KeyboardCallback(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		exit(0);
		break; 
	}

}

// �������ڻ��ƵĻص�������ڣ����ջ����FigureManager��display����
// ������ҵ����Ķ�DisplayCallback������ͼ��Ӧ��FigureManager����ɡ�
void DisplayCallback()
{
	board.Clear(); 

	FigureManager::handle().display(board); 

	board.Flush(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
	// ������ʵ����ҪһЩ��Ҫ�ĳ�ʼ�����ɷ�����������У�main���������
	// ���û�У������
	InitiateFigureManager(); 

	// ������л����뷽ʽ��
	// 1����test.txt�ļ����룬�Է������ʱ���������ʱ��
	// 2�������������룬�԰�����û����ȫ��д�ô���ʱ���޷���test.txt����

#if 0
	std::ifstream in("test.txt");  
	if (! in.is_open())  
	{ 
		std::cout << "Error opening file"; 
		exit (1); 
	}  
	FigureManager::handle().input(in); 
#else
	FigureManager::handle().input(std::cin); 
#endif

	// ���´������ڳ�ʼ�����ڵȡ��ɺ���
	board.InitCommandLine(&argc, (char **)argv); 
	board.InitWindowSize(800, 800); 

	board.InitDisplayCallback(DisplayCallback); 
	board.InitKeyboardCallback(KeyboardCallback); 
	board.InitReshapeCallback(ReshapeCallback); 

	board.Show(); 

	return 0;
}

