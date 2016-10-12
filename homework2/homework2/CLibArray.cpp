//#include "stdafx.h"

void CArray::initial(CArray &arr, const int cap = 20)        				//数组初始化
{
    arr.capacity = cap;
    arr.buff = new int(arr.capacity);
    arr.size = 0;
}

int CArray::capacity(const CArray arr)                          			//返回数组容量
{
	return arr.capacity;
}

void CArray::copy(const CArray arr, CArray &arr2)							//将arr拷贝到arr2
{
	initial(arr2, arr.capacity);
	for (int i = 0; i<arr.size; i++)
	{
		*(arr2.buff + i) = *(arr.buff + i);
	}
    arr2.size = arr.size;
}

int CArray::recap(CArray &arr, const int newcap)                   		//重新定义数组容量
{
	if (newcap < arr.size)
		return 1;
	arr.capacity = newcap;
	int *newbuff;
	newbuff = new int(newcap);
	for (int i = 0; i<arr.size; i++)
	{
		*(newbuff + i) = *(arr.buff + i);
	}
	arr.buff = newbuff;
	#if 0
	int capaug = newcap - arr.capacity;
	CArray arr2;
	copy(arr, arr2);
	initial(arr);
	copy(arr2, arr, capaug);
	#endif
	return 0;
}

void CArray::insert(CArray &arr, const int j, const int ele)    			//在arr index=j的位置插入元素ele
{
	arr.size++;
	if (arr.size>arr.capacity)
	{
		recap(arr, arr.capacity + 10);
	}
	for (int i = arr.size-1; i>j; i--)
	{
		*(arr.buff + i) = *(arr.buff + i - 1);
	}
	*(arr.buff + j) = ele;
}

int CArray::size(const CArray arr)                               			//返回数组大小
{
	return arr.size;
}

void CArray::append(CArray &arr, const int ele)                  			//增加元素
{
    arr.size++;
	if (arr.size>arr.capacity)
	{
		recap(arr, arr.capacity + 10);
	}
	*(arr.buff + arr.size - 1) = ele;
}

int& CArray::at(const CArray arr, const int j=0)                   		//返回在位置j的元素 
{
	return *(arr.buff + j);
}

bool CArray::compare(const CArray arr,const CArray arr2)        			//比较arr和arr2
{
    int size;
    if (arr.size>arr2.size)
		size = arr.size;
    else
		size = arr2.size;
    for(int i=0;i<size;i++)
    {
        if (at(arr, i) ==at(arr2,i))
			continue;
        else
			return false;
    }
    return true;
}

void CArray::destroy(CArray &arr)                                 		//清除arr
{
	memset(&arr, 0, sizeof(arr));
}