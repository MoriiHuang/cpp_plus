#include<iostream>
using namespace std;
// 虚析构函数：通过基类的指针删除派生类对象时，通常情况下只调用基类的析构函数
// 但是，删除一个派生类的对象时，应该先调用派生类的析构函数，然后调用基类的析构函数。
// 解决方法：把基类的析构函数声明为virtual
// 派生类的析构函数可以virtual不进行声明
// 通过基类的指针删除派生类对象时，首先调用派生类的析构函数，然后调用基类析构函数
// 构造函数不能为虚函数
// 包含纯虚函数的类叫抽象类
// 抽象类只能作为基类来派生新类使用，不能创建抽象类的对象
// 抽象类的指针和引用可以指向由抽象类派生出来的类的对象
// 在抽象类的成员函数内可以调用纯虚函数，但是在构造函数或析构函数中不能
// 如果一个类从抽象类派生而来，那么当且仅当他实现了基类中的所有纯虚函数，它才能成为非
// 抽象类 
class son
{
public:
    // ~son();
    virtual ~son();
};
son::~son()
{
    cout<<"descontructed::son"<<endl;
}
class grandson:public son
{
public:
    ~grandson();
};

grandson::~grandson()
{
    cout<<"descontructed::grandson"<<endl;
}
// 纯虚函数：没有函数体的虚函数
class A
{
private:
    int a;
public:
    virtual void Print()=0;
    void fun(){cout<<"fun";}
};
int main(){
    son *pson;
    pson = new grandson();
    delete pson;
    return 0;
}