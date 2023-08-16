#include<iostream>
using namespace std;
class add {

public:
	static int num;
	static int plus() {
		num += 15;
		return num;
	}
};
int add::num = 0;
//int main() {
//	add a,b;
//	cout << a.plus();
//	cout << b.plus();
//	add::num = 20;
//	cout << add::num;
//	cout<<a.plus();
//}