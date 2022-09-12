#include<iostream>
using namespace std;
// 其作用就是指向成员函数所作用的对象
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
    void Print(){
        cout<<real<<","<<imag<<endl;
    }
    void hello(){// void hello(Complex *this)
        cout<<"hello"<<endl;
    }
    Complex Addone(){
        this->real++;
        this->Print();
        return *this;
    }
};
int main(){
    Complex c1(1,1),c2(0,0);
    c2=c1.Addone();
    Complex c3=NULL;
    c3.hello();// hello(p)
}