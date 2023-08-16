#include<iostream>
using namespace std;
extern int flag_;
extern int ip;
#define width_ 9
#define length_ 9
#include<Windows.h>
#include<time.h>
#include"class.h"//����ͷ�ļ�
#include"cmd_console.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
int chessplate::panduan()
{
	int score = 0;
	int num;
	int i, j, k, p;
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
	for (i = 0; i < width_; i++)//��i��
	{

		for (j = 0; j < length_ - 1; j++)//��j��
		{
			num = 1;//�����1������λ�÷Ŵ��³�����������
			for (k = j + 1; k < length_; k++)//i��j��
			{
				if (loc_[k][i] != loc_[j][i] || loc_[j][i] == 0)//�ų�������ɫ��һ�����ߴ�λ����������
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
				for (p = j; p < length_; p++)//��һ��һ��ʼ���������һ�����ӱ��0�Ļ����������Ӷ�����͵�һ�����������
				{

					if (loc_[p][i] == t)
					{
						loc[p][i] = 0;//�޸ĵ���ԭ����
						clear(p, i);
					}

				}
				score += 2 * num;
				break;//��ʾ��һ���Ѿ������������һ���г���������������ôֻ���ܳ���һ��
			}
		}

	}
	//�ж���
	int num_;
	for (i = 0; i < length_; i++)//��i��
	{

		for (j = 0; j < width_ - 1; j++)//��j��
		{
			num_ = 1;

			for (k = j + 1; k < width_; k++)//i��j��
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
				for (p = j; p < width_; p++)//��һ��һ��ʼ���������һ�����ӱ��0�Ļ����������Ӷ�����͵�һ�����������
				{

					if (loc_[i][p] == t)
					{
						loc[i][p] = 0;
						clear(i, p);
					}

				}
				score += 2 * num_;
				break;//��ʾ��һ���Ѿ������������һ���г���������������ôֻ���ܳ���һ��
			}
		}

	}
	//�ж�б��(���ϣ�
	int num__;
	for (i = 0; i < length_ - 1; i++)//��
	{

		for (j = 1; j < width_; j++)//��
		{
			num__ = 1;
			for (k = i + 1, p = j - 1; k <length_&& p >= 0; k++, p--)//i��j��
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
				for (k = i, p = j; k <length_&&p >= 0; k++, p--)//��һ��һ��ʼ���������һ�����ӱ��0�Ļ����������Ӷ�����͵�һ�����������
				{

					if (loc_[k][p] == t)
					{
						loc[k][p] = 0;//�޸ĵ���ԭ����
						clear(k, p);
					}

				}
				score += 2 * num__;
				break;//��ʾ��һ���Ѿ������������һ���г���������������ôֻ���ܳ���һ��
			}
		}


	}
	//�ж�б��(���£�
	int num___;
	for (i = 0; i < length_ - 1; i++)//��
	{

		for (j = 0; j < width_ - 1; j++)//��
		{
			num___ = 1;
			for (k = i + 1, p = j + 1; k <length_&& p < width_; k++, p++)//i��j��
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
				for (k = i, p = j; k <length_&& p < width_; k++, p++)//��һ��һ��ʼ���������һ�����ӱ��0�Ļ����������Ӷ�����͵�һ�����������
				{

					if (loc_[k][p] == t)
					{
						loc[k][p] = 0;//�޸ĵ���ԭ����
						clear(k, p);
					}

				}
				score += 2 * num___;
				break;//��ʾ��һ���Ѿ������������һ���г���������������ôֻ���ܳ���һ��
			}
		}


	}
	mark[ip] += score;
	return score;
}
bool chessplate::game_over()
{
	int a = 0;
	for (int i = 0; i < length_; i++)
	{
		for (int j = 0; j < width_; j++)
		{
			if (loc[i][j] == 0)
			{
				a = 1;
				
			}
		}
	}
	if (a == 0)
		return 1;
	else
		return 0;
}
void chessplate::move_chess()
{
	int x1, y1, x2, y2;
	cct_showstr(0, 30, " ", 0, 0, 50, -1);
	cct_showstr(0, 31, " ", 0, 0, 50, -1);
	cct_showstr(0, 32, " ", 0, 0, 50, -1);
	cct_showstr(0, 33, " ", 0, 0, 50, -1);
	cct_showstr(0, 34, " ", 0, 0, 50, -1);
	cct_gotoxy(0, 30);
	cct_setcolor(0, 7);
	cout << "��������ʼ���� (x1:0-8,y1:0-8):";
	cin >> x1;
	cin >> y1;

	//���������ж�
	while (1)
	{
		if (loc[x1][y1] == 0)
		{
			
			cct_showstr(0, 31, " ", 0, 0, 50, -1);
			cct_gotoxy(0, 31);
			cct_setcolor(0, 7);
			cout << "��λ�������ӣ����������룡" << endl;
			Sleep(600);
			cct_showstr(0, 30, " ", 0, 0, 50, -1);
			cct_showstr(0, 31, " ", 0, 0, 50, -1);
			cin.clear();
			cct_gotoxy(0, 30);
			cct_setcolor(0, 7);
			cout << "��������ʼ���� (x1:0-8,y1:0-8):";
			cin >> x1;
			cin >> y1;
		}
		else
			break;
	}
	cct_showstr(0, 31, " ", 0, 0, 50, -1);
	cct_gotoxy(0, 31);
	cct_setcolor(0, 7);
	cout << "��������ֹ���� (x2:0-8,y2:0-8):";
	cin >> x2;
	cin >> y2;

	//���������ж�
	while (1)
	{
		if (loc[x2][y2] != 0)
		{
			cct_showstr(0, 32, " ", 0, 0, 50, -1);

			cct_gotoxy(0, 32);
			cct_setcolor(0, 7);
			cout << "��λ���Ѵ������ӣ����������룡" << endl;
			cin.clear();
			Sleep(600);
			cct_showstr(0, 31, " ", 0, 0, 50, -1);
			cct_showstr(0, 32, " ", 0, 0, 50, -1);
			cct_gotoxy(0, 31);
			cct_setcolor(0, 7);
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
void chessplate::kongbai( int row, int line)
{
	cct_setcolor(0, 7);
	for (int i = 0; i < length_; i++)
	{
		for (int j = 0; j < width_; j++)
		{
			loc[i][j] = 0;
		}
	}
	int x, y;
	cout << endl;
	cout << "    ";
	for (int i = 0; i < line; i++)
	{
		cout << "  " << i;
		cout << "   ";
		
	}
	cout << endl;



	cout << "  ";
	cct_getxy(x, y);
	x_ = x;
	y_ = y;
	cct_showstr(x, y, "��", 7, 0, 1, -1);
	for (int i = 0; i < line; i++)
	{
		Sleep(60);
		cct_getxy(x, y);
		cct_showstr(x, y, "����", 7, 0, 1, -1);
		if (i < line - 1)
		{
			cct_getxy(x, y);
			cct_showstr(x, y, "��", 7, 0, 1, -1);
		}

	}
	cct_getxy(x, y);
	cct_showstr(x, y, "��", 7, 0, 1, -1);
	cct_setcolor(0, 0);
	cout << endl;



	for (int i = 0; i < row; i++)
	{
		Sleep(10);
		cout << "  ";
		cct_getxy(x, y);
		cct_showstr(x, y, "��", 7, 0, 1, -1);
		for (int j = 0; j < line; j++)
		{
			cct_getxy(x, y);
			cct_showch(x, y, ' ', 7, 0, 4);
			cct_getxy(x, y);
			cct_showstr(x, y, "��", 7, 0, 1, -1);
		}
		cct_setcolor(0, 0);
		cout << endl;


		Sleep(20);
		cct_setcolor(0, 7);
		cout << i << " ";
		cct_getxy(x, y);
		cct_showstr(x, y, "��", 7, 0, 1, -1);
		for (int j = 0; j < line; j++)
		{
			cct_getxy(x, y);
			cct_showch(x, y, ' ', 7, 0, 4);
			cct_getxy(x, y);
			cct_showstr(x, y, "��", 7, 0, 1, -1);
		}
		cct_setcolor(0, 0);
		cout << endl;



	
		if (i < row - 1)
		{
			cout << "  ";
			cct_getxy(x, y);
			cct_showstr(x, y, "��", 7, 0, 1, -1);
			for (int i = 0; i < line; i++)
			{
				Sleep(10);
				cct_getxy(x, y);
				cct_showstr(x, y, "����", 7, 0, 1, -1);
				if (i < line - 1)
				{
					cct_getxy(x, y);
					cct_showstr(x, y, "��", 7, 0, 1, -1);
				}

			}
			cct_getxy(x, y);
			cct_showstr(x, y, "��", 7, 0, 1, -1);
			cct_setcolor(0, 0);
			cout << endl;
		}

	}
	cout << "  ";
	cct_getxy(x, y);
	cct_showstr(x, y, "��", 7, 0, 1, -1);
	for (int i = 0; i < line; i++)
	{
		Sleep(10);
		cct_getxy(x, y);
		cct_showstr(x, y, "����", 7, 0, 1, -1);
		if (i < line - 1)
		{
			cct_getxy(x, y);
			cct_showstr(x, y, "��", 7, 0, 1, -1);
		}

	}
	cct_getxy(x, y);
	cct_showstr(x, y, "��", 7, 0, 1, -1);
	
	cout << endl;

}
void chessplate::highlight(int i, int j)
{
	for (int k = 0; k < 5; k++)
	{
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "�q", 12, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "�r",12, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "�t", 12, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "�s", 12, 7, 1, -1);
		Sleep(30);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "�q", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "�r", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "�t", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "�s", loc[i][j] + 7, 7, 1, -1);
		Sleep(30);
	}
	
}
void chessplate::show_each( int i,int j)
{
	cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "�q", loc[i][j] + 7, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "�r", loc[i][j] + 7, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "�t", loc[i][j] + 7, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "�s", loc[i][j] + 7, 7, 1, -1);
}
void chessplate::show()
{
	for (int i = 0; i < length_; i++)
	{
		for (int j = 0; j < width_; j++)
		{
			show_each(i, j);
		}
	}
}
void chessplate::create_chess(int i)
{
	cct_setcolor(0, 7);
	int count=0;
	for (int i = 0; i < length_; i++)
	{
		for (int j = 0; j < width_; j++)
		{
			if (loc[i][j] == 0)
			{
				count++;

			}
		}
	}
	//�ܹؼ���������Ȼ��Ϸ�޷���ֹ������
	if (count < 3)
	{
		i = count;
	}
	for (int j = 0; j < i; j++)
	{
		chess* p = new chess;
		srand((unsigned)time(NULL));//��������ӡ���֤ÿ�����ɵ��������ͬ
		//�������һ������
		p->x = rand() % length_;//�����꣺0-8
		p->y = rand() % width_;//�����꣺0-8
		//�жϸ������Ƿ��Ѿ���������
		while (1)
		{
			if (loc[p->x][p->y] != 0)
			{
				//�ظ�����һ��������ֱ꣬�����ظ�Ϊֹ
				p->x = rand() % length_;//�����꣺0-8
				p->y = rand() % width_;//�����꣺0-8
			}
			else
				break;

		}


		p->col = rand() % 7 + 1;//��ɫ��1-7
		a[p->x][p->y] = *p;//�������ɵ����ӷ�������
		loc[p->x][p->y] = p->col;//��¼�����������е���ɫ
		show_each(p->x, p->y);
		highlight(p->x, p->y);
		delete p;//��̬����֮��ɾ��
	}
}
void chessplate::clear(int i, int j)
{
	for (int k = 0; k < 5; k++)
	{
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "�q", 1, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "�r", 2, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "�t", 3, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "�s", 4, 7, 1, -1);
		Sleep(30);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "�q", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "�r", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "�t", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "�s", loc[i][j] + 7, 7, 1, -1);
		Sleep(30);
	}
} 
void chessplate::xuanzhong(int i, int j)
{
	cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "�q", 0, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "�r", 0, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "�t", 0, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "�s", 0, 7, 1, -1);
}
void chessplate::anjian()//ԭ�����ö��̣߳�������Ϸ�����
{
	
	cct_setcursor(2);
	int X, Y;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	cct_enable_mouse();
	int mark = 0;
	int mark_ = 0;
	int x1, y1, x2, y2;
	while (loop)
	{
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT)
		{
			cct_showstr(0, 0, "����", 7, 0, 1, -1);
			if (maction== MOUSE_ONLY_MOVED)
			{
			
				if (X >= 0 && X <= 2 && Y == 0)
				{
				
					cct_showstr(0, 0, "����", 0, 7, 1, -1);
	
				}
				for (int i = 0; i < length_; i++)
				{
					for (int j = 0; j < width_; j++)
					{
						if (X == x_ + 6 * i + 2 && Y == y_ + 1 + 3 * j || X == x_ + 6 * i + 4 && Y == y_ + 1 + 3 * j || X == x_ + 6 * i + 2 && Y == y_ + 1 + 3 * j + 1 || X == x_ + 6 * i + 4 && Y == y_ + 1 + 3 * j + 1)
						{
							
					
							xuanzhong(i, j);
							cct_gotoxy(0, 30);
							cct_setcolor(0, 7);
							cout << "��ǰ����ֵ��" << i << " " << j;
						}
						else
						{
							show_each(i, j);
						}
					}
				}
			}
			if (maction == MOUSE_LEFT_BUTTON_CLICK)
			{
				if (X >= 0 && X <= 2 && Y == 0)
				{
					mciSendString(L"play click1.mp3 ", 0, 0, 0);
					mciSendString(L"open click1.mp3", 0, 0, 0);
					mciSendString(L"play click1.mp3 ", 0, 0, 0);
				
					cct_showstr(0, 0, "����", 0, 7, 1, -1);
					flag_ = 1;
					break;
				}
				for (int i = 0; i < length_; i++)
				{
					for (int j = 0; j < width_; j++)
					{
						
						if (X == x_ + 6 * i + 2 && Y == y_ + 1 + 3 * j || X == x_ + 6 * i + 4 && Y == y_ + 1 + 3 * j || X == x_ + 6 * i + 2 && Y == y_ + 1 + 3 * j + 1 || X == x_ + 6 * i + 4 && Y == y_ + 1 + 3 * j + 1)
						{
							
							mciSendString(L"play click1.mp3 ", 0, 0, 0);
							
							if (loc[i][j] == 0)
							{

								cct_showstr(0, 31, " ", 0, 0, 50, -1);
								cct_gotoxy(0, 31);
								cct_setcolor(0, 7);
								cout << "��λ�������ӣ����������룡" << endl;
								Sleep(600);
								cct_showstr(0, 30, " ", 0, 0, 50, -1);
								cct_showstr(0, 31, " ", 0, 0, 50, -1);
								cin.clear();
								cct_gotoxy(0, 30);
								cct_setcolor(0, 7);


							}
							else
							{
								
								xuanzhong(i, j);
								cct_gotoxy(0, 31);
								cct_setcolor(0, 7);
								cout << "��ʼ����ֵ��" << i << " " << j;
								x1 = i;
								y1 = j;
								mark = 1;
							}
							
						}
						
						
					}
				}
				if (mark == 1)
					break;
			}
		}
	}
	while (loop)
	{
		if (flag_ == 1)
		{
			break;
		}
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT)
		{
			if (maction == MOUSE_ONLY_MOVED)
			{
				
				for (int i = 0; i < length_; i++)
				{
					for (int j = 0; j < width_; j++)
					{
						if (X == x_ + 6 * i + 2 && Y == y_ + 1 + 3 * j || X == x_ + 6 * i + 4 && Y == y_ + 1 + 3 * j || X == x_ + 6 * i + 2 && Y == y_ + 1 + 3 * j + 1 || X == x_ + 6 * i + 4 && Y == y_ + 1 + 3 * j + 1)
						{
							
							
							xuanzhong(i, j);
							cct_gotoxy(0, 30);
							cct_setcolor(0, 7);
							cout << "��ǰ����ֵ��" << i << " " << j;
						}
						else
						{
							show_each(i, j);
						}
					}
				}
			}
			if (maction == MOUSE_LEFT_BUTTON_CLICK)
			{
				
				for (int i = 0; i < length_; i++)
				{
					for (int j = 0; j < width_; j++)
					{
						if (X == x_ + 6 * i + 2 && Y == y_ + 1 + 3 * j || X == x_ + 6 * i + 4 && Y == y_ + 1 + 3 * j || X == x_ + 6 * i + 2 && Y == y_ + 1 + 3 * j + 1 || X == x_ + 6 * i + 4 && Y == y_ + 1 + 3 * j + 1)
						{
						
							mciSendString(L"play click1.mp3 ", 0, 0, 0);
							
						
							if (loc[i][j] != 0)
							{

								cct_showstr(0, 32, " ", 0, 0, 50, -1);
								cct_gotoxy(0, 32);
								cct_setcolor(0, 7);
								cout << "��λ�������ӣ����������룡" << endl;
								Sleep(600);

								cct_showstr(0, 32, " ", 0, 0, 50, -1);
								cin.clear();
								cct_gotoxy(0, 32);
								cct_setcolor(0, 7);


							}
							else
							{
								xuanzhong(i, j);
								cct_gotoxy(0, 32);
								cct_setcolor(0, 7);
								cout << "�յ�����ֵ��" << i << " " << j;
								x2 = i;
								y2 = j;
								mark_ = 1;
							}

						}

					}
				}
				if (mark_ == 1)
				{
					int t = loc[x1][y1];
					loc[x1][y1] = 0;
					loc[x2][y2] = t;
					break;
				}
					
			}

		}
	}
	
}