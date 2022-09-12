#include<iostream>
using namespace std;
// 派生类可以定义一个和基类成员同名的成员，这叫做覆盖。派生类中访问这类成员时，缺省的
// 情况是访问派生类中定义的成员。要在派生类中访问由基类定义的同名成员时，要使用
// 作用域符号：：
class base
{
private:
    /* data */
    int j;
public:
    int i;
    base(/* args */);
    ~base();
    void func(){
        cout<<"base"<<endl;
    }
};

base::base(/* args */)
{
}

base::~base()
{
}
class derive:public base
{
private:
    /* data */
public:
    int i;
    void func(){
        cout<<"derived"<<endl;
    }
    void access(){
        i=1;//派生类
        base::i=5;
        base::func();
        func();
    }
    derive(/* args */);
    ~derive();
};

derive::derive(/* args */)
{
}

derive::~derive()
{
}

int main(){
    derive obj;
    obj.access();
    cout<<obj.i<<" "<<obj.base::i<<endl;
}