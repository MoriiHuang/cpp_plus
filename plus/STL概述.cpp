#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 容器：可容纳各种数据类型的通用数据结构，是类模板
// 迭代器：可用于依次存取容器中的元素，类似于指针
// 算法：用来操作容器中的函数模板
// 顺序容器：vector,deque,list
// 双向迭代器和随机访问迭代器：随机访问迭代器的作用比双向迭代器大：包括但不限于可以p+i，有[]函数
// STL中“大”和“小”的概念
// 使用STL时，在缺省的情况下，以下三个说法等价：x比y小，x<y为真，y比x大
// STL中的“相等”概念
// 有时候“x和y相等”等价于“x==y为真”，有时候“x和y相等”等价于“x小于y和y小于x同时为假”
// STL中的“相等”概念演示
class A
{
private:
    int v;
public:
    A(int n):v(n){};
    ~A(){};
    bool operator<(const A &a2 ) const{
        cout<<v<<"<"<<a2.v<<"?"<<endl;
        return false;//意味着x任意x<y 和 y<x是不成立的
    }
    bool operator==(const A &a2 ) const{
        cout<<v<<"=="<<a2.v<<"?"<<endl;
        return v==a2.v;
    }
};


int main(){
    vector<int> v;
    for(int i=1;i<5;i++){
        v.push_back(i);
    }
    vector<int>::const_iterator i;//常量迭代器
    for(i=v.begin();i!=v.end();i++){
        cout<<*i<<",";
    } 
    cout<<endl;
    vector<int>::reverse_iterator r;//反向迭代器
    for(r=v.rbegin();r!=v.rend();r++){
        cout<<*r<<",";
    } 
    cout<<endl;
    // vector<int>::iterator j;//非常量迭代器
    // for(j=v.begin();j!=v.end();j++){
    //     *j=100;
    // }
    // for(i=v.begin();i!=v.end();i++){
    //     cout<<*i<<",";
    // } 
    vector<int>::iterator p;
    p=find(v.begin(),v.end(),3);
    if (p!=v.end()){
        cout<<*p<<endl;
    }
    p=find(v.begin()+1,v.end()-2,3);
    if (p!=v.end()){
        cout<<*p<<endl;
    }
    A a[]={A(1),A(2),A(3),A(4),A(5)};
    cout<<binary_search(a,a+4,A(9));
    return 0;
}