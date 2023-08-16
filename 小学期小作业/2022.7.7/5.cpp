#include<iostream>
using namespace std;
class point {
public:
	point(int a, int b) :x(a), y(b)
	{

	}
	void print()
	{
		cout << x << y << endl;
	}
private:
	int x, y;
};

class Time {
public:
	Time(int h, int m, int s)
	{
		this->h = h;
		this->m= m;
		this->s = s;
	}
	void set_time(int h, int m, int s) 
	{
		this->h= h;
		this->m = m;
		this->s = s;
	}

	int h, m, s;
};
int v;
void balaba(int v)
{
	int m = 5;
	static int k = 4;
	enum color { RED, BLUE };
	class big {
		int x = k;
		color newcolor;
		void bs(color RED)
		{
			x = ::v;
			newcolor = RED;
		}
	};
}
int main()
{
	point a1[2] = { point(1,2),point(2,3) };
	Time now(1, 2, 3),*pt;
	pt = &now;
	int* ptr = &now.h;// 指向类中的数据成员的指针
	
	
	
	void (Time:: * pty)(int h, int m, int s) = &Time::set_time;//指向类中的成员函数的指针
	
	(now.*pty)(1,2,3);

	return 0;
}