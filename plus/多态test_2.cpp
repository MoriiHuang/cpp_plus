#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class Cshape
{
public:
   virtual double Area()=0;//纯虚函数
   virtual void PrintInfo()=0;
};
class Crectangle:public Cshape
{
private:
    /* data */
public:
   int w,h;
   virtual double Area();
   virtual void PrintInfo();
};
class Ccircle:public Cshape
{
private:
    /* data */
public:
   int r;
   virtual double Area();
   virtual void PrintInfo();
};
class CTriangle:public Cshape
{
private:
    /* data */
public:
   int a,b,c;
   virtual double Area();
   virtual void PrintInfo();
};
double Crectangle::Area(){
    return w*h;
}
void Crectangle::PrintInfo(){
    cout<<"Rectangle:"<<Area()<<endl;
}
double Ccircle::Area(){
    return 3.14*r*r;
}
void Ccircle::PrintInfo(){
    cout<<"Circle:"<<Area()<<endl;
}
double CTriangle::Area(){
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
void CTriangle::PrintInfo(){
    cout<<"Triangle:"<<Area()<<endl;
}
Cshape* pShapes[100];
int MyCompare(const void* s1,const void* s2){
    double a1,a2;
    Cshape ** p1;// s1,s2是void*，不可写*s1来取得s1指向的内容
    Cshape ** p2;
    p1=(Cshape**) s1;//s1，s2指向pShapes数组中的元素，数组元素的类型是 Cshape*
    p2=(Cshape**) s2;//故p1，p2都是指向指针的指针，类型是 Cshape**
    a1=(*p1)->Area();//*p1的类型是Cshape*，故为多态
    a2=(*p2)->Area();
    if (a1<a2){
        return -1;
    }
    else if (a2<a1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int i;int n;
    Crectangle* pr;Ccircle *pc;CTriangle *pt;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        switch (c)
        {
        case 'R':
            /* code */
            pr=new Crectangle();
            cin>>pr->w>>pr->h;
            pShapes[i]=pr;
            break;
        case 'C':
            /* code */
            pc=new Ccircle();
            cin>>pc->r;
            pShapes[i]=pc;
            break;
        case 'T':
            /* code */
            pt=new CTriangle();
            cin>>pt->a>>pt->b>>pt->c;
            pShapes[i]=pt;
            break;
        }
    }
    qsort(pShapes,n,sizeof(Cshape*),MyCompare);
    for (i=0;i<n;i++){
        pShapes[i]->PrintInfo();
    }
    return 0;
}

