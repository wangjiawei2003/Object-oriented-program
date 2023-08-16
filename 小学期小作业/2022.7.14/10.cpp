#include<iostream>
#include<math.h>
using namespace std;
void Reduction_(int *x, int* y);
class fraction {
private:
	int fenzi;
	int fenmu;
public:
	fraction (int x=1,int y=1):fenzi(x),fenmu(y){}
	
	void Inverse();
	void Reciprocal();
	void Reduction();
	void DtoF(double p);
	void StoF(string x);//1/4

	//˫Ŀ�����
	fraction operator+(fraction& a);
	fraction operator-(fraction& a);
	fraction operator*(fraction& a);
	fraction operator/(fraction& a);
	
	bool operator<(fraction& a);
	bool operator>(fraction& a);
	bool operator<=(fraction& a);
	bool operator>=(fraction& a);
	bool operator==(fraction& a);
	bool operator!=(fraction& a);

	void display();
};
void fraction::display()
{
	
	if (fenmu == 1)
	{
		cout << fenzi << endl;
	}
	else if (fenmu == -1)
	{
		cout << -fenzi << endl;
	}
	else if (fenzi == fenmu)
	{
		cout << 1 << endl;
	}
	else if (fenmu == 0)
	{
		cout << "�������Ϊ��" << endl;
	}
	else
		cout << fenzi << "/" << fenmu << endl;
}
void fraction::Inverse()
{
	fenzi = -fenzi;

}
void fraction::Reciprocal()
{
	
	int t = fenzi;
	fenzi = fenmu;
	
	fenmu = t;
}

