#include "stdafx.h"

#include <assert.h>
#include <iostream>

// 该测试用例中涉及的Vector.h及Matrix.h自行设计，逐渐熟悉并掌握类接口设计能力
// 建议可以先注释掉全部或大部分测试代码，从而以免在一开始因代码仅完成很少部分，产生太多编译错误
// 建议思考的方式为“我应该为Vector和Matrix提供什么接口，这些接口应当完成什么功能以满足他们的职责”为出发点，实现后通过测试用例验证
// 而非“我应该为Vector和Matrix提供什么接口，以能通过测试代码”为出发点，通不过一句，改一个函数，通过一句，就转移到下一个函数的方式
// 前者以对象为中心，考虑职责，在思考过程和实现过程中，类独立设计并实现，最终通过交互完成功能，类设计和实现的过程和测试代码的顺序无关，
// 仅与自身从测试代码中分析并融合出的职责需求有关
// 后者以过程为中心，考虑功能，思考过程和实现的过程中，以测试代码运行的顺序增加功能
// 最终提交Vector.h(cpp)与Matrix.h(cpp)四个文件，文件名固定
//
// 实验提交：
// 最终提交Vector.h(cpp)与Matrix.h(cpp)四个文件，文件名固定
// 文件打包成一个.zip或.rar格式的压缩包，以邮件附件形式发送。邮件主题与压缩包名一致。
// Email：esecpp2016@163.com
// 命名规范：学号+姓名+第几次作业+第几版（注意添加加号“+”）
// 截止时间：11月13日24：00前

#include "Vector.h"
#include "Matrix.h"


int _tmain(int argc, _TCHAR* argv[])
{
	// 通过传递元素素组初始化向量，最终将得到3个元素
	double data1[] = {3.4, 4.4, 6.0}; 
	Vector v(sizeof(data1) / sizeof(double), data1); 

	// 确保完备的初始化向量
	assert(v.size() == sizeof(data1) / sizeof(double)); 
	for (int idx = 0; idx < sizeof(data1) / sizeof(double); ++idx)
	{
		assert(v[idx] == data1[idx]); 
	}
	std::cout << "60" << std::endl; 

	// v的值应等于自身，且不会不等于自身
	assert(v == v); 
	assert(!(v != v));
	std::cout << "62" << std::endl; 

	// v + v按元素分别求和的结果，相当于每个元素直接与2相乘
	assert(v + v == v * 2); 
	std::cout << "64" << std::endl; 

	// v - v按元素分别求和的结果，相当于v加上v的相反数
	assert(v - v == v + (-v));
	std::cout << "68" << std::endl; 

	// v = 3的结果使向量的每个元素都变为3，因此等于直接初始化一个只有三个元素，且初始值为3的向量
	assert((v = 3) == Vector(sizeof(data1) / sizeof(double), 3)); 
	std::cout << "70" << std::endl; 

	// v + 3的结果使向量的每个元素都加上3，因此等于直接初始化一个只有三个元素，且初始值为6的向量
	// 而 v - 3则直接初始化一个只有三个元素，且初始值为0的向量
	assert(v + 3 == Vector(sizeof(data1) / sizeof(double), 6));
	assert(v - 3 == Vector(sizeof(data1) / sizeof(double), 0.0));
	std::cout << "74" << std::endl; 

	
	// 另行定义一个有十个元素，且每个元素值为5的向量
	Vector v2(10, 5); 

	// 确保其正确初始化
	assert(v2.size() == 10);
	for (int idx = 0; idx < v2.size(); ++idx)
	{
		assert(v2[idx] == 5); 
	}
	std::cout << "76" << std::endl; 

	// 两个元素个数不相等的向量相加，其结果为【无效向量】
	assert(v + v2 == Vector::INVALID_VECTOR); 
	std::cout << "77" << std::endl; 

	//////////////////////////////////////////////////
	// 通过传递元素素组初始化矩阵，3( 行) X 2(列) 矩阵为：
	// 1 1 
	// 1 1 
	// 1 1
	double data2[] = {1, 1, 1, 1, 1, 1}; 
	Matrix m1(3, 2, data2); 

	// m4等于m1乘以标量2，因此按元素分别求乘积，得到3( 行) X 2(列) 矩阵，为：
	// 2 2 
	// 2 2 
	// 2 2
	Matrix m4 = m1 * 2; 
	
	// 确保m1初始化正确，且与标量乘积正确
	assert(m4.rows() == 3); 
	assert(m4.cols() == 2); 
	for (int r = 0; r < 2; ++r)
	{
		for (int c = 0; c < 2; ++c)
		{
			assert(m4[r][c] == 2); 
		}
	}
	std::cout << "81" << std::endl; 

	// 以同样的数组初始化矩阵，但如果行数、列数不同，获得的矩阵也不同
	Matrix m2(6, 1, data2); 
	Matrix m3(3, 2, data2); 
	
	// 因此m1与m2同样有6个1，但行列不同，因此不相等
	assert(m1 != m2);
	// 只有m3这样的行列相同，元素相同，才应相等
	assert(m1 == m3); 
	std::cout << "85" << std::endl; 

	// 同样的结果可以通过直接初始化每个元素为一个相同的数值得到
	assert(m1 == Matrix(3, 2, 1)); 
	std::cout << "86" << std::endl; 

	// m1相加之后，应得到一个3行2列，元素全为2的矩阵
	assert(m1 + m1 == Matrix(3, 2, 2)); 
	// 但如果矩阵行列不同，无法直接相加，只能得到非法矩阵
	assert(m1 + m2 == Matrix::INVALID_MATRIX); 
	std::cout << "88" << std::endl; 

	// 同样，减法按元素相减，相当于加上相反数
	assert(m1 - m1 == m1 + (-m1)); 
	// 相反数的结果应正确
	assert(- m1 == Matrix(3, 2, -1)); 
	std::cout << "92" << std::endl; 

	// 在乘法中，如果矩阵行列不满足条件，只能得到非法矩阵
	assert(m1 * m1 == Matrix::INVALID_MATRIX); 
	// 满足乘法条件，m1与其转置矩阵的乘积((3 X 2) X (2 X 3))为3行3列元素为2矩阵
	assert(m1 * m1.trans() == Matrix(3, 3, 2)); 
	// 满足乘法条件，m1转置矩阵与m1的乘积((2 X 3) X (3 X 2))为2行2列元素为3矩阵
	assert(m1.trans() * m1 == Matrix(2, 2, 3));
	std::cout << "96" << std::endl; 

	// 向量可转化为矩阵与矩阵相乘，同样要满足矩阵乘法条件，由于v相当于1X3矩阵，元素为3，因此结果为1X2矩阵，元素为9
	assert(Matrix(v) * m1 == Matrix(1, 2, 9)); 
	// 改变顺序后也可通过转置获得另一个乘积，因此结果为2X1矩阵，元素为9，即相当于上面一个结果的转置
	assert(m1.trans() * Matrix(v).trans() == Matrix(2, 1, 9)); 
	std::cout << "100" << std::endl; 

	system("PAUSE");
	return 0;
}
