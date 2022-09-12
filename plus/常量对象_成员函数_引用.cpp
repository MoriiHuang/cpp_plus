#include<iostream>
using namespace std;
// 如果不希望某个对象的值被改变，则定义该对象的时候可以在前面加const关键字
// 在类的成员函数说明后面加const关键字，该函数为常量成员函数
// 常量成员函数执行期间不该修改其作用的对象，即不能修改成员变量的值（静态成员变量除外）
// 也不能调用同类的非常量成员函数
// 对象作为函数的参数时，生成该参数需要调用复制构造函数，效率比较低。用指针做参数，代码又不简洁
// 此时可以用对象的引用作为参数（为了避免引用作为形参修改了实参，加上const作为常引用）

class Sample
{
private:
    /* data */
public:
    int value;
    void GetValue() const;
    void func();
    Sample(/* args */);
    ~Sample();
};
void Sample:: GetValue() const{

}
Sample::Sample(/* args */)
{
}

Sample::~Sample()
{
}

int main(){
    const Sample o;
    // o.value=100;
    o.GetValue();
    // o.func();
}