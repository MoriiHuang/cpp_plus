#include <iostream>
#include <string>
using namespace std;
//友元类
class cFriend
{
private:
	int va;
	int vb;
public:
	cFriend() { va = 0; vb = 0; }
	cFriend(int a,int b) { va = a; vb = b; }
	~cFriend() { cout << "执行结束！！！" << endl; }
	void set_va(int a) { va = a; }
	void set_vb(int b) { vb = b; }
	void disp();
	friend class cFriends;
};
class cFriends
{
private:
	int x;
	int y;
public:
	cFriends() { x = 0; y = 0; }
	cFriends(int a, int b) { x = a; y = b; }
	~cFriends() { cout << "友元类调用结束！！！" << endl; }
	void disps() { cout << "友元类显示：" << endl; cout << " x = " << x << endl; cout << " y = " << y << endl; }
	void dispc(cFriend data);
};
void cFriends::dispc(cFriend data)
{
	cout << "友元类访问：" << endl;
	cout << " va = " << data.va << endl;
	cout << " vb = " << data.vb << endl;
}
void cFriend::disp()
{
	cout << "成员函数调用：" << endl;
	cout << " va = " << va << endl;
	cout << " vb = " << vb << endl;
}
 
int main()
{
	cFriend data1(4, 5);
	cFriends data2(5, 6);
	data1.disp();
	data2.disps();
	data2.dispc(data1);
	return 0;
}
