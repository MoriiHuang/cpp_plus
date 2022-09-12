#include<iostream>
#include<stdexcept>//异常类 常用的有 bad_cast,out_of_range
// 需要一种手段：把异常与函数的接口分开，并且能够区分不同的异常
// 在函数体外捕获所发生的异常，并且提供更多的异常信息
using namespace std;
class CException{
    public:
    string msg;
    CException(string s):msg(s){}
};
double Devide(double x,double y){
    if(y==0){
        throw CException("divided by zero");
    }
    cout<<"in Devide"<<endl;
    return x/y;
}
int CountTax(int salary){
    try{
        if(salary<0)
            throw -1;
        cout<<"counting tax"<<endl;
    }
    catch(int ){
        cout<<"salary<0"<<endl;
    }
    cout<<"tax counted"<<endl;
    return salary*0.15;
}
int main(){
    // try,catch处理异常
    double m,n;
    cin>>m>>n;
    try{
        cout<<"before dividing"<<endl;
        if(n==0){
            throw -1;
        }
        else if(m==0){
            throw -1.0;
        }
        else
            cout<<m/n<<endl;
        cout<<"after diciding";
    }
    catch(double d){
        cout<<"catch(double)"<<d<<endl;
    }
    catch(...){
        cout<<"catch(...)"<<endl;
    }
    cout<<"finished"<<endl;
    // 异常的再抛出
    // 如果一个函数在执行的过程中，抛出的异常在本函数内就被catch块捕获并处理了，那么该异常就不会抛给这个
    // 函数的调用者（也就是上一层函数）；如果异常在本函数没被处理，就会被抛给上一层的函数
    double f=1.2;
    try{
        CountTax(-1);
        f=Devide(3,0);
        cout<<"end of try block"<<endl;
    }
    catch(CException e){
        cout<<e.msg<<endl;
    }
    cout<<"f="<<f<<endl;
    cout<<"finished"<<endl;
    return 0;
}