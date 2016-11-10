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
	buff = new ValueType[_capacity];
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
	ValueType *newbuff;
	newbuff = new ValueType[newcap];
	for (int i = 0; i<_size; ++i)
	{
		*(newbuff + i) = *(buff + i);
	}
	ValueType *oldbuff = buff;
	buff = newbuff;
	delete[]oldbuff;
}

void CArray::insert(const int j, const ValueType ele)    	//在index=j的位置插入元素ele
{
	_size++;
	if (_size>_capacity)
	{
		recap(_capacity*2);
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

void CArray::append(const ValueType ele)					//增加元素
{
	int size = _size;
    insert(size,ele);
}

ValueType& CArray::at(const int j)                   		//返回在位置j的元素 
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