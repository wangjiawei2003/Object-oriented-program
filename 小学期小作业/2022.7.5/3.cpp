#include<iostream>
using namespace std;
class cub {
public:
	cub(int x=3, int y=6);
	int volume()
	{
		return a*b;
	}
private:
	int a, b;
};
//cub::cub(int x, int y)
//{
//	a = x;
//	b = y;
//}
cub::cub(int x, int y) :a(x), b(y) {

}
int main()
{
	cub d,c(2, 3);
	cout << c.volume()<<endl;
	cout << d.volume() << endl;

}