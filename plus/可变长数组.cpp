#include<iostream>
using namespace std;
// 非引用的函数返回值不可以作为左值使用，涉及到赋值问题
class CArray
{
private:
int size;
int* ptr;
public:
    CArray(int s=0);
    ~CArray();
    CArray(CArray &a);
    void push_back(int v){
        if (ptr){
            int *tmpPtr =new int[size+1];
            memcpy(tmpPtr,ptr,sizeof(int)*size);
            delete[] ptr;
            ptr=tmpPtr;
        }
        else{
            ptr= new int[1];
        }
        ptr[size++]=v;
    }
    CArray & operator=(const CArray &a){
        if(ptr==a.ptr){
            return *this;
        }
        if(a.ptr==NULL){
            if (ptr) delete [] ptr;
            ptr=NULL;
            size=0;
            return *this;
        }
        if (size<a.size){
            if(ptr){delete[] ptr;}
            ptr= new int[a.size];
        }
        memcpy(ptr,a.ptr,sizeof(int)*a.size);
        size=a.size;
        return *this;
    }

    int length(){return size;}
    int& operator[](int i){
        return ptr[i];
    }
};

CArray::CArray(int s)
{
    if (s==0){
        ptr=NULL;
    }
    else{
        ptr=new int[s];
    }
}
CArray::CArray(CArray &a){
    if (!a.ptr){
        ptr=NULL;
        size=0;
        return;
    }
    ptr=new int[a.size];
    memcpy(ptr,a.ptr,sizeof(int)*a.size);
    size=a.size;
} 
CArray::~CArray()
{
    if(ptr) delete[] ptr;
}

int main(){
    CArray a;
    a.push_back(3);
    a.push_back(4);
    for (int i=0;i<a.length();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    CArray  a2,a3;
    a2=a;
    for (int i=0;i<a2.length();i++){
        cout<<a2[i]<<" ";
    }
    cout<<endl;
    a[1]=100;
    CArray a4(a);
    for (int i=0;i<a4.length();i++){
        cout<<a4[i]<<" ";
    }
    cout<<endl;
}