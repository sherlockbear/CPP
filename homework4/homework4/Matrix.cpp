#include "stdafx.h"
#include "Matrix.h"
#include <stdlib.h>

ListNode::~ListNode()											//析构函数
{
	_data = 0;
	_next = NULL;
	_previous = NULL;
}

CPPList::~CPPList()                                 			//析构函数
{
	clear();
}

int& ListNode::data()											//返回结点数据
{
	return _data;
}

int ListNode::data() const										//返回结点数据
{
	return _data;
}

ListNode* &ListNode::next()										//返回后向指针
{
	return _next;
}

ListNode* ListNode::next() const								//返回后向指针
{
	return _next;
}

ListNode* &ListNode::previous()									//返回前向指针
{
	return _previous;
}

ListNode* ListNode::previous() const							//返回前向指针
{
	return _previous;
}

ListNode* CPPList::begin()										//返回头指针
{
	return _begin;
}

ListNode* CPPList::begin() const								//返回头指针
{
	return _begin;
}

ListNode* CPPList::end()										//返回尾指针
{
	return _end;
}

ListNode* CPPList::end() const									//返回尾指针
{
	return _end;
}

int CPPList::size()                               				//返回链表大小
{
	return _size;
}

ListNode* CPPList::next(ListNode *current)						//返回下一结点指针
{
	return current->next();
}

ListNode* CPPList::next(const ListNode *current) const			//返回下一结点指针
{
	return current->next();
}

void CPPList::append(const int ele)								//增加元素
{
	insert(_end, ele);
}

void CPPList::insert(ListNode* j, const int ele)    			//在j位置插入数据为ele的结点
{
	++_size;
	ListNode* inst = new ListNode(j->previous(),j);
	inst->data() = ele;
	if (j->previous() == NULL)
		_begin = inst;
	else
		j->previous()->next() = inst;
	j->previous() = inst;
}

void CPPList::clear()											//清空链表
{
	ListNode *current;
	int idx;
	for (idx = 0, current = begin(); current != end(); ++idx)
	{
		ListNode *tmp = current;
		current = next(current);
		remove(tmp);
	}
}

void CPPList::remove(ListNode* j)								//移除j位置结点
{
	if (j == NULL)
		return;
	if (j->previous() == NULL)
		_begin = j->next();
	else
		(j->previous())->next() = j->next();
	if (j->next() == NULL)
		return;
	(j->next())->previous() = j->previous();
	--_size;
	delete j;
}