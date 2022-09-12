#include<iostream>
using namespace std;
int n=4;
int &set_value(){return n;}
int main(){
    set_value()=40;
    cout<<n<<endl;
}