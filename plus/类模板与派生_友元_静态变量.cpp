#include<iostream>
using namespace std;
// 类模板与继承
// 类模板从类模板派生
template<class T1,class T2>
class A{
public:
    T1 v1; T2 v2;
};
template<class T1,class T2>
class B:public A<T2,T1>{
public:
    T1 v3; T2 v4;
};
template<class T>
class C:public B<T,T>{
    T v5;
};
// 函数模板作为类模板的友元
template<class T1,class T2>
class Pair
{
private:
T1 key;
T2 value;
public:
Pair(T1 k,T2 v):key(k),value(v){};
bool operator <(const Pair<T1,T2> &p) const{
    return key<p.key;
}
template<class T3,class T4>
friend ostream & operator<<(ostream &o,const Pair<T3,T4> &p);
};

template<class T1, class T2>
 ostream & operator<<(ostream &o,const Pair<T1,T2> &p){
    o<<"("<<p.key<<","<<p.value<<")";
    return o;
}
int main(){
    B<int,double> obj1;
    C<int> obj2;
    obj1.v1=4;
    Pair<int,string> student(123,"Morii");
    Pair<int,double> obj(123,456.789);
    cout<<student<<" "<<obj<<endl;
}