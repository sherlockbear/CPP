#include "stdafx.h" 

#include "FigureManager.h"
#include "BlackBoard.h"


using std::cout; 


void FigureManager::input(std::istream &is)
{
    // 1����ӡ�˵������û�ѡ������ͼ��
	// �˵���ʽΪ
	// input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)

	// ���벻Ҫ��std::cin
	// �ñ��������������is���÷�ͬcin

	// 2���û���������(1/2/3/0)ѡ��󣬸��ݲ�ͬ��ͼ�Σ���ʾ����ͼ�εĲ���
	
	char oneinput;
	Line* L;
	Circle* C;
	Rectangle* R;
	for(;;)
	{
		is >> oneinput;
		switch (oneinput)
		{
		case '1':		// ����Բ�Ĳ�������ΪԲ��x��y���뾶����˰�����ʾ����������������½��
		{
			int _x,_y,_radius;
			std::cout << "Center X: ";
			is >> _x;

			std::cout << "Center Y: ";
			is >> _y;

			std::cout << "Radius: ";
			is >> _radius;

			C = new Circle(_x, _y, _radius);
			cir.push_back(C);
			break;
		}
	
		case '2':		// �߲���Ϊ�˵�1 X��Y���꣬�˵�2 X���ꡢY���ꡣ
		{
			int _x1, _y1, _x2,_y2;
#if 1
			std::cout << "X1: ";
			is >> _x1;
			std::cout << "Y1: ";
			is >> _y1;

			std::cout << "X2: ";
			is >> _x2;
			std::cout << "Y2: ";
			is >> _y2;
#endif

			L = new Line(_x1, _y1, _x2, _y2);
			li.push_back(L);
			break;
		}

		case '3':		// ���β���Ϊ���϶���x��y�����¶���x��y
		{
			int _left, _top, _right, _bottom;
#if 1
			std::cout << "Left: ";
			is >> _left;
			std::cout << "Top: ";
			is >> _top;

			std::cout << "Right: ";
			is >> _right;
			std::cout << "Bottom: ";
			is >> _bottom;
#endif

			R = new Rectangle(_left, _top, _right, _bottom);
			rec.push_back(R);
			break;
		}

		case '0':
		{
			return;
		}
	// 3������ò����󣬽�ͼ�α�������������֮�����

	// 4���ص�1��������ӡ�˵���ֱ���û�ѡ��0���˳�input����

		default:
			continue;
		}
	}
}

void FigureManager::display(BlackBoard &board)
{
	// ������input�������ͼ�����������λ���
	for (unsigned int i = 0; i<li.size(); ++i) {
		li[i]->Draw(board);
	}

	for (unsigned int i = 0; i<rec.size(); ++i) {
		rec[i]->Draw(board);
	}
	for (unsigned int i = 0; i<cir.size(); ++i) {
		cir[i]->Draw(board);
	}
    
#if 0
	// ����board�ṩ��DrawCircle��DrawLine������ͼ����������һ��Բ����30,30λ�ã��뾶Ϊ100��Բ
	board.DrawCircle(30, 30, 100); 

	// �پ����������Σ��þ������Ͻ�Ϊ(30, 20)�����½�Ϊ��200,300��
	board.DrawLine(30, 20, 30, 300); 
	board.DrawLine(30, 300, 200, 300); 
	board.DrawLine(200, 300, 200, 20); 
	board.DrawLine(200, 20, 30, 20); 
#endif
}


// ������ʵ����ҪһЩ��Ҫ�ĳ�ʼ�����ɷ�����������У�main���������
// ���û�У������
void InitiateFigureManager()
{

}
