#pragma once
#include <iostream>
using namespace std;


//��ͼ������
class Map_cell
{
public:
	Map_cell(int mark = 1.1, int N = 0, int S = 0, int E = 0, int W = 0, int flag = 0);
	void setMap_cell(int mark, int N, int S, int E, int W, int flag);
	int linker_N(int i);     //��ͼcell֮�����ӵ�Ԫ ���ڴӵ�ǰcell������cell�ƶ� N S W E����ȷ������
	int linker_S(int i);
	int linker_W(int i);
	int linker_E(int i);

	int map_flag;       //��player�ϵ�mark������Ӧ ����3.14(����ͼ3�ϵ�cell_14   ��ȷ�����ɵ�ͼ��100��cell
	int New_flag;
	int N_flag, S_flag, W_flag, E_flag;  // ��linkָ���Ӧ ȷ��ÿ��link�����ӵ�cell���

	int flag;			   //0�޴���,1Ϊ���飬2Ϊbuff��3ΪС�֣�4Ϊboss


private:


};