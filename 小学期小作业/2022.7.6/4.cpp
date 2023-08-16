#include<iostream>
using namespace std;
class Data1 {

	int x = 5;
};
class Data {
public:
	explicit Data(const string str) :s(str)
	{

	}
	void print()
	{
		cout << s << endl;
	}
	Data1 printg(Data1 x)
	{
		return x;
	}
private:
	string s;
};
class bla {
public:

	bla(const bla& c)//复制构造函数
	{
		x = c.x;
		p = c.p;//开辟一段有长度的内存空间，该指针指向它；
		

	}
	bla(int m,const char *l) //构造函数
	{
		x = m;
		p = l;
	}
	~bla()//析构函数
	{
		cout << "析构函数起作用了" << p<<endl;
		
	}
private:
	int x;
	const char* p;//一定要是const，因为所给的实参是一个确定的恒定的字符串
};
int main()
{
	Data a("hello");//显式转换
	a.print();
	a = Data("world");//左边是类类型，右边是字符串类型，隐式转换
	a.print();
	Data1 b[5];
	Data1 c=a.printg(b[0]);
	bla cd(10,"hellpo");
	bla ab(cd);


}