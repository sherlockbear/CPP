#include "stdafx.h"
#include "Vector.h"
#include <stdlib.h>


Vector::~Vector()											//��������
{
	_data.clear();
}

Vector& Vector::operator=(ValueType rhs)					//��ֵ
{
	_data.clear();
	for (int idx = 0; idx < _size; ++idx)
	{
		_data.push_back(rhs);
	}
	return *this;
}

Vector Vector::operator+(Vector &rhs) 						//�ӷ�
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

Vector Vector::operator-(Vector &rhs)						//����
{
	return *this + (-rhs);
}

Vector Vector::operator+(ValueType rhs) 					//�ӷ�
{
	Vector result(*this);
	for (int idx = 0; idx < result.size(); ++idx)
	{
		result[idx] = result[idx] + rhs;
	}
	return result;
}

Vector Vector::operator-(ValueType rhs)						//����
{
	return *this + (-rhs);
}

Vector Vector::operator*(double rhs)						//����
{
	Vector result(*this);
	for (int idx = 0; idx < result.size(); ++idx)
	{
		result[idx] = result[idx] * rhs;
	}
	return result;
}

bool Vector::operator==(Vector &rhs)						//����
{
	bool result = true;
	for (int idx = 0; idx < _size; ++idx)
	{
		result = result || (_data[idx] == rhs[idx]);
	}
	return result;
}

bool Vector::operator!=(Vector &rhs)						//������
{
	return !(*this == rhs);
}

Vector Vector::operator-()									//ȡ��
{
	Vector result(*this);
	for (int idx = 0; idx < result.size(); ++idx)
	{
		result[idx] = -(result[idx]);
	}
	return result;
}

ValueType& Vector::operator[](int idx)						//ȡֵ
{
	return _data[idx];
}

int Vector::size() const
{
	return _size;
}

Vector Vector::INVALID_VECTOR = Vector(0, 0.0);