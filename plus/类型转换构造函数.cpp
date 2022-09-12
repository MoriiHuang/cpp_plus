#include<iostream>
using namespace std;
// 定义转换构造函数的目的是实现类型的自动转换
// 只有一个参数，而且不是复制构造函数的构造函数，一般可以看做是转换构造函数
// 当需要的时候，编译系统会自动调用转换构造函数，建立一个无名的临时对象
class  Complex
{
private:
    /* data */
public:
    double real,imag;
     Complex(int i){
        cout<<"IntConstructor called"<<endl;
        real=i;imag=0;
     }
     Complex(double r, double i){
        real=r;
        imag=i;
     }
    ~ Complex(){
        cout<<"Destructor called"<<endl;
    }
};
Complex func(Complex sobj){ // 参数对象消亡也会调用析构函数
    return sobj;
}

int main(){
    Complex c1(7,8);
    Complex c2(8);
    cout<<"start1"<<endl;
    c1=9;    // 此时c1是临时生成的，执行完后消亡
    cout<<"end"<<endl;
    cout<<"start2"<<endl;
    cout<<c1.real<<","<<c1.imag<<endl;
    cout<<"endl"<<endl;
    c1=func(c1);
}