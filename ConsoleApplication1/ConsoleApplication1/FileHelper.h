#pragma once
#include <iostream>
#include <Person.h>
using namespace std;

//�ļ�������
class FileHelper
{
public:
	FileHelper() {}
	//���������Ϣ
	void SavePlayer(Player* player);
	//��ȡ�����Ϣ
	Player ReadPlayer();
	//��ȡboss��Ϣ
	Monster ReadMonster(int mapCount);

private:

};

