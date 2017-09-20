#pragma once
#include <iostream>
using namespace std;


//地图格子类
class Map_cell
{
public:
	Map_cell(int mark = 1.1, int N = 0, int S = 0, int E = 0, int W = 0, int flag = 0);
	void setMap_cell(int mark, int N, int S, int E, int W, int flag);
	int linker_N(int i);     //地图cell之间连接单元 用于从当前cell向相邻cell移动 N S W E用于确定方向
	int linker_S(int i);
	int linker_W(int i);
	int linker_E(int i);

	int map_flag;       //与player上的mark变量对应 形如3.14(即地图3上的cell_14   可确定若干地图上100个cell
	int New_flag;
	int N_flag, S_flag, W_flag, E_flag;  // 与link指令对应 确定每个link所连接的cell编号

	int flag;			   //0无触发,1为剧情，2为buff，3为小怪，4为boss


private:


};