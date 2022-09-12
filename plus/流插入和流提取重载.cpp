#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class Student
{
private:
    int age;
public:
    Student(){
        age=3;
    }
    Student(int s=0){
        age=s;
    }
    ~Student(){

    }
    int getage() const{
        return age;
    }
};
class Complex
{
private:
    /* data */
    double real,imag;
public:
    Complex(double r=0,double i=0){
        real=r;imag=i;
    }
    ~Complex();
friend ostream &operator<<(ostream &os,const Complex &c);
friend istream &operator>>(istream &os,Complex &c);
};

Complex::~Complex()
{
}
ostream &operator<<(ostream &os,const Complex &c){
    os<<c.real<<"+"<<c.imag<<"i"<<endl;
    return os;
}
istream &operator>>(istream &is,Complex &c){
    string s;
    is>>s;
    int pos=s.find("+",0);
    string stmp=s.substr(0,pos);
    c.real=atof(stmp.c_str());
    stmp=s.substr(pos+1,s.length());
    c.imag=atof(stmp.c_str());
    return is;
}
ostream& operator<<(ostream &o,const Student &s){
    o<<s.getage();
    return o;
}
int main(){
    Student s(13);
    Complex c(1.2,1.3);
    cout<<c<<endl;
    cin>>c;
    cout<<c<<endl;
    cout<<s<<" "<<"xswl"<<endl;
}