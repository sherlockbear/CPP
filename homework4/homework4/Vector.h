#ifndef VECTOR
#define VECTOR

class Vector
{
private:
	CArray _data;
public:
	Vector(int size,ValueType data[])
	{
		
	}													//构造函数

	Vector(Vector &List)
	{
		
	}													//拷贝构造函数

	~Vector();											//析构函数

	Vector& operator=(const Vector &rhs);				//赋值

	Vector operator+(const Vector &rhs) const;			//加法

	Vector operator-(const Vector &rhs) const;			//减法

	Vector operator*(const int &rhs) const;				//数乘

	bool operator==(const Vector &rhs) const;			//等于

	bool operator!=(const Vector &rhs) const;			//不等于

	Vector operator-() const;							//取负
};

#endif