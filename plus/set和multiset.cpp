#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
// 关联容器
// 内部元素有序排序，新元素插入的位置取决于它的值，查找速度快
// 除了各容器都有的函数外，还支持以下成员函数：find，lower_bound(查找某个下界),upper_bound,
// equal_range(同时上界和下界)，count，insert
// multiset
// template<class Key,class Pred=less<Key>,class A=allocator<key>>
// Pred类型的变量决定了multiset中的元素“一个比另一个小”是如何定义的。Pred的缺省类型是less<Key>
// less模板的定义如下：
// template<class T>
// struct less:public binary_function<T,T,bool>
// {
//     bool operator()(const T &x,const T&y){return x<y;}const
// };

using namespace std;
class A
{
private:
    /* data */
    int n;
public:
    A(int n_):n(n_){};
    friend bool operator<(const A &a1,const A &a2){
        return  a1.n<a2.n;
    }
    friend ostream &operator<<(ostream &o,const A &a2){
        o<<a2.n;
        return o;
    }
    friend class MyLess;
};
struct MyLess
{
    bool operator()(const A &a1,const A &a2){
        return (a1.n%10)<(a2.n%10);
    }
};
typedef multiset<A> MySet1;
typedef multiset<A,MyLess> MySet2;
template<class T>
void Print(T first,T last){
    for(;first!=last;++first){
        cout<<*first<<" ";
    }
    cout<<endl;
}
int main(){
    // pair的第三种构造函数
    pair<int,int> p(pair<double,double>(5.6,4.4));
    cout<<p.first<<","<<p.second<<endl;
    // multiset<A> a;
    // a.insert(A()); error
    // multiset<A> a等价于multiset<A,less<A>> a. 插入元素时，multiset会将被插入元素和已有
    // 元素进行比较，由于less模板是用<进行比较的，所以，要求A的对象需要重载<
    const int SIZE=6;
    A a[SIZE]={4,22,19,8,33,40};
    MySet1 m1; 
    m1.insert(a,a+SIZE);
    m1.insert(22);
    cout<<"1)"<<m1.count(22)<<endl;
    cout<<"2)";Print(m1.begin(),m1.end());
    MySet1::iterator pp=m1.find(19);
    if (pp!=m1.end()){
        cout<<"found "<<*pp<<endl;
    }
    cout<<"3)";cout<<*m1.lower_bound(22)<<","<<*m1.upper_bound(22)<<endl;
    pp=m1.erase(m1.lower_bound(22),m1.upper_bound(22));
    cout<<"4)";Print(m1.begin(),m1.end());
    cout<<"5)"<<*pp<<endl;
    MySet2 m2;
    m2.insert(a,a+SIZE);
    cout<<"6)";Print(m2.begin(),m2.end());
    // set 用法
    typedef set<int>::iterator si;
    pair<si,bool> result;
    int a1[5]={13,2,4,3,8};
    set<int> st(a1,a1+5);
    result=st.insert(5);//插入成功则输出被插入元素
    if (result.second){
        cout<<*result.first<<"inserted"<<endl;
    }
    if (st.insert(5).second){//插入重复则输出重复的元素
        cout<<*result.first<<"inserted"<<endl;
    }
    else{
        cout<<*result.first<<"already exits"<<endl;
    }
    pair<si,si> bounds=st.equal_range(4);
    cout<<*bounds.first<<","<<*bounds.second<<endl;
    return 0;

}