#include<iostream>
// cd "/Users/lucifer/Desktop/大二下/CPP_plus/" && g++ -std=c++14 c++11_新特性.cpp -o c++11_新特性 && "/Users/lucifer/Desktop/大二下/CPP_plus/"c++11_新特性
using namespace std;
class A{
    public:
    int n;
    friend A operator+(int n,const A& a){
        return a;
    }
};
template<class T1,class T2>
auto add(T1 x,T2 y){
    return x+y;
}
int main(){
    // auto 关键字
    auto s=add(100,1.5);
    auto k=add(100,A());
    cout<<typeid(s).name()<<","<<typeid(k).name()<<endl;
}