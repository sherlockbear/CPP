#ifndef CLib
#define CLib
class CArray
{
private:
	int _capacity;
	int *buff;
	int _size;

	CArray(const int cap = 20):_capacity(cap), buff(new int(_capacity)), _size(0){}
														//声明一个有参构造函数
	~CArray();											//析构函数
	int capacity();										//返回数组容量

	int recap(const int cap);							//重新定义数组容量

	void format(const int cap = 20);        			//数组格式化

	

public:
	int size();											//返回数组大小

	void copy(CArray &arr,const int capaug = 0);		//将当前数组拷贝到arr

	void insert(const int j, const int ele);			//在index=i的位置插入元素ele

	void append(const int ele);							//增加元素

	int& at(const int j = 0);							//返回在位置i的元素 

	bool compare(const CArray arr2);					//比较当前数组和arr
};

#endif