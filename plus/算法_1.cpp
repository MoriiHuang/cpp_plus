#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iterator>
#include<random>
using namespace std;
// STL中的算法：不变序列算法，变值算法，删除算法，变序算法，排序算法，有序区间算法，数值算法
// 大多重载的算法都是有两个版本的
// 1。用“==”判断元素是否相等，或用“<”来比较大小
// 2。多出一个类型参数“Pred”和函数形参“Pred op”通过表达式op（x，y）的返回值
// true or false 来判断x是否等于y，或者x是否小于y
// 变值算法：该类算法会修改源区间或目标区间的值，值被修改的那个区间，不可以是属于关联容器的（因为排序好了，强行修改可能出问题）
// for_each(对区间中的每个元素做某种操作),copy（复制一个区间到别处） 
// copy 源代码
// template<class _II,class _OI>
// inline _OI copy(_II _F,_II _L,_OI _X){
//     for(;_F!=_L;++_X,++_F){
//         *_X=*_F;
//     }
//     return(_X);
// }
// copy_backward（复制一个区间到别处，但目标区是从后往前被修改的，注意不是反向，是从区间末尾到前面，但不是反向复制）,
// transform（将一个区间的元素变形后拷贝到另一个区间）
// for_each
// template<typename InputIteror,typename Functin>
// Function for_each(InputIteror begin,InputIteror end, Function f ){
//     while(begin!=end){
//         f(*begin++);
//     }
// }
// transform
// template<class InIt,class Outlt,class Unop>
// Outlt transform(InIt first,InIt last,Outlt x，Unop Unop)
// 对[first,last)中的每个迭代器I：执行uop（*I);并将结果依次放入从x开始的地方
// 要求uop(*I)不得改变*I的值
// 模板返回值是一个迭代器，即x+（last-first），x可以和first相等
template<class T>
class My_ostream_iterator:public iterator<output_iterator_tag,T>
{
private:
    /* data */
    ostream &os;
    string sep;
public:
    // 需要重载“+”，“*”，“=”；
    My_ostream_iterator(ostream &o,string s):os(o),sep(s){};
    void operator++(){};
    My_ostream_iterator & operator*(){return *this;}
    My_ostream_iterator & operator=(const T value){
        os<<value<<sep;
        return *this;
    }
};

class A
{
private:
    int n;
public:
    A(){};
    A(int i):n(i){}
    int show_n(){
        return n;
    }
    bool operator==(const A &rhs) const{
        return (n==rhs.n);
    }
    A & operator=(const A& oth){
        if(this==&oth){
            return *this;
        }
        else{
            n=oth.n;
            return *this;
        }
    }
    friend bool operator<(const A &a1, const A &a2){
        cout<<"< called"<<endl;
        if(a1.n==3 and a2.n==7){
            return true;
        }
        else return false;
   }
   friend int operator+(const A &a1, const A &a2){
        return a1.n+a2.n;
   }
   friend ostream &operator<<(ostream &os,const A&oth){
        os<<oth.n;
        return os;
    }
   friend class finder_t;
   template<class T>
   friend void PrinT_(T beg,T end);
   template<class T>
   friend void OutputSquare(T &a);
}; 
typedef struct finder_t
{   
    finder_t(int n):steo(n){}
    bool operator()(A a){
        return (steo<a.n);
    }
    int steo;
}finder_t;
template<class T>
void OutputSquare(T &a){
    cout<<a.n*a.n<<",";
}
int calculateCube(A &value){
    return value.show_n()*value.show_n()*value.show_n();
}
template<class T>
void PrinT_(T beg,T end){
    for (;beg!=end;beg++){
        cout<<beg->n<<" ";
    }
    cout<<endl;
}
int main(){
    // 不变序列算法，不会修改算法所作用的容器或对象 适用于顺序容器和关联容器
    // 时间复杂度为O(n)
    A aa[]={3,5,7,7,1};
    A aa_to_find(3);
    A aa_to_count(7);
    finder_t f_(6);
    A *s=find_if(aa,aa+5,f_);
    random_device rd;
    default_random_engine generator(rd());
    shuffle(aa, aa+5, generator);
    PrinT_(aa,aa+5);
    // A* s=find(aa,aa+5,aa_to_find);
    cout<<"find_if "<<s->show_n()<<endl;
    int cou=count(aa,aa+5,aa_to_count);
    cout<<"count "<<cou<<endl;
    cou=count_if(aa,aa+5,f_);
    cout<<"count_if "<<cou<<endl;
    cout<<min_element(aa,aa+5)->show_n()<<endl;
    cout<<max_element(aa,aa+5)->show_n()<<endl;    
    cout<<"accumulate "<<accumulate(aa,aa+5,0)<<endl;
    // for_each()函数,构架看main()函数前,一般fun为输入相关的函数，函数不会改变迭代器的值
    cout<<"for_each ";for_each(aa,aa+5,OutputSquare<A>);cout<<endl;
    A bb[5];
    transform(aa,aa+5,bb,calculateCube);
    cout<<"transform ";PrinT_(bb,bb+5);
    int in[4]={1,2,3,4};
    ostream_iterator<int> output(cout,"*");
    cout<<"copy ";copy(in,in+4,output);cout<<endl;
    My_ostream_iterator<int> output_2(cout,"*");
    cout<<"My_ostream_iterator ";copy(in,in+4,output);cout<<endl;
    My_ostream_iterator<A> output_3(cout," ");
    cout<<"copy for A ";copy(aa,aa+5,output_3);cout<<endl;
    return 0;
}