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

	bla(const bla& c)//���ƹ��캯��
	{
		x = c.x;
		p = c.p;//����һ���г��ȵ��ڴ�ռ䣬��ָ��ָ������
		

	}
	bla(int m,const char *l) //���캯��
	{
		x = m;
		p = l;
	}
	~bla()//��������
	{
		cout << "����������������" << p<<endl;
		
	}
private:
	int x;
	const char* p;//һ��Ҫ��const����Ϊ������ʵ����һ��ȷ���ĺ㶨���ַ���
};
int main()
{
	Data a("hello");//��ʽת��
	a.print();
	a = Data("world");//����������ͣ��ұ����ַ������ͣ���ʽת��
	a.print();
	Data1 b[5];
	Data1 c=a.printg(b[0]);
	bla cd(10,"hellpo");
	bla ab(cd);


}