#include<iostream>
using namespace std;
class demo
{
private:
    /* data */
public:
    int id;
    demo(int i);
    ~demo();
    demo(const demo &d){
        id=d.id+2;
        cout<<"copy called"<<endl;
    }
};

demo::demo(int i)
{
    id=i;
    cout<<id<<" "<<"constructed"<<endl;
}

demo::~demo()
{
    cout<<id<<" "<<"deconstructed"<<endl;
}
demo d1(1);
void Func(){
    static demo d2(2);
    demo d3(3);
    cout<<"func"<<endl;
}
demo f(){
    demo d18(18);
    return d18;
}
int main(){
    demo d4(4);
    d4=6;
    cout<<"main"<<endl;
    {
        demo d5(5);
    }
    Func();
    d4=demo(f());
    cout<<"main ends"<<endl;
}