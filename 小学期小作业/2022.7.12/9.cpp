#include <iostream>
using namespace std;
class father {

protected:
	string name;
public:
	father(int x, string y) :age(x), name(y)
	{
		cout << "���๹�캯��ִ�С�����" << endl;
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
	son(int x, string y, char z) :father(x, y), sex(z)//�������Ӷ���Ĺ�����̣�father fa�����������˲��������Ĺ��캯��
	{
		cout << "���๹�캯��ִ�С�����" << endl;
		cout << fa.age << endl;

	}//�̳е����޷����ʻ����˽����Ա�������Է��ʱ�����Ա
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
	//�����ⲿֻ�ܷ��ʸ����public��Ա��
	c.age = 15;
	cout << c.zx();
	cout << a.zx();//��̬����
	cout<<fason(&c);
	cout << fason(&a);//��̬���룬ֻ���ָ������ã���Ҫ�õ��麯��
	
	cout<<int('1');
}
