#include<iostream>
using namespace std;
class base
{
public:
    void fun1(){this->func2();}//this 是基类指针，fun2是虚函数，所以是多态
    virtual void func2(){
        cout<<"Base::func2()"<<endl;
    }
};
class Derived:public base
{
public:
    virtual void func2(){cout<<"Derived:fun2()"<<endl;}
};
class Myclass
{
private:
    /* data */
public:
    virtual void hello(){cout<<"hello from myclass"<<endl;}
    virtual void bye(){cout<<"bye from myclass"<<endl;};
};
class son:public Myclass
{
private:
    /* data */
public:
    void hello(){cout<<"hello from son"<<endl;}
    son(){hello();}
    ~son(){bye();}
};

class grandson:public son
{
private:
    /* data */
public:
    void hello(){cout<<"hello from grandson"<<endl;}
    grandson(){cout<<"construtor::grandson"<<endl;}
    ~grandson(){cout<<"desstrutor::grandson"<<endl;}
};


int main(){
    Derived d;
    base *pbase =&d;// 在非构造函数，非析构函数的成员函数中调用虚函数，是多态
    // 在构造函数和析构函数中调用虚函数，不是多态编译时即可确定，调用的函是自己的类或者
    // 基类中定义的函数，不会等到运行时才决定是自己还是派生类
    // 派生类中和基类中虚函数同名同参数表的函数，不加virtual也自动成为虚函数
    grandson gson;
    son *pson;
    pson=&gson;
    pson->hello();
    pbase->fun1();
    return 0;
}