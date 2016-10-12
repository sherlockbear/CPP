#ifndef CLib
#define CLib

typedef struct                                                          //定义扩展数组结构体
{
    int *buff;
    int size;
    int capacity;
}CArray;

void array_initial(CArray &arr, const int cap=20);                      //数组初始化

int array_capacity(const CArray arr);                                   //返回数组容量

void array_copy(const CArray arr, CArray &arr2, const int capaug = 0);  //将arr拷贝到arr2

int array_recap(CArray &arr, const int cap);                            //重新定义数组容量

void array_insert(CArray &arr, const int j, const int ele);             //在arr index=i的位置插入元素ele

int array_size(const CArray arr);                                       //返回数组大小

void array_append(CArray &arr, const int ele);                          //增加元素
    
int& array_at(const CArray arr, const int j=0);                         //返回在位置i的元素 

bool array_compare(const CArray arr,const CArray arr2);                 //比较arr和arr2

void array_destroy(CArray &arr);                                        //清除arr

#endif