#include<iostream>
#include<vector>
#include<pair>
using namespace std;

class Queue
{
private:
    int n;
    vector<pair<int,int>> v;
public: 
    Queue(int n_){
        n=n_;
        v.resize(n);
    };
    void InsertNode(int pos,int data){
        v.insert(v.begin()+pos,data);
    };
    void Delete(int pos){
        v.erase(v.begin()+pos);
    }
    vector<int>& getQueue(){
        return this->v;
    }
};


int main(){
    int n;
    int a,b,c;
    cin>>n;
    Queue que(n);

    for (int i=0;i<n;i++){
        cin>>a;
        switch (a)
        {
        case 1:
            cin>>b>>c;
            que.InsertNode(b,c);
            break;
        case 2:
            cin>>b;
            que.Delete(b);
            break;
        case 3:
            cin>>b>>c;
            NumArray* na=new NumArray(que.getQueue());
            cout<<na->sumRange(b-1,c-1)<<endl;
            break;
        }

    }
}