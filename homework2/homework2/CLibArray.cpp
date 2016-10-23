#include "stdafx.h"
#include "CLibArray.h"
#include <stdlib.h>

int CArray::capacity()                          			//返回数组容量
{
	return _capacity;
}

void CArray::copy(CArray &arr)
{
	_capacity = arr.capacity();
	_size = arr.size();
	buff = new int[_capacity];
	for (int i = 0; i<_size; ++i)
	{
		*(buff + i) = arr.at(i);
	}
}

int CArray::recap(const int newcap)							//重新定义数组容量
{
	if (newcap < _size)
		exit(1);
	_capacity = newcap;
	int *newbuff;
	newbuff = new int[newcap];
	for (int i = 0; i<_size; ++i)
	{
		*(newbuff + i) = *(buff + i);
	}
	int *oldbuff = buff;
	buff = newbuff;
	delete[]oldbuff;
	#if 0
	int capaug = newcap - _capacity;
	CArray *arr = new CArray;
	copy(*arr);
	//format();
	(this, capaug);
	delete arr;
	return 0;
	#endif
}

void CArray::insert(const int j, const int ele)    			//在index=j的位置插入元素ele
{
	_size++;
	if (_size>_capacity)
	{
		recap(_capacity + 10);
	}
	for (int i = _size-1; i>j; i--)
	{
		*(buff + i) = *(buff + i - 1);
	}
	*(buff + j) = ele;
}

int CArray::size()                               			//返回数组大小
{
	return _size;
}

void CArray::append(const int ele)							//增加元素
{
	int size = _size;
    insert(size,ele);
}

int& CArray::at(const int j)                   			//返回在位置j的元素 
{
	if (j > _size)
		exit(1);
	return *(buff + j);
}

bool CArray::compare(CArray &arr)        					//比较当前数组和arr
{
    int size;
    if (_size>arr.size())
		size = _size;
    else
		size = arr.size();
    for(int i=0;i<size;i++)
    {
        if (at(i) == arr.at(i))
			continue;
        else
			return false;
    }
    return true;
}

CArray::~CArray()                                 			//析构函数
{
	delete []buff;
}