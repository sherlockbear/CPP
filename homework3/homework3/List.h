#ifndef CLib
#define CLib

class ListNode
{
private:
	int _data;
	ListNode* _next;

public:
	ListNode(ListNode* next):
		_next(next)
	{}

	~ListNode();

	int& data();

	ListNode* next();
};

class CPPList
{
private:
	int _capacity;
	int *buff;
	int _size;
	ListNode* _begin;
	ListNode* _end;

	int capacity();										//返回数组容量

	int recap(const int cap);							//重新定义数组容量

public:

	CPPList(const int cap = 20) :
		_capacity(cap),
		buff(new int[_capacity]),
		_size(0)
	{}													//声明一个有参构造函数

	~CPPList();											//析构函数

	ListNode* begin();									//返回头指针

	ListNode* end();									//返回尾指针

	int size();											//返回链表大小

	ListNode* next(ListNode *current);					//返回下一结点指针

	void append(const int ele);							//增加元素

	void insert(ListNode* j, const int ele);			//在j位置插入数据为ele的结点

	void clear();										//清空链表

	void remove(ListNode* j);							//移除j位置结点
};

#endif