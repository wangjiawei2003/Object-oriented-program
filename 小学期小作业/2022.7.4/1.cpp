//类的基础知识
#include<iostream>
using namespace std;
class dot {
private:
	void setdot(int x,int y);
	dot* l;
public:
	int x_, y_;
protected:
	int max(int x, int y)
	{
		return (x > y ? x : y);
	}
	
};
class line {
public:
	int l;
}line1, line2;


void dot::setdot(int x, int y)
{
	x_ = x;
	y_ = y;
}
int main() {
	dot a, b;
	dot* p = new dot;
	p->x_ = 5;
	p->y_ = 4;
	cout << p->x_<<endl;
	delete p;
	cout << sizeof(a) << endl;
}