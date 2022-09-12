#include<iostream>
using namespace std;
// 为了区分前置还是后置，c++规定前置运算符作为一元运算符，后置运算符作为二元运算符，多写一个没用的参数
class Cdemo
{
private:
    /* data */
    int n;
public:
    Cdemo(int n=0);
    ~Cdemo();
    Cdemo(const Cdemo &c){
        n=c.n;
    }
    operator int(){
        return n;
    }
    Cdemo & operator++(){
        ++n;
        return *this;
    }
    Cdemo operator++(int k){
        Cdemo tmp(*this);
        n++;
        return tmp;
    }
friend  ostream &operator<<(ostream &os,Cdemo d){
    os<<d.n;
    return os;
}
friend Cdemo & operator--(Cdemo &s){
    s.n--;
    return s;
}
friend Cdemo operator--(Cdemo &s,int k){
    Cdemo tmp(s);
    s.n--;
    return tmp;
}
};

Cdemo::Cdemo(int i)
{
    n=i;
}

Cdemo::~Cdemo()
{
}

int main(){
    Cdemo d(5);
    cout<<(d++)<<",";
    cout<<d<<",";
    cout<<(++d)<<",";
    cout<<d<<endl;
    cout<<(d--)<<",";
    cout<<d<<",";
    cout<<(--d)<<",";
    cout<<d<<endl;
    return 0;
}