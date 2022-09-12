#include<iostream>
using namespace std;
// 只有一个参数，即对同类对象的引用
// 形如X::X(X&)或X::X(const X &) 后者能以常量对象作为参数
// 如果没有定义复制构造函数，那么编译器生成默认复制构造函数。默认的复制构造函数完成复制功能
class Complex
{
private:
    double real,imag;
public:
    int verti;
    Complex(){
        verti=3;
    }
    Complex(int n){
        verti=n;
    }
    ~Complex(){}
    Complex(const Complex &c){//只能是引用不是对象
        real=c.real;
        imag=c.imag;
        verti=c.verti;
        cout<<"Copy constructor Called"<<" ";
    }
};
void Func(Complex c1){
    cout<<c1.verti<<endl;
}
Complex FuncC(){
    Complex c(4);
    return c;
}
int main(){
    Complex c1;
    Complex c2(c1); 
    // 如果某函数有一个参数是类A的对象，那么函数调用是，类A的复制构造函数将被调用
    // 但是这样调用时生成形参会应发复制构造函数，开销比较大。所以可以用常量引用函数
    // fun（const Complex &c）
    Func(c2);
    // 如果某函数的返回值是类A的对象，那么函数调用是，类A的复制构造函数将被调用,但是实践起来好像不是这样
    cout<<FuncC().verti<<endl;
}