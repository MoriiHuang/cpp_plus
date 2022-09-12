#include<iostream>
using namespace std;
// static_cast,reinterpret_cast,const_cast和dynamic_cast
// static_cast 用来进用行比较“自然”和低风险的转换，比如整型和实数型，字符型之间相互转换
// static_cast 不能用来在不同类型的指针之间互相转换，，也不能用于整型和指针之间的相互转换，也不能用于不同类型的引用之间的转换
// static_cast示例
class A
{
private:
    /* data */
public:
    operator int() {return 1;}
    operator char*() {return NULL;}
};
// reinterpret_cast用来进行各种不同类型的指针之间的转换，不同类型的引用之间的转换
// 以及指针和能容纳得下指针的整数类型之间的转换。转换的时候执行的是逐个比特拷贝的操作
// reinterpret_cast示例
class B
{
private:
    /* data */
public:
    int i;
    int j;
    B(int n):i(n),j(n){};
};
// const_cast 用来进行去除const属性的转换。将const引用转换成同类型的非const引用
// 将const指针转换为同类型的非const指针时用它

// dynamic_cast专门用于将多态基类的指针或引用，强制转换为派生类的指针或引用，而且能够检查转换的安全性
// 对于不安全的指针转换，转换结果返回NULL指针
// dynamic_cast不能用于将非多态基类的指针或引用，强制转换为派生类的指针或引用
// dynamic_cast示例
class Base
{
private:
    /* data */
public:
    virtual ~Base(){};
};
class Derived:public Base
{
private:
    /* data */
public:
};



int main(){
    // static_cast示例
    cout<<"static_cast"<<endl;
    A a;
    int n;char *p="New Dragon Inn";
    n=static_cast<int>(3.14);
    cout<<n<<endl;
    n=static_cast<int>(a);
    cout<<n<<endl;
    p=static_cast<char*>(a);
    if(p==NULL){
        cout<<"p is NULL"<<endl;
    }
    // n=static_cast<int>(p);
    // p=static_cast<char*>(n);
    // reinterpret_cast示例
    cout<<"reinterpret_cast"<<endl;
    B b(100);
    int&r=reinterpret_cast<int&>(b);//强行让r引用b的前4个字节
    r=200;
    cout<<b.i<<","<<b.j<<endl;
    int b_n;
    B *pb=reinterpret_cast<B*>(&b_n);//强行让pb指向b_n
    pb->i=400;
    pb->j=500;//此语句不安全，可能导致程序崩溃
    cout<<b_n<<endl;
    long long la=0x12345678abcdLL;
    cout<<hex<<la<<endl; 
    pb=reinterpret_cast<B*>( la);
    uint64_t s=reinterpret_cast<uint64_t>(pb);
    cout<<hex<<s<<endl;
    typedef void(*PF1)(int);
    // typedef void (*F) (int)定义了一个指向函数的指针F，其返回值 void 类型，参数是后面的(int).
    // 然后我们就可以直接使用 F来定义这种指针变量，比如：F f(等价于void f(int))
    typedef int(*PF2)(int,char*);
    PF1 pf1; PF2 pf2;
    pf2=reinterpret_cast<PF2>(pf1);
    // const_cast示例
    const string ss="Inception";
    string &pp=const_cast<string &>(ss);
    string *pps =const_cast<string*>(&ss);
    // dynamic_cast示例
    Base bb;
    Derived dd;
    Derived *pd;
    pd=reinterpret_cast<Derived*>(&bb);
    if(pd==NULL){
        cout<<"unsafe reinterpret_cast"<<endl;
    }
    pd=dynamic_cast<Derived*>(&bb);
    if(pd==NULL){
        cout<<"unsafe dynamic_cast1"<<endl;
    }
    Base *pbb=&dd;
    pd=dynamic_cast<Derived*>(pbb);
    if(pd==NULL){
        cout<<"unsafe dynamic_cast2"<<endl;
    }
    return 0;
}