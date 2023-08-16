#pragma once
void anjian();
class chess {
public:
	int x, y;//坐标
	int col;//颜色
};
class chessplate {
public:
	int mark[100] = { 0 };
	int x_, y_;
	chess a[9][9];//棋子
	int loc[9][9] = { 0 };//棋子记录器

	void create_chess(int i);//随机生成给定数目的棋子
	void move_chess();//移动棋子
	int panduan();
	bool game_over();
	void kongbai(int x, int y);
	void show_each(int x, int y);
	void show();
	void highlight(int x, int y);
	void clear(int x, int y);
	void anjian();
	void xuanzhong(int x, int y);
};
