#include <iostream>
#include <Map_cell.h>
using namespace std;

Map_cell::Map_cell(int mark, int N, int S, int E, int W, int f)
{
	map_flag = mark;
	N_flag = N;
	S_flag = S;
	E_flag = E;
	W_flag = W;
	flag = f;
}

void Map_cell::setMap_cell(int mark, int N, int S, int E, int W, int f) {
	map_flag = mark;
	N_flag = N;
	S_flag = S;
	E_flag = E;
	W_flag = W;
	flag = f;
}

int Map_cell::linker_N(int i)
{
	int change = 0;
	New_flag = map_flag;
	if (N_flag == 0)
		cout << "你不能继续向北走了。" << endl;
	else {
		//change = map_flag;
		New_flag = change + N_flag + 100 * i;
	}
	return New_flag;

}

int Map_cell::linker_S(int i)
{
	int change = 0;
	New_flag = map_flag;
	if (S_flag == 0)
		cout << "你不能继续向南走了。" << endl;
	else {
		//change = map_flag;
		New_flag = change + S_flag + 100 * i;
	}

	return New_flag;
}

int Map_cell::linker_E(int i)
{
	int change = 0;
	New_flag = map_flag;
	if (E_flag == 0)
		cout << " 你不能继续向东走了。" << endl;
	else {
		//change = map_flag;
		New_flag = change + E_flag + 100 * i;
	}

	return New_flag;
}

int Map_cell::linker_W(int i)
{
	int change = 0;
	New_flag = map_flag;
	if (W_flag == 0)
		cout << " 你不能继续向西走了。" << endl;
	else {
		//change = map_flag;
		New_flag = change + W_flag + 100 * i;
	}

	return New_flag;
}