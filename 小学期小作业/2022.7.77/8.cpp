#include<iostream>
using namespace std;
class base {
private:
	int x;
public:
	base(int i):x(i){}
	int print()
	{
		return x;
	}
};
class derived : public base {
public:
	derived(int x_,int y_) :base(x_),y(y_) {}
private:
	int y;
};
int main()
{
	derived a(2,3);
	cout << a.print();

}