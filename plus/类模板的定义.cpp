#include<iostream>
#include<cstring>
template<class T1,class T2>
class Pair
{
public:
    T1 key;
    T2 value;
    Pair(T1 k,T2 v):key(k),value(v){}
    bool operator< (const Pair<T1,T2> &p) const;
};
template<class T1,class T2>
bool Pair<T1,T2>::operator< (const Pair<T1,T2> &p) const{
    return key<p.key;
}
using namespace std;
int main(){
    Pair<string,int> student("tom",19);
    Pair<string,int> studen1t("tom1",119);
    cout<<student.key<<","<<student.value<<endl;
    cout<<(student<studen1t)<<endl;
}


