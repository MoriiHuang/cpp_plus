#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
// 所有适用于 vector的操作都适用于 deque，deque还有push_front,pop_front操作，复杂度为O(1)
// 双向链表list：早任何位置插入删除都是常数时间，不支持随机存取（即重载了[]）。除去具有所有顺序容器都有的成员函数
// 外，还支持8个成员函数：push_front,pop_front,sort(list不支持STL的算法sort),remove（删除和指定值相等的所有元素）
// unique（删除和前一个元素相同的元素，搭配sort使用）,merge,reverse，splice（在指定位子前插入另一个链表1元素，并在
// 另一链表中删除被插入的元素）
// vector
template<class T>
void PrintVector(T s,T e){
    for (;s!=e;s++){
        cout<<*s<<" ";
        
    }
    cout<<endl;
}
// list
class A
{
private:
    int n;
public:
    A(int n_):n(n_){};
    friend bool operator<(const A &a1,const A &a2);
    friend bool operator==(const A &a1,const A &a2);
    friend ostream &operator<<(ostream & o,const A &a );
};
bool operator<(const A &a1,const A &a2){
    return a1.n<a2.n;
}
bool operator==(const A &a1,const A &a2){
    return a1.n==a2.n;
}
ostream &operator<<(ostream & o,const A &a ){
    o<<a.n;
    return o;
}
template<class T>
void  PrintVector(const list<T> &lst){
    typename list<T>::const_iterator i;
    i=lst.begin();
    for (i=lst.begin();i!=lst.end();i++){
        cout<<*i<<",";
    }
    cout<<endl;
}
int main(){
    int a[5]={1,2,3,4,5};
    vector<int> v(a,a+5);
    cout<<"1)"<<v.end()-v.begin()<<endl;
    cout<<"2)";PrintVector(v.begin(),v.end());
    v.insert(v.begin()+2,13);
    cout<<"3)";PrintVector(v.begin(),v.end());
    v.erase(v.begin()+2);
    cout<<"4)";PrintVector(v.begin(),v.end());
    vector<int> v2(4,100);
    v2.insert(v2.begin(),v.begin()+1,v.begin()+3);
    cout<<"5)v2: ";PrintVector(v2.begin(),v2.end());
    v.erase(v.begin()+1,v.begin()+3);
    cout<<"6)";PrintVector(v.begin(),v.end());
    // 用vector实现二维数组
    vector<vector<int> > v1(3);
    for (int i=0;i<v.size();i++){
        for (int j=0;j<4;j++){
            v1[i].push_back(j);
        }
    }
    for (int i=0;i<v1.size();++i){
        for (int j=0;j<v1[i].size();++j){
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }
    // list
    list<A> lst1,lst2;
    for(int i=1;i<5;i++)
        lst1.push_back(i);
    lst1.push_back(2);
    for(int i=1;i<5;i++)
        lst2.push_back(i*10);
    lst2.insert(lst2.begin(),30);lst2.insert(lst2.begin(),40);
    lst2.insert(lst2.begin(),30);lst2.insert(lst2.begin(),40);
    cout<<"list 1)";PrintVector(lst1);
    cout<<"list 2)";PrintVector(lst2);
    lst2.sort();
    cout<<"list 3)";PrintVector(lst2);
    lst2.pop_front();
    cout<<"list 4)";PrintVector(lst2);
    lst1.remove(2);
    cout<<"list 5)";PrintVector(lst1);
    lst2.unique();
    cout<<"list 6)";PrintVector(lst2);

}