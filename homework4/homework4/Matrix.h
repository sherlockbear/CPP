#ifndef MATRIX
#define MATRIX

#include <vector>

class Matrix
{
private:
	std::vector<Vector*> _data;
	int _rows, _cols;
public:

	Matrix(int row, int column, ValueType data[]) :_rows(row), _cols(column)
	{
		for (int i = 0; i < _rows; ++i)
		{
			Vector* v = new Vector(_cols,0.0);
			for (int j = 0; j < _cols; ++j)
			{
				((*v)[j]) = data[(i*_cols)+j];
			}
			_data.push_back(v);
		}
	}													//构造函数
	
	Matrix(int row, int column, ValueType data) :_rows(row), _cols(column)
	{
		for (int i = 0; i < _rows; ++i)
		{
			Vector* v = new Vector(_cols, 0.0);
			for (int j = 0; j < _cols; ++j)
			{
				((*v)[j]) = data;
			}
			_data.push_back(v);
		}
	}													//构造函数
	
	Matrix(Vector data) :_rows(1), _cols(data.size())
	{
		Vector* v = new Vector(data);
		_data.push_back(v);
	}													//构造函数

	Matrix(Matrix &rhs)
	{
		_rows = rhs.rows();
		_cols = rhs.cols();
		for (int i = 0; i < _rows; ++i)
		{
			Vector* v = new Vector(rhs[i]);
			_data.push_back(v);
		}
	}													//拷贝构造函数

	~Matrix();											//析构函数
#if 0
	Matrix& operator=(Vector rhs);						//赋值
#endif
	Matrix operator+(Matrix &rhs);						//加法

	Matrix operator-(Matrix &rhs);						//减法
#if 0
	Matrix operator+(Vector rhs); 						//加法

	Matrix operator-(Vector rhs);						//减法
#endif
	Matrix operator*(double rhs);						//数乘

	Matrix operator*(Matrix &rhs);						//矩阵乘法

	bool operator==(Matrix &rhs);						//等于

	bool operator!=(Matrix &rhs);						//不等于

	Matrix operator-();									//取负

	Matrix trans();									//转置

	Vector& operator[](int idx);						//取值

	int rows();

	int cols();

	

	static Matrix INVALID_MATRIX;
};
#endif