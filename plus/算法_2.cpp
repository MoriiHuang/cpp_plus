#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iterator>
#include<random>
using namespace std;
// 删除算法
// 删除一个容器中的某些元素
// 删除--不会使容器中里的元素减少：将所有应该删除的元素看做空位子
// 用留下的元素从后往前移，依次去填空位子；元素从后往前移动，依次去填空位子
// 元素从后往前移后，他原来的位置也就算是空位，也应该由后面的留下的元素填上
// 最后，没有被填上的空位子，维持其原来的值不变
// 删除算法不应该作用于关联容器
// remove（删除区间中等于某值的元素） remove_if,unique(删除区间中连续相等的元素，只留下一个，可自定义比较器)
// 复杂度都是O（n）
// unique(用==比较是否相等)
// template<class Fwdlt>
// Fwdlt unique(Fwdlt first,Fwdlt last);
// template<class Fwdlt,class Pred>(自定义比较器)
// Fwdlt unique(Fwdlt first,Fwdlt last,Pred pr);
// 返回值是迭代器，指向元素删除后的区间最后一个元素的后面
// 变序算法（算法复杂度都是O（n））
// 变序算法改变容器中的元素顺序，但是不改变元素的值，变序算法不适用于关联容器
// reverse(颠倒区间的前后次序)，rotate（将区间进行循环左移）
// next_permutation(将区间改为下一个排列，可自定义比较器)，prev_permutation
// stable_patition(把区间内满足某个条件的元素移到前面，不满足的移到后面，两部分元素保持原来的次序)
// 关于next_permutation的原理解释(考虑自行实现)
// 在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，并且满足*i < *ii。
// 然后再从尾端寻找另一个元素*j，如果满足*i < *j，即将第i个元素与第j个元素对调，并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。
// 下一个排列一定与原排列有尽可能长的前缀，所以，脑洞大开一下，从后面往前看这个序列，如果后面的若干个数字有下一个排列，问题就得到了解决。
// 排序算法（比前面的变序算法复杂度更高，一般是O（nlogn））
// 排序算法需要随机访问迭代器的支持，不适用于关联容器和list，list要用list::sort
// sort()降区间从小到大排序（可自定义比较器）
// 有序区间算法：要求所操作的区间是已经从小到大排好序的
// 需要随机访问迭代器的支持，不能用于关联容器和list
// binary_search 判断区间是否包含某个元素，lower_bound:查找最后一个不小于某值的元素的位置
// upper_bound 查找第一个大于某值的元素的位置 equal_range 同时获取 lower_bound和 upper_bound
// set_intersection 求出[first1,last1),[first2,last2)中共有的元素，放到从x开始的地方
// template<class init1,class init2,class Outit>
// Outit set_intersection(init1 first1,init1 last1,init2 first2,init2 last2,Outit x);
// bitset（bitset 模板类由若干个位（bit）组成，它提供一些成员函数，使程序员不必通过位运算就能很方便地访问、修改其中的任意一位。bitset 模板类在头文件 <bitset> 中定义如下：）
// template <size_t N>
// class bitset
// {
//     ...
// };
// 实际size_t 可视为 unsigned int。将 bitset 实例化时，N 必须是一个整型常数，例如：bitset <40> bst;
// 则 bst 是一个由 40 个位组成的对象，用 bitset 的成员函数可以方便地访问其中任意一位。bitset 中的位从 0 开始编号，第 0 位是最右边的位。


template<typename Iter>
bool my_next_permutation(Iter first, Iter last)
{
    if (first == last)
        return false;
    Iter i = first;
    ++i;
    if (i == last)
        return false;
    i = last;
    --i;
        
    for(;;)
    {
        Iter ii = i;
        --i;
        if (*i < *ii)
        {
            Iter j = last;
            while (!(*i < *j))
            {j--;}
            std::iter_swap(i, j);
            std::reverse(ii, last);
            return true;
        }
        if (i == first)
        {
            std::reverse(first, last);
            return false;
        }
    }
}
class A
{
private:
    int n;
public:
    A(int n_):n(n_){};
    int show_n(){
        return n;
    }
    friend int cmp(const A &a1,const A &a2);
};
int cmp(const A &a1,const A &a2){
    return a1.n<a2.n;
} 

int main(){
    int a[5]={1,2,3,2,5};
    int b[6]={1,2,3,2,5,6};
    ostream_iterator<int> output(cout," ");
    int *p=remove(a,a+5,2);
    cout<<"1)";copy(a,a+5,output);cout<<endl;
    cout<<"2)"<<p-a<<endl;
    vector<int> v(b,b+6);
    remove(v.begin(),v.end(),2);
    cout<<"3)";copy(v.begin(),v.end(),output);cout<<endl;
    cout<<"4)";cout<<v.size()<<endl;
    cout<<"5) "<<endl;
    string str="231";
    char szStr[]="324";
    while(my_next_permutation(str.begin(),str.end())){
        cout<<str<<endl;
    }
    cout<<"***"<<endl;
    while(next_permutation(szStr,szStr+3)){
        cout<<szStr<<endl;
    }
    int ls[]={8,7,10};
    while(next_permutation(ls,ls+3)){
        for(int i=0;i<sizeof(ls)/sizeof(int);i++){
            cout<<ls[i]<<" ";
        }
        cout<<endl;
    }
    A aa[]={9,7,1,2,5};
    vector<A> vv(aa,aa+sizeof(aa)/sizeof(A));
    while(next_permutation(vv.begin(),vv.end(),cmp)){
        vector<A>::iterator i=vv.begin();
        for(;i!=vv.end();i++){
            cout<<(*i).show_n()<<" ";
        }
        cout<<endl;
    }
}