#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 若一个类重载了运算符“（）”，则该类的对象就为函数对象
// STL中的函数对象类模板 equal_to,greater,less.......头文件<functional>

class CMyAverage
{
public:
    double operator()(int a1,int a2,int a3){
        return (double)(a1+a2+a3)/3;
    }
};
template<class T>
void PrintInterval(T first,T last){
    for(;first!=last;++first){
        cout<<*first<<" ";
    }
    cout<<endl;
}
template<class T>
class SumPower
{
private:
    int power;
public:
    SumPower(int p):power(p){};
    const T operator()(const T &total,const T &value){
        T v=value;
        for(int i=0;i<power-1;i++){
            v=v*value;
        }
        return total+v;
    }
};

// greater的用法
class MyLess
{

public:
    bool operator()(const int &c1,const int &c2){
        return (c1%10)<(c2%10);
    }
};
template<class T>
void Print(T first,T last){
    for(;first!=last;first++) cout<<*first<<",";
    cout<<endl;
}
bool Mycompare(int a1,int a2){
    return (a1%10)>(a2%10);
}
template<class T,class op>

T MyMax(T first,T last,op myless){
    T tmpMax=first;
    for(;first!=last;first++){
        if(myless(*tmpMax,*first)){
            tmpMax=first;
        }
    }
    return tmpMax;
}   


int main(){
    CMyAverage aver;
    cout<<aver(3,2,3)<<endl;
    int total=10;
    SumPower<int> sp(3);
    int a1[]={1,2,3,4,5};
    vector<int> a(a1,a1+5);
    vector<int>::iterator i;
    int result;
    for(i=a.begin();i!=a.end();i++){
        result=sp(total,*i);
    }
    cout<<result<<endl;
    int tmp[]={35,227,1145113,19,12};
    cout<<*MyMax(tmp,tmp+5,MyLess())<<endl;
    cout<<*MyMax(tmp,tmp+5,Mycompare)<<endl;
}
