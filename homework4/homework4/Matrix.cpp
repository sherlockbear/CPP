#include "stdafx.h"
#include "Vector.h"
#include "Matrix.h"
#include <stdlib.h>

Matrix::~Matrix()											//��������
{
	_data.clear();
}
#if 0
Matrix& Matrix::operator=(Vector rhs)						//��ֵ
{
	_data.clear();
	for (int idx = 0; idx < _size; ++idx)
	{
		_data.push_back(rhs);
	}
	return *this;
}
#endif
Matrix Matrix::operator+(Matrix &rhs) 						//�ӷ�
{
	if ((_rows != rhs.rows()) && (_cols != rhs.cols()))
		return Matrix::INVALID_MATRIX;
	Matrix result(*this);
	for (int i = 0; i < result.rows(); ++i)
	{
		for (int j = 0; j < result.cols(); ++j)
		{
			result[i][j] = result[i][j] + rhs[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator-(Matrix &rhs)						//����
{
	return *this + (-rhs);
}
#if 0
Matrix Matrix::operator+(Vector rhs) 						//�ӷ�
{
	Matrix result(*this);
	for (int idx = 0; idx < result.size(); ++idx)
	{
		result[idx] = result[idx] + rhs;
	}
	return result;
}

Matrix Matrix::operator-(Vector rhs)						//����
{
	return *this + (-rhs);
}
#endif
Matrix Matrix::operator*(double rhs)						//����
{
	Matrix result(*this);
	for (int i = 0; i < result.rows(); ++i)
	{
		for (int j = 0; j < result.cols(); ++j)
		{
			result[i][j] = result[i][j] * rhs;
		}
	}
	return result;
}

Matrix Matrix::operator*(Matrix &rhs)						//����˷�
{
	if (_cols != rhs.rows())
		return Matrix::INVALID_MATRIX;
	Matrix result(_rows, rhs.cols(), 0.0);
	for (int i = 0; i < result.rows(); ++i)
	{
		for (int j = 0; j < result.cols(); ++j)
		{
			for (int idx = 0; idx < _cols; ++idx)
			{
				result[i][j] = result[i][j] + (*this)[i][idx] * rhs[idx][j];
			}
		}
	}
	return result;
}

bool Matrix::operator==(Matrix &rhs)						//����
{
	if ((_rows != rhs.rows()) && (_cols != rhs.cols()))
		return false;
	bool result = true;
	for (int i = 0; i < _rows; ++i)
	{
		for (int j = 0; j < _cols; ++j)
		{
			result = result || (*_data[i] == rhs[i]);
		}
	}
	return result;
}

bool Matrix::operator!=(Matrix &rhs)						//������
{
	return !(*this == rhs);
}

Matrix Matrix::operator-()									//ȡ��
{
	Matrix result(*this);
	for (int i = 0; i < _rows; ++i)
	{
		for (int j = 0; j < _cols; ++j)
		{
			result[i][j] = -result[i][j];
		}
	}
	return result;
}

Matrix Matrix::trans()												//ת��
{
	Matrix result(_cols, _rows, 0.0);
	for (int i = 0; i < result.rows(); ++i)
	{
		for (int j = 0; j < result.cols(); ++j)
		{
			result[i][j] = (*this)[j][i];
		}
	}
	return result;
}

Vector& Matrix::operator[](int idx)							//ȡ������
{
	return *_data[idx];
}

int Matrix::rows()
{
	return _rows;
}
int Matrix::cols()
{
	return _cols;
}

Matrix Matrix::INVALID_MATRIX = Matrix(0, 0, 0.0);
