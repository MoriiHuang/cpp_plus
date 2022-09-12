#include<iostream>
using namespace std;
// 用new 运算符实现动态内存分配
// 第一种用法，分配一个变量 P=new T; P是类型 T* 的指针。动态分配出一片大小为sizeof（T）字节的内存空间
// 并且将改内存空间的起始地址赋值给 P
// 第二种用法，分配一个数组 P=new T【N】; P是类型 T* 的指针。动态分配出一片大小为N*sizeof（T）字节的内存空间
// 并且将改内存空间的起始地址赋值给 P
// 用 “new” 动态分配的内存空间，一定要用“delete”运算符进行释放 释放数组时，用“delete【】”
int main(){
    int* pn;
    pn = new int;
    *pn =5;
}