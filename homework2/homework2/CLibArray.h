#ifndef CLib
#define CLib
class CArray
{
	private:
	int *buff;
    int size;
    int capacity;

void initial(const int cap=20);                      //数组初始化

int capacity();                                   //返回数组容量

int recap(const int cap);                            //重新定义数组容量

void destroy();                                        //清除arr

public:
int size();                                       //返回数组大小

void copy(CArray &arr2);                        //将arr拷贝到arr2

void insertconst int j, const int ele);             //在arr index=i的位置插入元素ele

void append(const int ele);                          //增加元素
    
int& at(const int j=0);                         //返回在位置i的元素 

bool compare(const CArray arr,const CArray arr2);                 //比较arr和arr2
}

#endif