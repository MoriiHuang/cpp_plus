#include<iostream>
using namespace std;
// 模板函数的重载，只要它们的形参表或者类型参数表不同即可
// 匹配模板函数时，不进行类型自动转换 
template<class T,class Pred>
void Map(T s,T e,T x,Pred op){
    for(;s!=e;++s,++x){
        *x=op(*s);
    }
}
template<class S>
S Cube(S x){
    return x*x*x;
}
template<class S>
S Square(S x){
    return x*x;
}
template<class T>
void swap(T &x,T &y){
    T tmp=x;
    x=y;
    y=tmp;
}
int main(){
    int a[5]={1,2,3,4,5},b[5];
    double d[5]={1.1,1.2,1.3,1.4,1.5},c[5];
    Map(a,a+5,b,Square<int>);
    for (int i=0;i<5;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    Map(a,a+5,b,Cube<int>);
    for (int i=0;i<5;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    Map(d,d+5,c,Square<double>);
    for (int i=0;i<5;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
}