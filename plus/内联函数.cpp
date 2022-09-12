#include<iostream>
using namespace std;
// 内联函数：函数调用是有时间开销的，如果函数本身只有几条语句，而且会被反复调用，相比之下调用函数所
// 产生的这个开销会显得比较大。为了减少函数调用的开销，引入了内联函数机制。编译器处理对内联函数的
// 调用语句时，是将整个函数的代码插入到调用语句处，而不会产生调用函数的语句
// 函数的重载（成员函数也适用） 一个或多个函数，名字相同，然而参数个数或参数类型不相同，这叫做函数的重载。编译器根据
// 调用语句中的实参的个数和类型来判断调用那个函数
// 函数缺省值（成员函数也适用），定义函数时可以让最右边若干个参数有缺省值

inline int Max(int a,int b){
    if (a>b) return a;
    return b;
}
int Max(double a, double b){
    if (a>b) return a;
    return b;
}
class Crectangle
{
private:
    /* data */
    // 私有元素不能被成员函数外函数调用（言外之意可以被成员函数调用）
public:
    int w,h;
    Crectangle(int w_,int h_);
    ~Crectangle();
    int Area(){
        return w*h;
    }
    int Circle(){
        return 2*w+2*h;
    }
};

Crectangle::Crectangle(int w_,int h_)
{
    w=w_;
    h=h_;
}

Crectangle::~Crectangle()
{
}
void printCretangle( Crectangle &r){
    cout<<r.w<<" "<<r.h<<" "<<r.Area()<<" "<<r.Circle()<<endl;
}
int main(){
    int n1,n2,k;
    n1=3;n2=4;
    k=Max(n1,n2);//相当于把Max中的语句插入到这里代替Max
    double f1,f2,f3;
    f1=2.3;f2=4.4;
    f3=Max(f1,f2);
    cout<<k<<" "<<f3<<endl;
    Crectangle C(3,4);
    // 使用累的成员变量和成员函数
    // 方法一 对象名.成员名
    C.w=5;
    // 方法二，指针->成员名
    Crectangle* P1= &C;
    P1->w=12;
    // 方法三 引用。成员名
    printCretangle(*P1);
    printCretangle(C);
}