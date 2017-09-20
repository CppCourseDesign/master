#pragma once
#include <iostream>
#include <Person.h>
using namespace std;

//文件操作类
class FileHelper
{
public:
	FileHelper() {}
	//保存玩家信息
	void SavePlayer(Player* player);
	//读取玩家信息
	Player ReadPlayer();
	//读取boss信息
	Monster ReadMonster(int mapCount);

private:

};

