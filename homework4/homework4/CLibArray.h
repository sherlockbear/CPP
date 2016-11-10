#ifndef CLib
#define CLib
typedef double ValueType;

class CArray
{
private:
	ValueType _capacity;
	ValueType *buff;
	int _size;

	int capacity();										//返回数组容量

	int recap(const int cap);							//重新定义数组容量

public:

	CArray(const int cap = 2):
		_capacity(cap), 
		buff(new ValueType[_capacity]), 
		_size(0)
	{}													//声明一个有参构造函数
	
	~CArray();											//析构函数

	int size();											//返回数组大小

	void copy(CArray &arr);								//将arr拷贝到当前数组

	void insert(const int j, const ValueType ele);		//在index=i的位置插入元素ele

	void append(const ValueType ele);					//增加元素

	ValueType& at(const int j = 0);						//返回在位置i的元素 

	bool compare(CArray &arr);							//比较当前数组和arr
};

#endif