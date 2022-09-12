#include<iostream>
using namespace std;
// 
const int MAX_VAL=23;
const double pi=3.14;
const char* SCHOOL_NAME="Shanghai JiaoTong University"; 
int main(){
    // 引用 类型名 & 引用名 = 某变量名 等价于某个对象，相当于改变量的别名
    // 不可以通过常量指针修改其指向的内容
    int n,m;
    const int* p =&n;
    n=4;
    p=&m; // 常量指针的指向可以被修改
    // *p=5; 编译报错
    // 不能把 常量指针 赋值 给非常量指针，反过来可以
    const int *p1;int* p2;
    p1=p2;
    // p2=p1; 常量指针指向的地方不应该被修改
    p2 = (int *) p1; // 强制类型转换

}
