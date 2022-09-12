#include<iostream>
using namespace std;
int num=0;
class Csample
{
private:
    /* data */
public:
    Csample(/* args */){
        cout<<"Constructor 1 Called"<<endl;
    }
    Csample(int n){
        cout<<"Constructor 2 Called"<<endl;
    }
    ~Csample(){
        char c='0'+num;
        cout<<"析构函数"<<c<<"Called"<<endl;
        num+=1;
    }
};
int main(){
    Csample array1[2];
    cout<<"step1"<<endl;
    Csample array2[2]={4,5};
    cout<<"step2"<<endl;
    Csample array3[2]={3};
    cout<<"step3"<<endl;
    Csample *array4 = new Csample[2];
    delete[] array4;
    cout<<"step4"<<endl;
    Csample *array5 = new Csample[2];//动态分配的内容需要自行delete否则不会析构
    cout<<"step5"<<endl;
    Csample *parray[3] = {new Csample(4),new Csample};// 指针数组如果不new 不会引发对象的生成
}