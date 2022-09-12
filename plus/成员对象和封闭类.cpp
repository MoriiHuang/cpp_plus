#include<iostream>
using namespace std;
// 有成员对象的类叫封闭类
// 任何生成封闭类对象的语句，都要让编译器明白，对象中的成员对象，是如何初始化的。
// 具体来说，就是通过封闭类的构造函数的初始化列表
// 先执行所有对象成员的构造函数，再执行封闭类的构造函数
// 对象成员的构造函数调用次序和对象成员在类中的说明次序一致，与他们在成员初始化列表中的次序无关。
// 析构的调用和构造函数的调用次序相反
class Ctype
{
private:
    /* data */
    int radius;
    int width;
public:
    Ctype(int r,int w):radius(r),width(w){cout<<"Ctype constructor"<<endl;}
    Ctype(const Ctype &c){
        radius=c.radius;
        width=c.width;
        cout<<"copy called"<<endl;}
    ~Ctype(){cout<<"Ctype destructor"<<endl;}
};
class Cenge
{
private:
    /* data */
public:
    Cenge(/* args */){cout<<"Cenge constructor"<<endl;}
    ~Cenge(){cout<<"Cenge destructor"<<endl;}
};
class Cc
{
private:
    /* data */
    int price;
    Ctype ty;
    Cenge ge;
public:
    Cc(int p, int tr,int tw):price(p),ty(tr,tw){cout<<"Cc constructor"<<endl;}
    ~Cc(){cout<<"Cc destructor"<<endl;}
};

int main(){
    Cc c1(1,3,4),c2(c1);
    return 0;
}