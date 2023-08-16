#include<iostream>
using namespace std;
class Data {
public:
	void fun(int a, int m, int n) {
		data = n;
	}
	int data;
private:
	void add(int m) {
		data += m;
	}
	int x, y;
};
void func(Data A, Data* B, Data& C)
{
	A.data = 100;
	B->data = 100;
	C.data = 100;
	
}
Data fun(Data A)
{
	Data B;
	B = A;
	return B;
}
void cellar()
{
	Data A, * p, * p1;
	p1 = &A;
	p = new Data;
	p->data = 100;
	delete p;
}
Data* la(Data* p,Data* q)
{
	if (p->data > q->data)
		return p;
	else
		return q;
}
void add(int m, int n)
{
	m = m + 1;
}
//int main()
//{
//	Data l;
//	Data b;
//	Data c;
//	l.fun(1, 2, 3);
//	b.fun(2, 3, 4);
//	c.fun(3, 4, 5);
//	la(&b, &c)->data = 100;
//	func(l,&b,c);
//
//	cout << l.data << endl;
//	cout << b.data << endl;
//	cout << c.data << endl;
//}