#include<iostream>
#include<iomanip>
using namespace std;
// 这里利用了<<的重载：ostream &operator<<(ostream&(*p)(ostream &));该函数内部会调用p指向的函数（这里是tab），且以*this（这里为cout）作为参数
ostream &tab(ostream &output){
    return output<<'\t';
}
int main(){
    double x=1234567.89,y=12.34567;
    int n=1234567;
    int m=12;
    cout<<setprecision(6)<<x<<endl<<y<<endl<<n<<m<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(6)<<x<<endl<<y<<endl<<n<<m<<endl;
    // int w=4;
    // char string[10];
    // cin.width(5);
    // while(cin>>string){
    //     cout.width(w++);
    //     cout<<string<<endl;
    //     cin.width(5);
    // }
    cout<<"aa"<<tab<<"bb"<<endl;
}