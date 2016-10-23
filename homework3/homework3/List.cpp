#include "stdafx.h"
#include "List.h"
#include <stdlib.h>

int CPPList::capacity()                          			//返回数组容量
{
	return _capacity;
}

void CPPList::copy(CPPList &arr)
{
	_capacity = arr.capacity();
	_size = arr.size();
	buff = new int[_capacity];
	for (int i = 0; i<_size; ++i)
	{
		*(buff + i) = arr.at(i);
	}
}

int CPPList::recap(const int newcap)							//重新定义数组容量
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
	CPPList *arr = new CPPList;
	copy(*arr);
	//format();
	(this, capaug);
	delete arr;
	return 0;
	#endif
}



int& CPPList::at(const int j)                   			//返回在位置j的元素 
{
	if (j > _size)
		exit(1);
	return *(buff + j);
}

bool CPPList::compare(CPPList &arr)        					//比较当前数组和arr
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

ListNode::~ListNode()
{
	;
}

CPPList::~CPPList()                                 			//析构函数
{
	delete []buff;
}

int& ListNode::data()
{
	return _data;
}

ListNode* ListNode::next()
{
	return _next;
}

ListNode* CPPList::begin()										//返回头指针
{
	return _begin;
}

ListNode* CPPList::end()										//返回尾指针
{
	return _end;
}

int CPPList::size()                               			//返回链表大小
{
	return _size;
}

ListNode* CPPList::next(ListNode *current)					//返回下一结点指针
{
	return current->next();
}

void CPPList::append(const int ele)								//增加元素
{
    insert(_end,ele);
}

void CPPList::insert(ListNode* j, const int ele)    			//在j位置插入数据为ele的结点
{
	;
}

void CPPList::clear()											//清空链表
{
	;
}

void CPPList::remove(ListNode* j)								//移除j位置结点
{
	;
}