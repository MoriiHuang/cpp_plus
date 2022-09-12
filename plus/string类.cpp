#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    // assign
    string s1(8,'s'),s2,s3;
    s3.assign(s1);
    s2.assign(s1,1,3);
    cout<<s1<<" "<<s2<<" "<<s3<<endl;
    // compare
    string s_1("hello"),s_2("hello"),s_3("hell");
    int f1=s_1.compare(s_2);
    int f2=s_1.compare(s_3);
    int f3=s_3.compare(s_1);
    cout<<f1<<","<<f2<<","<<f3<<endl;
    // substr
    string m1("sadhapppy");
    string m2=m1.substr(3,8);
    cout<<m2<<endl;
    // swap
    m1.swap(m2);
    cout<<m1<<" "<<m2<<endl;
    // find
    cout<<m2.find(m1)<<" "<<m2.rfind(m1)<<" "<<m2.find(m1,1)<<" "<<m2.find_first_of("ug")<<endl;
    // erase
    m2.erase(3);
    cout<<m2<<endl;
    // replace
    m2.replace(0,6,"talent");
    cout<<m2<<endl;
    // insert(loc,string,//可缺省 start,length)
    // c_str()返回传统的const char* 类型字符串，以‘\0’结尾
    // istringstream
    string input("Input test 123 4.7 A");
    istringstream inputString(input);
    string string1,string2;
    int a;
    double b;
    char c;
    inputString>>string1>>string2>>a>>b>>c;
    cout<<string1<<","<<string2<<","<<a<<","<<b<<","<<c<<endl;
    return 0;
}