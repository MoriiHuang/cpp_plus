#include<iostream>
#include<string>
#include<algorithm>
#include<map>
//  multimap
// template<class Key,class T,class Pred=less<Key>,class A=allocator<T>>
// class multimap{
    // typedef pair<const key,T> value_type; 
// }
// multimap中的元素由<关键字，值>组成，每个元素是一个pair对象，关键字就是first成员变量，其类型是Key
// multimap中允许多个元素的关键字相同。元素按照first成员变量从小到大排列，缺省情况下用less<Key>定义
// 关键字的“小于”关系
// map
// template<class Key,class T,class Pred=less<Key>,class A=allocator<T>>
// class map{
    // typedef pair<const key,T> value_type; 
// }
// map 和multimap基本类似，但关键字（first 成员变量 ）各不相同
// mutimap 样例
using namespace std;
class Cstudent
{

public:
    struct Cinfo
    {
        int id;
        string name;
    };
    int score;
    Cinfo info;
};
int main(){
    typedef multimap<int,double,less<int>  > mmid;
    mmid pairs;
    cout<<"1)"<<pairs.count(15)<<endl;
    pairs.insert(mmid::value_type(15,2.7));
    pairs.insert(mmid::value_type(15,99.3));
    cout<<"2)"<<pairs.count(15)<<endl;
    pairs.insert(mmid::value_type(30,11.11));
    pairs.insert(mmid::value_type(10,22.22));
    pairs.insert(mmid::value_type(25,33.33));
    pairs.insert(mmid::value_type(20,44.44));
    for(mmid::const_iterator i =pairs.begin();i!=pairs.end();++i){
        cout<<"("<<i->first<<","<<i->second<<")"<<",";
    }
    cout<<endl;
    // map的[]成员函数 若pairs为map模板类的对象，pairs[key]返回关键字等于key的元素的引用。若没有
    // 关键字为key的元素，则会插入一个关键字的引用，其值用无参构造函数初始化，并返回其值的引用
    typedef multimap<int,Cstudent::Cinfo> MAP_std;//使用内部类时要用外部类：：内部类形式
    MAP_std mp;
    Cstudent st;
    string cmd;
    while(cin>>cmd){
        if (cmd=="Add"){
            cin>>st.info.name>>st.info.id>>st.score;
            mp.insert(MAP_std::value_type(st.score,st.info));
        }
        else if(cmd=="Query"){
            int score;
            cin>>score;
            MAP_std::iterator p =mp.lower_bound(score);
            if (p!=mp.begin()){
                --p;
                score=p->first;
                MAP_std::iterator maxp =p;
                int maxid=p->second.id;
                for(;p!=mp.begin() && p->first==score;p--){
                    if(p->second.id>maxid){
                        maxp=p;
                        maxid=p->second.id;
                    }
                }
                if (p->first==score){
                    if(p->second.id>maxid){
                        maxp=p;
                        maxid=p->second.id;
                    }
                }
                cout<<maxp->second.name<<" "<<maxp->second.id<<" "<<maxp->first<<endl;
            }
            else{
                cout<<"Nobody"<<endl;
            }

        }
    }
    return 0;
}