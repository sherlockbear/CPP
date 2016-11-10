#ifndef CLib
#define CLib

class ListNode
{
private:
	int _data;
	ListNode* _next;
	ListNode* _previous;

public:
	ListNode(ListNode* previous,ListNode* next):
		_previous(previous),
		_next(next)
	{}													//构造函数

	~ListNode();										//析构函数

	int& data();										//返回结点数据

	int data() const;									//返回结点数据

	ListNode* &next();									//返回后向指针

	ListNode* next() const;								//返回后向指针

	ListNode* &previous();								//返回前向指针

	ListNode* previous() const;							//返回前向指针
};

class CPPList
{
private:
	int _size;
	ListNode* _begin;
	ListNode* _end;
public:
	CPPList()
	{
		_end = _begin =new ListNode(NULL,NULL);
	}													//构造函数

	CPPList(CPPList &List)
	{
		_end = _begin = new ListNode(NULL, NULL);
		ListNode *current;
		int idx;
		for (idx = 0, current = List.begin(); current != List.end(); current = List.next(current), ++idx)
		{
			append(current->data());
		}
	}													//拷贝构造函数

	~CPPList();											//析构函数

	ListNode* begin();									//返回头指针

	ListNode* begin() const;							//返回头指针

	ListNode* end();									//返回尾指针

	ListNode* end() const;								//返回尾指针

	int size();											//返回链表大小

	ListNode* next(ListNode *current);					//返回下一结点指针

	ListNode* next(const ListNode *current) const;		//返回下一结点指针

	void append(const int ele);							//增加元素

	void insert(ListNode* j, const int ele);			//在j位置插入数据为ele的结点

	void clear();										//清空链表

	void remove(ListNode* j);							//移除j位置结点
};

#endif