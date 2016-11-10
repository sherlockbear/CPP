#include "stdafx.h"
#include "Matrix.h"
#include <stdlib.h>

ListNode::~ListNode()											//��������
{
	_data = 0;
	_next = NULL;
	_previous = NULL;
}

CPPList::~CPPList()                                 			//��������
{
	clear();
}

int& ListNode::data()											//���ؽ������
{
	return _data;
}

int ListNode::data() const										//���ؽ������
{
	return _data;
}

ListNode* &ListNode::next()										//���غ���ָ��
{
	return _next;
}

ListNode* ListNode::next() const								//���غ���ָ��
{
	return _next;
}

ListNode* &ListNode::previous()									//����ǰ��ָ��
{
	return _previous;
}

ListNode* ListNode::previous() const							//����ǰ��ָ��
{
	return _previous;
}

ListNode* CPPList::begin()										//����ͷָ��
{
	return _begin;
}

ListNode* CPPList::begin() const								//����ͷָ��
{
	return _begin;
}

ListNode* CPPList::end()										//����βָ��
{
	return _end;
}

ListNode* CPPList::end() const									//����βָ��
{
	return _end;
}

int CPPList::size()                               				//���������С
{
	return _size;
}

ListNode* CPPList::next(ListNode *current)						//������һ���ָ��
{
	return current->next();
}

ListNode* CPPList::next(const ListNode *current) const			//������һ���ָ��
{
	return current->next();
}

void CPPList::append(const int ele)								//����Ԫ��
{
	insert(_end, ele);
}

void CPPList::insert(ListNode* j, const int ele)    			//��jλ�ò�������Ϊele�Ľ��
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

void CPPList::clear()											//�������
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

void CPPList::remove(ListNode* j)								//�Ƴ�jλ�ý��
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