#include<iostream>
using namespace std;
#define width 9
#define length 9

#include<time.h>


class chess {
public:
	int x, y;//坐标
	int col;//颜色
};
class chessplate {
public:
	int mark = 0;
	chess a[9][9];//棋子
	int loc[9][9] = { 0 };//棋子记录器

	void create_chess(int i);//随机生成给定数目的棋子
	void draw_plate();//显示棋盘
	void move_chess();//移动棋子
	int panduan();
	bool game_over();
};

int chessplate::panduan()
{
	int score=0;
	int num;
	int i, j,k,p;
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
	for (i = 0; i < width; i++)//第i行
	{

		for (j = 0; j < length-1; j++)//第j列
		{
			num = 1;//错误点1：变量位置放错导致程序运行有误
			for (k = j+1;k < length; k++)//i行j列
			{
				if (loc_[k][i] != loc_[j][i]||loc_[j][i]==0)//排除相邻颜色不一样或者此位置无珠的情况
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
				for (p = j; p < length; p++)//这一部一开始有误，如果第一个珠子变成0的话，后面珠子都不会和第一个珠子相等了
				{
				
					if (loc_[p][i] == t)
					{
						loc[p][i] =0;//修改的是原数组
					}
					
				}
				score += 2 * num;
				break;//表示这一行已经结束，如果这一行中出现了连珠现象，那么只可能出现一次
			}
		}

	}
	//判断列
	int num_;
	for (i = 0; i < length; i++)//第i列
	{

		for (j = 0; j < width - 1; j++)//第j行
		{
			num_ = 1;
			
			for (k = j + 1; k < width; k++)//i行j列
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
				for (p = j; p < width; p++)//这一部一开始有误，如果第一个珠子变成0的话，后面珠子都不会和第一个珠子相等了
				{

					if (loc_[i][p] == t)
					{
						loc[i][p] = 0;
					}

				}
				score += 2 * num_;
				break;//表示这一行已经结束，如果这一行中出现了连珠现象，那么只可能出现一次
			}
		}

	}
	//判断斜线(右上）
	int num__;
	for (i = 0; i < length-1; i++)//列
	{
		
		for (j = 1; j <width;  j++)//行
		{
			num__ = 1;
			for (k = i+ 1,p=j-1; k<length,p>=0; k++,p--)//i行j列
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
				for (k=i,p=j; k <length,p>=0; k++,p--)//这一部一开始有误，如果第一个珠子变成0的话，后面珠子都不会和第一个珠子相等了
				{

					if (loc_[k][p] == t)
					{
						loc[k][p] = 0;//修改的是原数组
					}

				}
				score += 2 * num__;
				break;//表示这一行已经结束，如果这一行中出现了连珠现象，那么只可能出现一次
			}
		}
		

	}
	//判断斜线(右下）
	int num___;
	for (i = 0; i < length-1 ; i++)//列
	{

		for (j = 1; j < width-1; j++)//行
		{
			num___ = 1;
			for (k = i + 1, p = j + 1; k < length, p <width; k++, p++)//i行j列
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
				for (k = i, p = j; k < length, p <width; k++, p++)//这一部一开始有误，如果第一个珠子变成0的话，后面珠子都不会和第一个珠子相等了
				{

					if (loc_[k][p] == t)
					{
						loc[k][p] = 0;//修改的是原数组
					}

				}
				score += 2 * num___;
				break;//表示这一行已经结束，如果这一行中出现了连珠现象，那么只可能出现一次
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
		srand((unsigned)time(NULL));//随机数种子。保证每次生成的随机数不同
		//随机生成一个坐标
		p->x= rand() % length;//横坐标：0-8
		p->y = rand() % width;//纵坐标：0-8
		//判断该坐标是否已经存在棋子
		while (1)
		{
			if (loc[p->x][p->y] != 0)
			{
				//重复生成一个随机坐标，直到不重复为止
				p->x = rand() % length;//横坐标：0-8
				p->y = rand() % width;//纵坐标：0-8
			}
			else
				break;

		}
			
		
		p->col = rand() % 7 + 1;//颜色：1-7
		a[p->x][p->y] = *p;//将新生成的棋子放入棋盘
		loc[p->x][p->y] = p->col;//记录棋子在棋盘中的颜色
		delete p;//动态申请之后删除
	}
}
void chessplate::draw_plate()//绘制棋盘
{
	cout << "列数：0 1 2 3 4 5 6 7 8 " << endl;
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
	
	cout << "请输入起始坐标 (x1:0-8,y1:0-8):";
	cin >> x1;
	cin >> y1;
	//错误输入判断
	while (1)
	{
		if (loc[x1][y1] == 0)
		{
			cout << "该位置无珠子，请重新输入！" << endl;
			cin.clear();
			cout << "请输入起始坐标 (x1:0-8,y1:0-8):";
			cin >> x1;
			cin >> y1;
		}
		else
			break;
	}
	cout << "请输入终止坐标 (x2:0-8,y2:0-8):";
	cin >> x2;
	cin >> y2;
	//错误输入判断
	while (1)
	{
		if (loc[x2][y2] != 0)
		{
			cout << "该位置已存在珠子，请重新输入！" << endl;
			cin.clear();
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
int main()
{
	int flag;
	chessplate b;//新建一个棋盘
	b.create_chess(7);//开局随机生成七个珠子
	b.draw_plate();//显示棋盘
	
	while (1)
	{
		
		b.move_chess();//移动柱子
		b.draw_plate();//显示移动之后的珠盘
		flag=b.panduan();//错误点2：若一个函数有返回值时，想要不多次调用该函数，就应该将返回值赋给一个变量
		if (flag!=0)
		{
			cout << "本轮得分：" <<flag<<endl;
			cout << "总得分：" << b.mark << endl;
		}
		else
		{
			cout << "很遗憾本轮未得分，将重新生成三个珠子" << endl;
			cout << "本轮得分：" << flag << endl;
			cout << "总得分：" << b.mark << endl;
			b.create_chess(3);//随机生成三个珠子
		}
		
		b.draw_plate();//显示消除之后的珠盘
		//判断一下未输入值之前是否还有消除的可能
		while (1)
		{
			flag = b.panduan();//错误点2：若一个函数有返回值时，想要不多次调用该函数，就应该将返回值赋给一个变量
			if (flag != 0)
			{
				cout << "额外得分：" << flag << endl;
				cout << "总得分：" << b.mark << endl;
			}
			else
				break;
		}
		//判断游戏是否结束
		if (b.game_over())
		{
			cout << "游戏结束！" << endl;
			break;
		}
	}

	
}