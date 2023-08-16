#include<iostream>
using namespace std;
#define width 9
#define length 9

#include<time.h>


class chess {
public:
	int x, y;//����
	int col;//��ɫ
};
class chessplate {
public:
	int mark = 0;
	chess a[9][9];//����
	int loc[9][9] = { 0 };//���Ӽ�¼��

	void create_chess(int i);//������ɸ�����Ŀ������
	void draw_plate();//��ʾ����
	void move_chess();//�ƶ�����
	int panduan();
	bool game_over();
};

int chessplate::panduan()
{
	int score=0;
	int num;
	int i, j,k,p;
	int loc_[9][9] = { 0 };
	//�������飬����֮����жϣ�����ԭ�����ƻ���ᷢ������
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			loc_[i][j] = loc[i][j];
		}
	}//�õ��������飬��ʱ���Զ�ԭ��������޸�

	//���ж���
	for (i = 0; i < width; i++)//��i��
	{

		for (j = 0; j < length-1; j++)//��j��
		{
			num = 1;//�����1������λ�÷Ŵ��³�����������
			for (k = j+1;k < length; k++)//i��j��
			{
				if (loc_[k][i] != loc_[j][i]||loc_[j][i]==0)//�ų�������ɫ��һ�����ߴ�λ����������
				{
					break;
				}
				else
				{
					num++;
				}
			
			
			}
			if (num >= 5)//��ʾ��һ�г�������������,��i�У���j�п�ʼ
			{
				int t = loc_[j][i];
				for (p = j; p < length; p++)//��һ��һ��ʼ���������һ�����ӱ��0�Ļ����������Ӷ�����͵�һ�����������
				{
				
					if (loc_[p][i] == t)
					{
						loc[p][i] =0;//�޸ĵ���ԭ����
					}
					
				}
				score += 2 * num;
				break;//��ʾ��һ���Ѿ������������һ���г���������������ôֻ���ܳ���һ��
			}
		}

	}
	//�ж���
	int num_;
	for (i = 0; i < length; i++)//��i��
	{

		for (j = 0; j < width - 1; j++)//��j��
		{
			num_ = 1;
			
			for (k = j + 1; k < width; k++)//i��j��
			{
				if (loc_[i][k] != loc_[i][j] || loc_[i][j] == 0)//�ų�������ɫ��һ�����ߴ�λ����������
				{
					break;
				}
				else
				{
					num_++;
				}


			}
			if (num_ >= 5)//��ʾ��һ�г�������������,��i�У���j�п�ʼ
			{
				int t = loc_[i][j];
				for (p = j; p < width; p++)//��һ��һ��ʼ���������һ�����ӱ��0�Ļ����������Ӷ�����͵�һ�����������
				{

					if (loc_[i][p] == t)
					{
						loc[i][p] = 0;
					}

				}
				score += 2 * num_;
				break;//��ʾ��һ���Ѿ������������һ���г���������������ôֻ���ܳ���һ��
			}
		}

	}
	//�ж�б��(���ϣ�
	int num__;
	for (i = 0; i < length-1; i++)//��
	{
		
		for (j = 1; j <width;  j++)//��
		{
			num__ = 1;
			for (k = i+ 1,p=j-1; k<length,p>=0; k++,p--)//i��j��
			{
				if (loc_[k][p] != loc_[i][j] || loc_[i][j] == 0)//�ų�������ɫ��һ�����ߴ�λ����������
				{
					break;
				}
				else
				{
					num__++;
				}


			}
			if (num__ >= 5)//��ʾ��һ�г�������������,��i�У���j�п�ʼ
			{
				int t = loc_[i][j];
				for (k=i,p=j; k <length,p>=0; k++,p--)//��һ��һ��ʼ���������һ�����ӱ��0�Ļ����������Ӷ�����͵�һ�����������
				{

					if (loc_[k][p] == t)
					{
						loc[k][p] = 0;//�޸ĵ���ԭ����
					}

				}
				score += 2 * num__;
				break;//��ʾ��һ���Ѿ������������һ���г���������������ôֻ���ܳ���һ��
			}
		}
		

	}
	//�ж�б��(���£�
	int num___;
	for (i = 0; i < length-1 ; i++)//��
	{

		for (j = 1; j < width-1; j++)//��
		{
			num___ = 1;
			for (k = i + 1, p = j + 1; k < length, p <width; k++, p++)//i��j��
			{
				if (loc_[k][p] != loc_[i][j] || loc_[i][j] == 0)//�ų�������ɫ��һ�����ߴ�λ����������
				{
					break;
				}
				else
				{
					num___++;
				}


			}
			if (num___ >= 5)//��ʾ��һ�г�������������,��i�У���j�п�ʼ
			{
				int t = loc_[i][j];
				for (k = i, p = j; k < length, p <width; k++, p++)//��һ��һ��ʼ���������һ�����ӱ��0�Ļ����������Ӷ�����͵�һ�����������
				{

					if (loc_[k][p] == t)
					{
						loc[k][p] = 0;//�޸ĵ���ԭ����
					}

				}
				score += 2 * num___;
				break;//��ʾ��һ���Ѿ������������һ���г���������������ôֻ���ܳ���һ��
			}
		}


	}
	mark += score;
	return score;
}
bool chessplate::game_over()
{
	int a = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (loc[i][j] == 0)
			{
				a = 1;
				break;
			}
		}
	}
	if (a == 0)
		return 1;
	else
		return 0;
}
void chessplate:: create_chess(int i)
{
	for (int j = 0; j < i; j++)
	{
		chess* p = new chess;
		srand((unsigned)time(NULL));//��������ӡ���֤ÿ�����ɵ��������ͬ
		//�������һ������
		p->x= rand() % length;//�����꣺0-8
		p->y = rand() % width;//�����꣺0-8
		//�жϸ������Ƿ��Ѿ���������
		while (1)
		{
			if (loc[p->x][p->y] != 0)
			{
				//�ظ�����һ��������ֱ꣬�����ظ�Ϊֹ
				p->x = rand() % length;//�����꣺0-8
				p->y = rand() % width;//�����꣺0-8
			}
			else
				break;

		}
			
		
		p->col = rand() % 7 + 1;//��ɫ��1-7
		a[p->x][p->y] = *p;//�������ɵ����ӷ�������
		loc[p->x][p->y] = p->col;//��¼�����������е���ɫ
		delete p;//��̬����֮��ɾ��
	}
}
void chessplate::draw_plate()//��������
{
	cout << "������0 1 2 3 4 5 6 7 8 " << endl;
	for (int i = 0; i < width; i++)
	{
		cout << i<<"     ";
		for (int j = 0; j < length; j++)
		{
			cout << loc[j][i] << " ";
		}
		
		cout << endl;
	}
}

