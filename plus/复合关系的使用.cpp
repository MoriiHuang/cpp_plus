#include<iostream>
using namespace std;
// 复合关系的正确写法是两个类都有指向对方的指针
class Cmaster;
class Cdog{
public:
    int Cdogindex;
    Cmaster *pm;
    Cdog(int index=0){
        Cdogindex=index;
    }
};
class Cmaster{
public:
    Cdog *dogs[10];
};
int main(){
    Cmaster cm;
    Cdog cd(10);
    cm.dogs[0]=&cd;
    cout<<cm.dogs[0]->Cdogindex<<endl;
}