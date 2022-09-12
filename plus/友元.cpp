#include<iostream>
using namespace std;
// 友元函数：一个类的友元函数可以访问该类的私有成员
class Ccar;
class Cdriver
{
private:
    /* data */
public:
    Cdriver(){

    }
    ~Cdriver(){

    }
    void ModifyCar(Ccar *pcar);
};
class Ccar
{
private:
    /* data */
    int price;
friend void Cdriver::ModifyCar(Ccar *pcar);
friend int MostExpensiveCar(Ccar cars[],int total);
friend class CDriver;
public:
    Ccar(/* args */){
        price=102;
    }
    ~Ccar(){

    }
};
// 友元类：如果A是B的友元类，那么A的成员函数可以访问B的成员变量
class CDriver
{
private:
    /* data */
public:
    void CDriver::Modifycar(Ccar myCar){
        myCar.price+=1000;
}
};
void Cdriver::ModifyCar(Ccar *pcar){
    pcar->price+=100;
}
int MostExpensiveCar(Ccar cars[],int total){
    int tmpMax=-1;
    for (int i=0;i<total;i++){
        if (cars[i].price>tmpMax){
            tmpMax=cars[i].price;
        }
    }
    return tmpMax;
}

int main(){
    Cdriver cd;
    Ccar car[3];
    cd.ModifyCar(&car[0]);
    cd.ModifyCar(&car[0]);
    cd.ModifyCar(&car[1]);
    int m=MostExpensiveCar(car,3);
    cout<<m<<endl;
}