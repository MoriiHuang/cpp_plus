#include<iostream>
#include<stack>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
// template<class T,class Cont=deque<T> >
// class stack{

// };
// push pop top
// queue 和 stack基本类似
// priority_queue 和queue基本类似
// template<class T,class Cont=deque<T>. class Compare=less<T> >
// class priority_queue{

// };
// push,pop时间复杂度为O(logn) top为O(1)
int main(){
    priority_queue<double> pq1;
    pq1.push(3.2);
    pq1.push(9.8);pq1.push(9.8);pq1.push(5.4);
    while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();}
}
