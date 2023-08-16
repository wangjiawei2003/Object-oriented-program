#include<iostream>
using namespace std;
#define width_ 9
#define length_ 9
#define loc_ 17
#define loc__ 30
#define hgt 18
#include <thread>
#include<algorithm>
#include<time.h>
#include<Windows.h>
#include"class.h"//引用头文件
#include"cmd_console.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#include<graphics.h>
int flag_;
int ip = -1;
int music;
IMAGE img;
int main()
{

	
	cct_setcursor(2);
	int X, Y;
	int ret, maction;
	int keycode1, keycode2;
	cct_enable_mouse();
	int mark = 0;
	int mark_ = 0;
	chessplate b;//新建一个棋盘

	
	pal:while (1)
	{
		
		mciSendString(L"close bg.mp3 ", 0, 0, 0);
		if (music != -1)
		{
			mciSendString(L"open ga.mp3", 0, 0, 0);
			mciSendString(L"play ga.mp3 repeat", 0, 0, 0);
		}
		
		cct_cls();
		cct_setconsoleborder(60, 40);
		cct_showstr(24, 10, "五子连珠", 7, 5, 1, -1);
		cct_showstr(loc_, hgt, "┏", 7, 0, 1, -1);
		cct_showstr(loc_+2, hgt, "━━━", 7, 0, 1, -1);
		cct_showstr(loc_+8, hgt, "┓", 7, 0, 1, -1);

		cct_showstr(loc_, hgt+1, "┃", 7, 0, 1, -1);
		cct_showstr(loc_+2, hgt + 1, " ", 7, 7, 1, -1);
		cct_showstr(loc_+7, hgt + 1, " ", 7, 7, 1, -1);
		cct_showstr(loc_+8, hgt + 1, "┃", 7, 0, 1, -1);
		cct_showstr(loc_+3, hgt + 1, "开始", 7, 0, 1, -1);

		cct_showstr(loc_, hgt + 2, "┗", 7, 0, 1, -1);
		cct_showstr(loc_+2, hgt + 2, "━━━", 7, 0, 1, -1);
		cct_showstr(loc_+8, hgt + 2, "┛", 7, 0, 1, -1);
		cct_setcolor(0, 7);
		cct_showstr(loc_+3, hgt + 1, "开始", 7, 0, 1, -1);



		cct_showstr(loc_, hgt + 4, "┏", 7, 0, 1, -1);
		cct_showstr(loc_+2, hgt + 4, "━━━", 7, 0, 1, -1);
		cct_showstr(loc_+8, hgt + 4, "┓", 7, 0, 1, -1);

		cct_showstr(loc_, hgt + 5, "┃", 7, 0, 1, -1);
		cct_showstr(loc_+2, hgt + 5, " ", 7, 7, 1, -1);
		cct_showstr(loc_+7, hgt + 5, " ", 7, 7, 1, -1);
		cct_showstr(loc_+8, hgt + 5, "┃", 7, 0, 1, -1);
		cct_showstr(loc_+3, hgt + 5, "排名", 7, 0, 1, -1);

		cct_showstr(loc_, hgt + 6, "┗", 7, 0, 1, -1);
		cct_showstr(loc_+2, hgt + 6, "━━━", 7, 0, 1, -1);
		cct_showstr(loc_+8, hgt + 6, "┛", 7, 0, 1, -1);
		cct_setcolor(0, 7);
		cct_showstr(loc_+3, hgt + 5, "排名", 7, 0, 1, -1);


		cct_showstr(loc_, hgt + 8, "┏", 7, 0, 1, -1);
		cct_showstr(loc_+2, hgt + 8, "━━━", 7, 0, 1, -1);
		cct_showstr(loc_+8, hgt + 8, "┓", 7, 0, 1, -1);

		cct_showstr(loc_, hgt + 9, "┃", 7, 0, 1, -1);
		cct_showstr(loc_+2, hgt + 9, " ", 7, 7, 1, -1);
		cct_showstr(loc_+7, hgt + 9, " ", 7, 7, 1, -1);
		cct_showstr(loc_+8, hgt + 9, "┃", 7, 0, 1, -1);
		cct_showstr(loc_+3, hgt + 9, "退出", 7, 0, 1, -1);

		cct_showstr(loc_, hgt + 10, "┗", 7, 0, 1, -1);
		cct_showstr(loc_+2, hgt + 10, "━━━", 7, 0, 1, -1);
		cct_showstr(loc_+8, hgt + 10, "┛", 7, 0, 1, -1);
		cct_setcolor(0, 7);
		cct_showstr(loc_+3, hgt + 9, "退出", 7, 0, 1, -1);





		cct_showstr(loc__, hgt, "┏", 7, 0, 1, -1);
		cct_showstr(loc__ + 2, hgt, "━━━", 7, 0, 1, -1);
		cct_showstr(loc__ + 8, hgt, "┓", 7, 0, 1, -1);

		cct_showstr(loc__, hgt + 1, "┃", 7, 0, 1, -1);
		cct_showstr(loc__ + 2, hgt + 1, " ", 7, 7, 1, -1);
		cct_showstr(loc__ + 7, hgt + 1, " ", 7, 7, 1, -1);
		cct_showstr(loc__ + 8, hgt + 1, "┃", 7, 0, 1, -1);
		cct_showstr(loc__ + 3, hgt + 1, "音乐", 7, 0, 1, -1);

		cct_showstr(loc__, hgt + 2, "┗", 7, 0, 1, -1);
		cct_showstr(loc__ + 2, hgt + 2, "━━━", 7, 0, 1, -1);
		cct_showstr(loc__ + 8, hgt + 2, "┛", 7, 0, 1, -1);
		cct_setcolor(0, 7);
		cct_showstr(loc__ + 3, hgt + 1, "音乐", 7, 0, 1, -1);



		cct_showstr(loc__, hgt + 4, "┏", 7, 0, 1, -1);
		cct_showstr(loc__ + 2, hgt + 4, "━━━", 7, 0, 1, -1);
		cct_showstr(loc__ + 8, hgt + 4, "┓", 7, 0, 1, -1);

		cct_showstr(loc__, hgt + 5, "┃", 7, 0, 1, -1);
		cct_showstr(loc__ + 2, hgt + 5, " ", 7, 7, 1, -1);
		cct_showstr(loc__ + 7, hgt + 5, " ", 7, 7, 1, -1);
		cct_showstr(loc__ + 8, hgt + 5, "┃", 7, 0, 1, -1);
		cct_showstr(loc__ + 3, hgt + 5, "帮助", 7, 0, 1, -1);

		cct_showstr(loc__, hgt + 6, "┗", 7, 0, 1, -1);
		cct_showstr(loc__ + 2, hgt + 6, "━━━", 7, 0, 1, -1);
		cct_showstr(loc__ + 8, hgt + 6, "┛", 7, 0, 1, -1);
		cct_setcolor(0, 7);
		cct_showstr(loc__ + 3, hgt + 5, "帮助", 7, 0, 1, -1);


		cct_showstr(loc__, hgt + 8, "┏", 7, 0, 1, -1);
		cct_showstr(loc__ + 2, hgt + 8, "━━━", 7, 0, 1, -1);
		cct_showstr(loc__ + 8, hgt + 8, "┓", 7, 0, 1, -1);

		cct_showstr(loc__, hgt + 9, "┃", 7, 0, 1, -1);
		cct_showstr(loc__ + 2, hgt + 9, " ", 7, 7, 1, -1);
		cct_showstr(loc__ + 7, hgt + 9, " ", 7, 7, 1, -1);
		cct_showstr(loc__ + 8, hgt + 9, "┃", 7, 0, 1, -1);
		cct_showstr(loc__ + 3, hgt + 9, "关于", 7, 0, 1, -1);

		cct_showstr(loc__, hgt + 10, "┗", 7, 0, 1, -1);
		cct_showstr(loc__ + 2, hgt + 10, "━━━", 7, 0, 1, -1);
		cct_showstr(loc__ + 8, hgt + 10, "┛", 7, 0, 1, -1);
		cct_setcolor(0, 7);
		cct_showstr(loc__ + 3, hgt + 9, "关于", 7, 0, 1, -1);
		while (1)
		{
			cct_showstr(24, 10, "五子连珠", 7, 1, 1, -1);
			Sleep(200);
			cct_showstr(24, 10, "五子连珠", 7, 2, 1, -1);
			Sleep(200);
			cct_showstr(24, 10, "五子连珠", 7, 3, 1, -1);
			Sleep(200);
			cct_showstr(24, 10, "五子连珠", 7, 4, 1, -1);
			Sleep(200);
			cct_showstr(24, 10, "五子连珠", 7, 5, 1, -1);
			Sleep(200);
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
			if (ret == CCT_MOUSE_EVENT)
			{
				if (maction == MOUSE_ONLY_MOVED)
				{

					if (X >= loc_+3 && X <=loc_+7 && Y == hgt+1)
					{
						cct_showstr(loc_+3, hgt+1, "开始", 0, 7, 1, -1);
					}
					else
					{
						cct_showstr(loc_+3, hgt+1, "开始", 7, 0, 1, -1);
					}

					if (X >= loc_+3 && X <= loc_+7 && Y == hgt+5)
					{
						cct_showstr(loc_+3, hgt+5, "排名", 0, 7, 1, -1);
					}
					else
					{
						cct_showstr(loc_+3, hgt+5, "排名", 7, 0, 1, -1);
					}

					if (X >= loc_+3 && X <= loc_+7 && Y == hgt+9)
					{
						cct_showstr(loc_+3, hgt+9, "退出", 0, 7, 1, -1);
					}
					else
					{
						cct_showstr(loc_+3, hgt+9, "退出", 7, 0, 1, -1);
					}
					if (X >= loc__+ 3 && X <= loc__ + 7 && Y == hgt + 1)
					{
						cct_showstr(loc__ + 3, hgt + 1, "音乐", 0, 7, 1, -1);
					}
					else
					{
						cct_showstr(loc__ + 3, hgt + 1, "音乐", 7, 0, 1, -1);
					}

					if (X >= loc__ + 3 && X <= loc__ + 7 && Y == hgt + 5)
					{
						cct_showstr(loc__ + 3, hgt + 5, "帮助", 0, 7, 1, -1);
					}
					else
					{
						cct_showstr(loc__ + 3, hgt + 5, "帮助", 7, 0, 1, -1);
					}

					if (X >= loc__ + 3 && X <= loc__ + 7 && Y == hgt + 9)
					{
						cct_showstr(loc__ + 3, hgt + 9, "关于", 0, 7, 1, -1);
					}
					else
					{
						cct_showstr(loc__ + 3, hgt + 9, "关于", 7, 0, 1, -1);
					}
					cct_setcolor(0, 7);
				}
				if (maction == MOUSE_LEFT_BUTTON_CLICK)
				{
					if (X >= loc__ + 3 && X <= loc__ + 7 && Y == hgt + 9)//关于键
					{
						cct_cls();
						cct_setcolor(0, 7);
						cct_gotoxy(22, 17);
						cout << "作者：烛酒";
						cct_gotoxy(22, 19);
						cout << "QQ号:2769735361";
						cct_showstr(0, 0, "返回", 7, 0, 1, -1);
						cct_setcolor(0, 7);
						while (1)
						{

							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
							if (ret == CCT_MOUSE_EVENT)
							{
								if (maction == MOUSE_LEFT_BUTTON_CLICK)
								{
									if (X >= 0 && X <= 2 && Y == 0)
									{
										goto pal;
									}
									if (X >= 25 && X <= 26 && Y == 21)
									{
										mciSendString(L"play ga.mp3 repeat", 0, 0, 0);
										music = 0;

									}
									if (X >= 27 && X <= 30 && Y == 21)
									{
										mciSendString(L"close ga.mp3 ", 0, 0, 0);
										music = -1;
									}

								}
							}
						}
					}
					if (X >= loc__ + 3 && X <= loc__ + 7 && Y == hgt + 5)//帮助键
					{
						cct_cls();
						cct_setcolor(0, 7);
						cct_gotoxy(0, 20);
						cout << "棋盘大小是9X9，一共会出现6种颜色的珠子。初始状态棋盘上7个随机位置分布着7个随机颜色的珠子。通过移动珠子将同色的珠子连在一起来消除后得分。当无珠子可以移动时程序结束。游戏记录所有游戏者得分并排序。";
						cct_showstr(0, 0, "返回", 7, 0, 1, -1);
						cct_setcolor(0, 7);
						while (1)
						{

							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
							if (ret == CCT_MOUSE_EVENT)
							{
								if (maction == MOUSE_LEFT_BUTTON_CLICK)
								{
									if (X >= 0 && X <= 2 && Y == 0)
									{
										goto pal;
									}

								}
							}
						}
					}
					if (X >= loc__ + 3 && X <= loc__ + 7 && Y == hgt + 1)//音乐键
					{
						cct_cls();
						cct_setcolor(0, 7);
						cct_showstr(25, 21, "on", 3, 7, 1, -1);
						cct_showstr(27, 21, "off", 5, 7, 1, -1);
						cct_setcolor(0, 7);
						
						cct_showstr(0, 0, "返回", 7, 0, 1, -1);
						cct_setcolor(0, 7);
						while (1)
						{

							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
							if (ret == CCT_MOUSE_EVENT)
							{
								if (maction == MOUSE_LEFT_BUTTON_CLICK)
								{
									if (X >= 0 && X <= 2 && Y == 0)
									{
										goto pal;
									}
									if (X >= 25 && X <= 26 && Y == 21)
									{
										mciSendString(L"play ga.mp3 repeat", 0, 0, 0);
										music = 0;

									}
									if (X >= 27 && X <= 30 && Y == 21)
									{
										mciSendString(L"close ga.mp3 ", 0, 0, 0);
										music = -1;
									}

								}
							}
						}
					}
					if (X >= loc_+3 && X <= loc_+7 && Y == hgt+9)//退出键
					{
						cct_cls();
						cout << "游戏结束！！！";
						cout << endl;
						exit(0);
					}
					if (X >= loc_+3 && X <= loc_+7 && Y == hgt+5)//排行键
					{
						cct_cls();
						cct_setcolor(0, 7);
						sort(b.mark, b.mark + ip + 1, greater<int>());
						cct_showstr(27, 21, "冠军：" , 0, 7, 1, -1);
						cct_gotoxy(34, 21);
						cout << b.mark[0];

						cct_showstr(27, 22, "亚军：" , 0, 7, 1, -1);
						cct_gotoxy(34, 22);
						cout << b.mark[1];

						cct_showstr(27, 23, "季军：" , 0, 7, 1, -1);
						cct_gotoxy(34, 23);
						cout << b.mark[2];

						cct_showstr(0, 0, "返回", 7, 0, 1, -1);
						cct_setcolor(0, 7);
						while (1)
						{

							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
							if (ret == CCT_MOUSE_EVENT)
							{
								if (maction == MOUSE_LEFT_BUTTON_CLICK)
								{
									if (X >= 0 && X <= 2 && Y == 0)
									{
										goto pal;
									}

								}
							}
						}

					}
					if (X >= loc_+3 && X <= loc_+7 && Y == hgt+1)//开始键
					{
						ip++;
						cct_setcolor(0, 7);
						cct_cls();
						mciSendString(L"close ga.mp3", 0, 0, 0);
						mciSendString(L"open bg.mp3", 0, 0, 0);
						mciSendString(L"play bg.mp3 repeat", 0, 0, 0);
						cct_showstr(0, 0, "返回", 7, 0, 1, -1);
						cct_setcolor(0, 7);


						int flag;
				
						b.kongbai(length_, width_);
						b.create_chess(7);//开局随机生成七个珠子
						b.show();

						while (1)
						{
							cct_showstr(0, 0, "返回", 7, 0, 1, -1);

							cct_showstr(0, 31, " ", 0, 0, 50, -1);
							cct_showstr(0, 32, " ", 0, 0, 50, -1);
							flag_ = 0;
							b.anjian();
							if (flag_ == 1)
							{
								goto pal;
							}
							cct_setcolor(0, 7);
							//b.move_chess();//移动柱子

							b.show();
							//b.draw_plate();//显示移动之后的珠盘
							flag = b.panduan();//错误点2：若一个函数有返回值时，想要不多次调用该函数，就应该将返回值赋给一个变量
						
							if (flag != 0)
							{
								mciSendString(L"play move.mp3 ", 0, 0, 0);
								mciSendString(L"open move.mp3", 0, 0, 0);
								mciSendString(L"play move.mp3 ", 0, 0, 0);
								cct_gotoxy(0, 0);
								cct_setcolor(0, 7);
								cout << "本轮得分：" << flag;
								Sleep(1200);
								cct_showstr(0, 0, " ", 0, 0, 50, -1);

								cct_gotoxy(15, 0);
								cct_setcolor(0, 7);
								cout << "总得分：" << b.mark[ip] << endl;
							}
							else
							{
								cct_gotoxy(0, 0);
								cct_setcolor(0, 7);
								cout << "很遗憾本轮未得分，将重新生成三个珠子" << endl;
								Sleep(1200);
								cct_showstr(0, 0, " ", 0, 0, 50, -1);

								cct_gotoxy(15, 0);
								cct_setcolor(0, 7);
								cout << "总得分：" << b.mark[ip] << endl;
								b.create_chess(3);//随机生成三个珠子
							}

							//b.draw_plate();//显示消除之后的珠盘
							//判断一下未输入值之前是否还有消除的可能
							while (1)
							{
								flag = b.panduan();//错误点2：若一个函数有返回值时，想要不多次调用该函数，就应该将返回值赋给一个变量
								if (flag != 0)
								{
									cct_gotoxy(0, 0);
									cct_setcolor(0, 7);
									cout << "额外得分：" << flag << endl;
									Sleep(1200);
									cct_showstr(0, 0, " ", 0, 0, 50, -1);
									cct_gotoxy(15, 0);
									cct_setcolor(0, 7);
									cout << "总得分：" << b.mark[ip] << endl;
								}
								else
									break;
							}
							//判断游戏是否结束
							if (b.game_over())
							{
								cct_showstr(0, 30, " ", 0, 0, 50, -1);
								cct_showstr(0, 31, " ", 0, 0, 50, -1);
								cct_showstr(0, 32, " ", 0, 0, 50, -1);
								cct_showstr(0, 33, " ", 0, 0, 50, -1);
								cct_gotoxy(0, 30);
								cct_setcolor(0, 7);
								cout << "本局游戏结束！" << endl;
								Sleep(1000);
								goto pal;
								
							}
						}
					}
					
					
				}
			}
			
		}
		
	}
	

	


}