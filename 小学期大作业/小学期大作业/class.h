#pragma once
void anjian();
class chess {
public:
	int x, y;//����
	int col;//��ɫ
};
class chessplate {
public:
	int mark[100] = { 0 };
	int x_, y_;
	chess a[9][9];//����
	int loc[9][9] = { 0 };//���Ӽ�¼��

	void create_chess(int i);//������ɸ�����Ŀ������
	void move_chess();//�ƶ�����
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