void fraction::Reduction()
{
	int j = fenzi;
	for (int i = j; i > 1; i--)
	{
		if (fenzi % i == 0 && fenmu % i == 0)
		{
			fenzi = fenzi / i;
			fenmu = fenmu / i;
		}
	}
}
void fraction::DtoF(double p)
{
	char str[100];
	sprintf_s(str, "%lf", p);//�ø�ʽ�����Ʒ�ʵ������ת��
	int len = strlen(str);
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		count++;
		if (str[i] == '.')
		{
			break;
		}
	}
	for (int i = count - 1; i < len - 1; i++)
	{
		str[i] = str[i + 1];
	}
	int digit = len - count;
	int num = 0;
	for (int i = 0; i < len - 1; i++)
	{
		num += ((str[i]) - 48) * int(pow(10, len - i - 2));//�ַ���������ת��
	}//�õ�����ֵ
	int num_ = int(pow(10, digit));
	fenzi = num;
	fenmu = num_;
	Reduction();
}
void fraction::StoF(string x)//1/4
{
	fenzi = 0;
	fenmu = 0;
	int count = 0;
	int len = x.length();//123/17

	for (int i = 0; i < len; i++)
	{
		count++;
		if (x[i] == '/')
		{
			break;
		}
	}
	for (int i = 0; i < count - 1; i++)
	{
		fenzi += (x[i] - 48) * int(pow(10, count - i - 2));
	}
	for (int i = count; i < len; i++)
	{
		fenmu += (x[i] - 48) * int(pow(10, len - i - 1));
	}

}
void Reduction_(int *x,int *y)
{
	int j = abs(*x);
	for (int i = j; i > 1; i--)
	{
		if (abs(*x) % i == 0 && abs(*y) % i == 0)
		{
			*x = *x / i;
			*y = *y / i;
		}
	}
}
fraction fraction::operator+(fraction& a)
{
	fraction c;
	c.fenmu = (this->fenmu) * (a.fenmu);
	c.fenzi = (this->fenzi) * (a.fenmu) + (this->fenmu) * (a.fenzi);

	Reduction_(&c.fenzi, &c.fenmu);
	return c;
}
fraction fraction::operator-(fraction& a)
{
	fraction c;
	c.fenmu = (this->fenmu) * (a.fenmu);
	c.fenzi = (this->fenzi) * (a.fenmu) - (this->fenmu) * (a.fenzi);

	Reduction_(&c.fenzi, &c.fenmu);
	return c;
}
fraction fraction::operator*(fraction& a)
{
	fraction c;
	c.fenmu = (this->fenmu) * (a.fenmu);
	c.fenzi = (this->fenzi) * (a.fenzi);

	Reduction_(&c.fenzi, &c.fenmu);
	return c;
}
fraction fraction::operator/(fraction& a)
{
	fraction c;
	c.fenmu = (this->fenmu) * (a.fenzi);
	c.fenzi = (this->fenzi) * (a.fenmu);

	Reduction_(&c.fenzi, &c.fenmu);
	return c;
}
bool fraction::operator<(fraction& a)
{
	if ((this->fenzi) * (a.fenmu) - (this->fenmu) * (a.fenzi) < 0)
		return 1;
	else
		return 0;

}
bool fraction::operator>(fraction& a)
{
	if ((this->fenzi) * (a.fenmu) - (this->fenmu) * (a.fenzi) > 0)
		return 1;
	else
		return 0;

}
bool fraction::operator<=(fraction& a)
{
	if ((this->fenzi) * (a.fenmu) - (this->fenmu) * (a.fenzi) <= 0)
		return 1;
	else
		return 0;

}
bool fraction::operator>=(fraction& a)
{
	if ((this->fenzi) * (a.fenmu) - (this->fenmu) * (a.fenzi) >= 0)
		return 1;
	else
		return 0;

}
bool fraction::operator==(fraction& a)
{
	if ((this->fenzi) * (a.fenmu) - (this->fenmu) * (a.fenzi) == 0)
		return 1;
	else
		return 0;

}
bool fraction::operator!=(fraction& a)
{
	if ((this->fenzi) * (a.fenmu) - (this->fenmu) * (a.fenzi) !=0)
		return 1;
	else
		return 0;

}
int main()
{
	while (1)
	{
		int x, y;
		cout << "a�ķ��ӣ�";
		cin >> x;
		cout << "a�ķ�ĸ��";
		cin >> y;

		fraction a(x, y);
		//���Դ���
		cout << "ԭ�����ǣ�";
		a.display();
		a.Inverse();
		cout << "ȡ����ķ����ǣ�";
		a.display();

		cout << "ԭ�����ǣ�";
		a.display();
		a.Reciprocal();
		cout << "ȡ����֮��ķ����ǣ�";
		a.display();

		cout << "ԭ�����ǣ�";
		a.display();
		a.Reduction();
		cout << "Լ��֮��ķ����ǣ�";
		a.display();


		double p;
		cout << "����һ��double���͵����֣�";
		cin >> p;
		a.DtoF(p);
		cout << "doubleת������";
		a.display();

		string q;
		cout << "����һ��string���͵������ַ�����";
		cin >> q;
		a.StoF(q);
		cout << "�ַ���ת������";
		a.display();

		int m, n;
		cout << "b�ķ��ӣ�";
		cin >> m;
		cout << "b�ķ�ĸ��";
		cin >> n;

		fraction b(m, n), c;

		cout << "a������ֵ��";
		a.display();
		cout << "b��ֵ��";
		b.display();

		cout << "a��b��";
		c = a + b;
		c.display();
		cout << "a��b��";
		c = a - b;
		c.display();
		cout << "a��b��";
		c = a * b;
		c.display();
		cout << "a��b��";
		c = a / b;
		c.display();

		cout << "�Ƚ�a��b�Ĵ�С��" << endl;
		if (a < b)
		{
			cout << "aС��b" << endl;
		}
		else if (a > b)
		{
			cout << "aС��b" << endl;
		}
		else
		{
			cout << "a��b���" << endl;
		}
		cout << "�Ƿ��ظ�ִ������������(Y/N)" << endl;

		char z;
		cin >> z;

		if (z == 'N')
		{
			break;
		}
	}
	
}