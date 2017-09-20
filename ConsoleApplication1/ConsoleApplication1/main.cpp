#include <iostream>
#include <fstream>
#include <string>
#include<Person.h>
#include<Map.h>
#include<FileHelper.h>
#include<Fight.h>

using namespace std;

int main()
{
	FileHelper filehelper;
	Fight fight;
	Map map1(1), map2(2), map3(3), map4(4);
	Map map[4] = { map1,map2,map3,map4 };

	Player player = filehelper.ReadPlayer();
	player = filehelper.ReadPlayer();
	char flag_start = '7';
	while (flag_start != '1'&&flag_start != '2') {
		cout << "*************************************************************************" << endl;
		cout << "*                                                                       *" << endl;
		cout << "*                                                                       *" << endl;
		cout << "*                           1. �µĿ�ʼ                                 *" << endl;
		cout << "*                           2. �ɵĻ���                                 *" << endl;
		cout << "*                           0. ������Ϸ                                 *" << endl;
		cout << "*                                                                       *" << endl;
		cout << "*                                                                       *" << endl;
		cout << "*************************************************************************" << endl;
		cin >> flag_start;
		if (flag_start == '1') {
			system("cls");
			if (player.getMark() != 101)
				player.setMark(101);
			map[0].print_scriptBegin(&player);
		}
		else if (flag_start == '2') {
			system("cls");
			map[(int)(player.getMark() / 100) - 1].print_scriptBegin(&player);
		}
		else if (flag_start == '0')
			exit(0);
		else {
			cout << "warning!";
			system("cls");
			flag_start = '7';
		}
	}
	//�л���ͼ
	while ((player.getMark() / 100) < 5) {
		map[(int)(player.getMark() / 100) - 1].print_scriptEnd(&player);
		player.setMark(((int)(player.getMark() / 100) + 1) * 100 + 1);
		if (player.getMark() / 100 < 5)
			map[(int)(player.getMark() / 100) - 1].print_scriptBegin(&player);
	}
	system("cls");
	cout << "Ŷ������ĵ�ͼ�����Ѿ������ˡ�����������" << endl << endl;
	system("pause");
	return 0; 
}