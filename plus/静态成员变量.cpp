#include<iostream>
using namespace std;
// 静态成员：在说明前加了static关键字的成员变量。
// 普通成员变量每个对象有各自的一份，静态成员变量所有对象共享一份
// 普通成员函数必须具体作用于某个对象，而静态成员并不具体作用于某个对象
// 不需要通过对象就能访问
// 静态成员变量本质上也是一个全局变量，静态成员函数本质上也是全局函数
// 设置惊涛成员这种机制的目的是将和某些类紧密相关的全局变量和函数写到类里面，易于维护和理解
// 如何访问静态成员： 1）类名::成员名 2）对象名.成员名 3）指针->成员名
class Csample
{
private:
    int w,h;
    static int ntotal;//要作为全局变量声明
public:
    Csample(int w_,int r_){
        w=w_;
        h=r_;
        ntotal+=w*h;
        // 此处的缺陷是，有时会调用复制构造函数生成临时的隐藏的Crectangle对象，消亡时析构会减少
    }
    Csample (const Csample &r){
        w=r.w;
        h=r.h;
        ntotal+=w*h;
    }
    ~Csample(){
        ntotal-=w*h;
    }
    static void PrintTotal(){//在静态成员函数中，不能访问非静态成员变量，也不能调用非静态成员函数
        cout<<ntotal<<endl;
    }
};
int Csample::ntotal=0;
int main(){
    Csample r1(1,4),r2(3,5);
    {
        Csample r3(5,12);
        Csample::PrintTotal();
    }
    Csample::PrintTotal();
    r1.PrintTotal();
    return 0;
} 