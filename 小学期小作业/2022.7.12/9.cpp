#include <iostream>
using namespace std;
class father {

protected:
	string name;
public:
	father(int x, string y) :age(x), name(y)
	{
		cout << "基类构造函数执行。。。" << endl;
	}
	father()
	{
		age = 30;
		name = "Litao";
	}
	virtual int zx()
	{
		return 0;
	}
	int age;
};
class son :public	father {
protected:
	int la = 3;
private:
	char sex;
	father fa;
public:
	son(int x, string y, char z) :father(x, y), sex(z)//隐含了子对象的构造过程，father fa这个对象调用了不含参数的构造函数
	{
		cout << "子类构造函数执行。。。" << endl;
		cout << fa.age << endl;

	}//继承的类无法访问基类的私立成员，但可以访问保护成员
	int zx()
	{
		return 1;
	}
};
int fason(father *x)
{
	
	return x->zx();
}
int main()
{
	father a, * b;
	b = &a;
	son c(10, "Tony", 'm');
	cout << fason(&c) << endl;
	//在类外部只能访问该类的public成员；
	c.age = 15;
	cout << c.zx();
	cout << a.zx();//静态编译
	cout<<fason(&c);
	cout << fason(&a);//动态编译，只针对指针和引用，需要用到虚函数
	
	cout<<int('1');
}
