#include<iostream>
using namespace std;
// 赋值函数=只能重载成成员函数
class Complex
{
private:
    /* data */
    double real;
    double imag;
public:
    Complex(double r,double i):real(r),imag(i){    }
    ~Complex(){
    }
    Complex operator-(const Complex &c){
        return Complex(this->real-c.real,this->imag-c.imag);
    }
friend Complex operator+(const Complex &a,const Complex &b);
friend void showdata(const Complex &c){
    cout<<c.real<<" "<<c.imag<<endl;
}
};
Complex operator+(const Complex &a,const Complex &b){
    return Complex(a.real+b.real,a.imag+b.imag);
}
// 浅拷贝和深拷贝：没有自己定义的赋值运算符，那么S1=S2实际上导致S1.str和S2.str指向同一地方
// 会导致两者在析构，赋值等时会出现问题,因此需要添加第二个赋值函数
class String
{
private:
    /* data */
    char* str;
public:
    String(/* args */){}
    ~String(){}
    const char * c_str(){return str;}
    String (String &s){
        str=new char[strlen(s.str)+1];
        strcpy(str,s.str);
    }
    String & operator =(const char* s){
        delete [] str;
        str=new char[strlen(s)+1];
        strcpy(str,s);
        return *this;
    }
    String & operator =(const String &s){
        cout << "operator =" << endl;
        if (this == &s) 
            return *this;   
        else{
        delete [] str;
        str=new char[strlen(s.str)+1];
        strcpy(str,s.str);
        return * this;
        }
    }
};

int main(){
    Complex a(1.2,32.2);
    Complex b(23.2,11.0);
    Complex c(11.2,23.0);
    Complex d=a+b;
    Complex e=a-c;
    showdata(d);
    showdata(e);
    String s;
    s="hello world";
    cout<<s.c_str()<<endl;
    // 实验为什么应该写成&String
    String m1;
    m1="sda";
    String m2;
    m2="happy";
    String m3;
    m3="nb";
    cout<<m1.c_str()<<endl;
    cout<<(m1=m2).c_str()<<endl;
}