void chessplate::move_chess()
{
	int x1, y1, x2, y2;
	
	cout << "��������ʼ���� (x1:0-8,y1:0-8):";
	cin >> x1;
	cin >> y1;
	//���������ж�
	while (1)
	{
		if (loc[x1][y1] == 0)
		{
			cout << "��λ�������ӣ����������룡" << endl;
			cin.clear();
			cout << "��������ʼ���� (x1:0-8,y1:0-8):";
			cin >> x1;
			cin >> y1;
		}
		else
			break;
	}
	cout << "��������ֹ���� (x2:0-8,y2:0-8):";
	cin >> x2;
	cin >> y2;
	//���������ж�
	while (1)
	{
		if (loc[x2][y2] != 0)
		{
			cout << "��λ���Ѵ������ӣ����������룡" << endl;
			cin.clear();
			cout << "��������ֹ���� (x2:0-8,y2:0-8):";
			cin >> x2;
			cin >> y2;
		}
		else
			break;
	}
	int t = loc[x1][y1];
	loc[x1][y1] = 0;
	loc[x2][y2] = t;
}
int main()
{
	int flag;
	chessplate b;//�½�һ������
	b.create_chess(7);//������������߸�����
	b.draw_plate();//��ʾ����
	
	while (1)
	{
		
		b.move_chess();//�ƶ�����
		b.draw_plate();//��ʾ�ƶ�֮�������
		flag=b.panduan();//�����2����һ�������з���ֵʱ����Ҫ����ε��øú�������Ӧ�ý�����ֵ����һ������
		if (flag!=0)
		{
			cout << "���ֵ÷֣�" <<flag<<endl;
			cout << "�ܵ÷֣�" << b.mark << endl;
		}
		else
		{
			cout << "���ź�����δ�÷֣�������������������" << endl;
			cout << "���ֵ÷֣�" << flag << endl;
			cout << "�ܵ÷֣�" << b.mark << endl;
			b.create_chess(3);//���������������
		}
		
		b.draw_plate();//��ʾ����֮�������
		//�ж�һ��δ����ֵ֮ǰ�Ƿ��������Ŀ���
		while (1)
		{
			flag = b.panduan();//�����2����һ�������з���ֵʱ����Ҫ����ε��øú�������Ӧ�ý�����ֵ����һ������
			if (flag != 0)
			{
				cout << "����÷֣�" << flag << endl;
				cout << "�ܵ÷֣�" << b.mark << endl;
			}
			else
				break;
		}
		//�ж���Ϸ�Ƿ����
		if (b.game_over())
		{
			cout << "��Ϸ������" << endl;
			break;
		}
	}

	
}