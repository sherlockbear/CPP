#ifndef VECTOR
#define VECTOR

#include <vector>

typedef double ValueType;

class Vector
{
private:
	std::vector<ValueType> _data;
	int _size;
public:
	Vector(int size,ValueType data[]):_size(size)
	{
		for (int idx = 0; idx < _size; ++idx)
		{
			_data.push_back(data[idx]);
		}
	}													//构造函数

	Vector(int size, ValueType data) :_size(size)
	{
		for (int idx = 0; idx < _size; ++idx)
		{
			_data.push_back(data);
		}
	}													//构造函数

	Vector(Vector &rhs)
	{
		_size = rhs.size();
		for (int idx = 0; idx < _size; ++idx)
		{
			_data.push_back(rhs[idx]);
		}
	}													//拷贝构造函数

	~Vector();											//析构函数

	Vector& operator=(ValueType rhs);					//赋值

	Vector operator+(Vector &rhs);						//加法

	Vector operator-(Vector &rhs);						//减法

	Vector operator+(ValueType rhs); 					//加法

	Vector operator-(ValueType rhs);					//减法

	Vector operator*(double rhs);						//数乘

	bool operator==(Vector &rhs);						//等于

	bool operator!=(Vector &rhs);						//不等于

	Vector operator-();									//取负

	ValueType& operator[](int idx);						//取值

	int size() const;
	
	static Vector INVALID_VECTOR;
};
#endif