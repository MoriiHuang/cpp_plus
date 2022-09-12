#include<iostream>
using namespace std;
class Base
{
public:
    int i;
    virtual void Print(){cout<<"Base:Print";}
};
class Derived: public Base{
public:
    int n;
    virtual void Print(){cout<<"Derived:Print"<<endl;}
};
class A
{
public:
    virtual void Func(){
        cout<<"A::Func"<<endl;
    }
};
class B:public A
{

public:
    virtual void Func(){
        cout<<"B::Func"<<endl;
    }
};



int main(){
    Derived d;
    cout<<sizeof(Base)<<","<<sizeof(Derived)<<endl;
    // 这里由于字节对齐的原因与预想值有差异
    A a;
    A *pa=new B();
    pa->Func();
    long long *p1=(long long*) &a;
    long long *p2=(long long*) pa;
    *p2=*p1;
    pa->Func(); 
}