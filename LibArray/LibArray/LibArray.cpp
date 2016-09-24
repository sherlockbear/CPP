// LibArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

// ʵ�����ݣ�
// 1��ʹ��C����ʵ��һ�����ȿ���������飨������Ҫ�����ݽṹ����������
// 2��Ҫ���ܴ���������͵����ݣ�������ʵ�ִ洢���εĴ��룬֮���д����Ӧ�������͵Ĵ��룩��
// 3����д��������ͨ�����Գ���
// 4�������ļ��������ļ���֮�⣬�����ļ�����CLibArray.cpp��CLibArray.h�ļ������Լ�������ͬѧ�Լ������������пɷ��飬�ɲ鿴msdn��

// ʵ��Ŀ�ģ�
// 1����Ϥ��ص�ָ�����, ��ϰ��̬�ڴ����ز���.
// 2�����C�������ʵ���������ͺ�Χ�����������ϲ����ļ���
// 3��Ϊδ�������ʵ�ֵ�����vector��׼��

// ֻ�ύCLibArray.cpp��CLibArray.h

// ʵ���ύ��
// �����ļ������һ��ѹ���������ʼ�������ʽ���͡��ʼ�������ѹ������һ�¡�
// Email��		esecpp2016@163.com
// �����淶��	����+ѧ��+�ڼ�����ҵ+�ڼ���
// ��ֹʱ�䣺	10��2��24��00ǰ

#include "stdafx.h"

#include <assert.h>

#include "CLibArray.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CArray array;
	array_initial(array);

	array_recap(array, 10); //���¶�����������
	assert(array_capacity(array) == 10);

	//////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 20; ++i)
	{
		array_append(array, i); //����Ԫ��
	}
	assert(array_size(array) == 20);

	for (int i = 0; i < array_size(array); ++i)
	{
		assert(array_at(array, i) == i);//array_at:������λ��i��Ԫ�� 
	}

	//////////////////////////////////////////////////////////////////////////
	CArray array2, array3;
	array_initial(array2);
	array_initial(array3);

	array_copy(array, array2); //��array������array2
	assert(array_compare(array, array2) == true);
	array_copy(array, array3);
	assert(array_compare(array, array3) == true);

	//////////////////////////////////////////////////////////////////////////
	array_insert(array2, 2, 3); //��array2 index=2��λ�ò���Ԫ��3
	assert(array_compare(array, array2) == false);

	//////////////////////////////////////////////////////////////////////////
	array_at(array3, 2) = 5;
	assert(array_compare(array, array3) == false);

	//////////////////////////////////////////////////////////////////////////
	array_destroy(array);
	array_destroy(array2);
	array_destroy(array3);

	return 0;
}


// ��ҵ��ʾ��
// typedef struct  
// {
//     int *buff; 
//     int size; 
//     int capacity; 
// } CArray;

