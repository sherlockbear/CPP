#include "stdafx.h"
#include "Vector.h"
#include <stdlib.h>


Vector::~Vector()											//析构函数
{
	_data.clear();
}

Vector& Vector::operator=(ValueType rhs)					//赋值
{
	_data.clear();
	for (int idx = 0; idx < _size; ++idx)
	{
		_data.push_back(rhs);
	}
	return *this;
}

Vector Vector::operator+(Vector &rhs) 						//加法
{
	if (_size != rhs.size())
		return Vector::INVALID_VECTOR;
	Vector result(*this);
	for (int idx = 0; idx < result.size(); ++idx)
	{
		result[idx] = result[idx] + rhs[idx];
	}
	return result;
}

Vector Vector::operator-(Vector &rhs)						//减法
{
	return *this + (-rhs);
}

Vector Vector::operator+(ValueType rhs) 					//加法
{
	Vector result(*this);
	for (int idx = 0; idx < result.size(); ++idx)
	{
		result[idx] = result[idx] + rhs;
	}
	return result;
}

Vector Vector::operator-(ValueType rhs)						//减法
{
	return *this + (-rhs);
}

Vector Vector::operator*(double rhs)						//数乘
{
	Vector result(*this);
	for (int idx = 0; idx < result.size(); ++idx)
	{
		result[idx] = result[idx] * rhs;
	}
	return result;
}

bool Vector::operator==(Vector &rhs)						//等于
{
	bool result = true;
	for (int idx = 0; idx < _size; ++idx)
	{
		result = result || (_data[idx] == rhs[idx]);
	}
	return result;
}

bool Vector::operator!=(Vector &rhs)						//不等于
{
	return !(*this == rhs);
}

Vector Vector::operator-()									//取负
{
	Vector result(*this);
	for (int idx = 0; idx < result.size(); ++idx)
	{
		result[idx] = -(result[idx]);
	}
	return result;
}

ValueType& Vector::operator[](int idx)						//取值
{
	return _data[idx];
}

int Vector::size() const
{
	return _size;
}

Vector Vector::INVALID_VECTOR = Vector(0, 0.0);