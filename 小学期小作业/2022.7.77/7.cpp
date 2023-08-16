#include<iostream>
#include<cmath>
using namespace std;

class point {
private:
	int x, y;
	friend double distance(point& a, point& b);
public:
	point(int x_, int y_) :x(x_), y(y_){}

};
double distance(point& a, point& b)
{
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x * x + y * y);
}
//int main()
//{
//	point c(1, 2), d(2, 3);
//	cout << distance(c, d);
//
//}