#include<iostream>
using namespace std;
extern int flag_;
extern int ip;
#define width_ 9
#define length_ 9
#include<Windows.h>
#include<time.h>
#include"class.h"//引用头文件
#include"cmd_console.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
int chessplate::panduan()
{
	int score = 0;
	int num;
	int i, j, k, p;
	int loc_[9][9] = { 0 };
	//备份数组，方便之后的判断，否则原数组破坏后会发生错误
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			loc_[i][j] = loc[i][j];
		}
	}//得到备份数组，此时可以对原数组进行修改

	//先判断行
	for (i = 0; i < width_; i++)//第i行
	{

		for (j = 0; j < length_ - 1; j++)//第j列
		{
			num = 1;//错误点1：变量位置放错导致程序运行有误
			for (k = j + 1; k < length_; k++)//i行j列
			{
				if (loc_[k][i] != loc_[j][i] || loc_[j][i] == 0)//排除相邻颜色不一样或者此位置无珠的情况
				{
					break;
				}
				else
				{
					num++;
				}


			}
			if (num >= 5)//表示这一行出现了连珠现象,第i行，第j列开始
			{
				int t = loc_[j][i];
				for (p = j; p < length_; p++)//这一部一开始有误，如果第一个珠子变成0的话，后面珠子都不会和第一个珠子相等了
				{

					if (loc_[p][i] == t)
					{
						loc[p][i] = 0;//修改的是原数组
						clear(p, i);
					}

				}
				score += 2 * num;
				break;//表示这一行已经结束，如果这一行中出现了连珠现象，那么只可能出现一次
			}
		}

	}
	//判断列
	int num_;
	for (i = 0; i < length_; i++)//第i列
	{

		for (j = 0; j < width_ - 1; j++)//第j行
		{
			num_ = 1;

			for (k = j + 1; k < width_; k++)//i行j列
			{
				if (loc_[i][k] != loc_[i][j] || loc_[i][j] == 0)//排除相邻颜色不一样或者此位置无珠的情况
				{
					break;
				}
				else
				{
					num_++;
				}


			}
			if (num_ >= 5)//表示这一行出现了连珠现象,第i行，第j列开始
			{
				int t = loc_[i][j];
				for (p = j; p < width_; p++)//这一部一开始有误，如果第一个珠子变成0的话，后面珠子都不会和第一个珠子相等了
				{

					if (loc_[i][p] == t)
					{
						loc[i][p] = 0;
						clear(i, p);
					}

				}
				score += 2 * num_;
				break;//表示这一行已经结束，如果这一行中出现了连珠现象，那么只可能出现一次
			}
		}

	}
	//判断斜线(右上）
	int num__;
	for (i = 0; i < length_ - 1; i++)//列
	{

		for (j = 1; j < width_; j++)//行
		{
			num__ = 1;
			for (k = i + 1, p = j - 1; k <length_&& p >= 0; k++, p--)//i行j列
			{
				if (loc_[k][p] != loc_[i][j] || loc_[i][j] == 0)//排除相邻颜色不一样或者此位置无珠的情况
				{
					break;
				}
				else
				{
					num__++;
				}


			}
			if (num__ >= 5)//表示这一行出现了连珠现象,第i行，第j列开始
			{
				int t = loc_[i][j];
				for (k = i, p = j; k <length_&&p >= 0; k++, p--)//这一部一开始有误，如果第一个珠子变成0的话，后面珠子都不会和第一个珠子相等了
				{

					if (loc_[k][p] == t)
					{
						loc[k][p] = 0;//修改的是原数组
						clear(k, p);
					}

				}
				score += 2 * num__;
				break;//表示这一行已经结束，如果这一行中出现了连珠现象，那么只可能出现一次
			}
		}


	}
	//判断斜线(右下）
	int num___;
	for (i = 0; i < length_ - 1; i++)//列
	{

		for (j = 0; j < width_ - 1; j++)//行
		{
			num___ = 1;
			for (k = i + 1, p = j + 1; k <length_&& p < width_; k++, p++)//i行j列
			{
				if (loc_[k][p] != loc_[i][j] || loc_[i][j] == 0)//排除相邻颜色不一样或者此位置无珠的情况
				{
					break;
				}
				else
				{
					num___++;
				}


			}
			if (num___ >= 5)//表示这一行出现了连珠现象,第i行，第j列开始
			{
				int t = loc_[i][j];
				for (k = i, p = j; k <length_&& p < width_; k++, p++)//这一部一开始有误，如果第一个珠子变成0的话，后面珠子都不会和第一个珠子相等了
				{

					if (loc_[k][p] == t)
					{
						loc[k][p] = 0;//修改的是原数组
						clear(k, p);
					}

				}
				score += 2 * num___;
				break;//表示这一行已经结束，如果这一行中出现了连珠现象，那么只可能出现一次
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
	cout << "请输入起始坐标 (x1:0-8,y1:0-8):";
	cin >> x1;
	cin >> y1;

	//错误输入判断
	while (1)
	{
		if (loc[x1][y1] == 0)
		{
			
			cct_showstr(0, 31, " ", 0, 0, 50, -1);
			cct_gotoxy(0, 31);
			cct_setcolor(0, 7);
			cout << "该位置无珠子，请重新输入！" << endl;
			Sleep(600);
			cct_showstr(0, 30, " ", 0, 0, 50, -1);
			cct_showstr(0, 31, " ", 0, 0, 50, -1);
			cin.clear();
			cct_gotoxy(0, 30);
			cct_setcolor(0, 7);
			cout << "请输入起始坐标 (x1:0-8,y1:0-8):";
			cin >> x1;
			cin >> y1;
		}
		else
			break;
	}
	cct_showstr(0, 31, " ", 0, 0, 50, -1);
	cct_gotoxy(0, 31);
	cct_setcolor(0, 7);
	cout << "请输入终止坐标 (x2:0-8,y2:0-8):";
	cin >> x2;
	cin >> y2;

	//错误输入判断
	while (1)
	{
		if (loc[x2][y2] != 0)
		{
			cct_showstr(0, 32, " ", 0, 0, 50, -1);

			cct_gotoxy(0, 32);
			cct_setcolor(0, 7);
			cout << "该位置已存在珠子，请重新输入！" << endl;
			cin.clear();
			Sleep(600);
			cct_showstr(0, 31, " ", 0, 0, 50, -1);
			cct_showstr(0, 32, " ", 0, 0, 50, -1);
			cct_gotoxy(0, 31);
			cct_setcolor(0, 7);
			cout << "请输入终止坐标 (x2:0-8,y2:0-8):";
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
	cct_showstr(x, y, "┏", 7, 0, 1, -1);
	for (int i = 0; i < line; i++)
	{
		Sleep(60);
		cct_getxy(x, y);
		cct_showstr(x, y, "━━", 7, 0, 1, -1);
		if (i < line - 1)
		{
			cct_getxy(x, y);
			cct_showstr(x, y, "┳", 7, 0, 1, -1);
		}

	}
	cct_getxy(x, y);
	cct_showstr(x, y, "┓", 7, 0, 1, -1);
	cct_setcolor(0, 0);
	cout << endl;



	for (int i = 0; i < row; i++)
	{
		Sleep(10);
		cout << "  ";
		cct_getxy(x, y);
		cct_showstr(x, y, "┃", 7, 0, 1, -1);
		for (int j = 0; j < line; j++)
		{
			cct_getxy(x, y);
			cct_showch(x, y, ' ', 7, 0, 4);
			cct_getxy(x, y);
			cct_showstr(x, y, "┃", 7, 0, 1, -1);
		}
		cct_setcolor(0, 0);
		cout << endl;


		Sleep(20);
		cct_setcolor(0, 7);
		cout << i << " ";
		cct_getxy(x, y);
		cct_showstr(x, y, "┃", 7, 0, 1, -1);
		for (int j = 0; j < line; j++)
		{
			cct_getxy(x, y);
			cct_showch(x, y, ' ', 7, 0, 4);
			cct_getxy(x, y);
			cct_showstr(x, y, "┃", 7, 0, 1, -1);
		}
		cct_setcolor(0, 0);
		cout << endl;



	
		if (i < row - 1)
		{
			cout << "  ";
			cct_getxy(x, y);
			cct_showstr(x, y, "┣", 7, 0, 1, -1);
			for (int i = 0; i < line; i++)
			{
				Sleep(10);
				cct_getxy(x, y);
				cct_showstr(x, y, "━━", 7, 0, 1, -1);
				if (i < line - 1)
				{
					cct_getxy(x, y);
					cct_showstr(x, y, "╋", 7, 0, 1, -1);
				}

			}
			cct_getxy(x, y);
			cct_showstr(x, y, "┫", 7, 0, 1, -1);
			cct_setcolor(0, 0);
			cout << endl;
		}

	}
	cout << "  ";
	cct_getxy(x, y);
	cct_showstr(x, y, "┗", 7, 0, 1, -1);
	for (int i = 0; i < line; i++)
	{
		Sleep(10);
		cct_getxy(x, y);
		cct_showstr(x, y, "━━", 7, 0, 1, -1);
		if (i < line - 1)
		{
			cct_getxy(x, y);
			cct_showstr(x, y, "┻", 7, 0, 1, -1);
		}

	}
	cct_getxy(x, y);
	cct_showstr(x, y, "┛", 7, 0, 1, -1);
	
	cout << endl;

}
void chessplate::highlight(int i, int j)
{
	for (int k = 0; k < 5; k++)
	{
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "╭", 12, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "╮",12, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "╰", 12, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "╯", 12, 7, 1, -1);
		Sleep(30);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "╭", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "╮", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "╰", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "╯", loc[i][j] + 7, 7, 1, -1);
		Sleep(30);
	}
	
}
void chessplate::show_each( int i,int j)
{
	cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "╭", loc[i][j] + 7, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "╮", loc[i][j] + 7, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "╰", loc[i][j] + 7, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "╯", loc[i][j] + 7, 7, 1, -1);
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
	//很关键！！！不然游戏无法终止！！！
	if (count < 3)
	{
		i = count;
	}
	for (int j = 0; j < i; j++)
	{
		chess* p = new chess;
		srand((unsigned)time(NULL));//随机数种子。保证每次生成的随机数不同
		//随机生成一个坐标
		p->x = rand() % length_;//横坐标：0-8
		p->y = rand() % width_;//纵坐标：0-8
		//判断该坐标是否已经存在棋子
		while (1)
		{
			if (loc[p->x][p->y] != 0)
			{
				//重复生成一个随机坐标，直到不重复为止
				p->x = rand() % length_;//横坐标：0-8
				p->y = rand() % width_;//纵坐标：0-8
			}
			else
				break;

		}


		p->col = rand() % 7 + 1;//颜色：1-7
		a[p->x][p->y] = *p;//将新生成的棋子放入棋盘
		loc[p->x][p->y] = p->col;//记录棋子在棋盘中的颜色
		show_each(p->x, p->y);
		highlight(p->x, p->y);
		delete p;//动态申请之后删除
	}
}
void chessplate::clear(int i, int j)
{
	for (int k = 0; k < 5; k++)
	{
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "╭", 1, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "╮", 2, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "╰", 3, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "╯", 4, 7, 1, -1);
		Sleep(30);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "╭", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "╮", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "╰", loc[i][j] + 7, 7, 1, -1);
		cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "╯", loc[i][j] + 7, 7, 1, -1);
		Sleep(30);
	}
} 
void chessplate::xuanzhong(int i, int j)
{
	cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j, "╭", 0, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j, "╮", 0, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 2, y_ + 1 + 3 * j + 1, "╰", 0, 7, 1, -1);
	cct_showstr(x_ + 6 * i + 4, y_ + 1 + 3 * j + 1, "╯", 0, 7, 1, -1);
}
void chessplate::anjian()//原本想用多线程，结果果断放弃了
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
			cct_showstr(0, 0, "返回", 7, 0, 1, -1);
			if (maction== MOUSE_ONLY_MOVED)
			{
			
				if (X >= 0 && X <= 2 && Y == 0)
				{
				
					cct_showstr(0, 0, "返回", 0, 7, 1, -1);
	
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
							cout << "当前坐标值：" << i << " " << j;
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
				
					cct_showstr(0, 0, "返回", 0, 7, 1, -1);
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
								cout << "该位置无珠子，请重新输入！" << endl;
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
								cout << "起始坐标值：" << i << " " << j;
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
							cout << "当前坐标值：" << i << " " << j;
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
								cout << "该位置有珠子，请重新输入！" << endl;
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
								cout << "终点坐标值：" << i << " " << j;
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