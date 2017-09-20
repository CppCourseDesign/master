#pragma once
#include <iostream>
#include <FileHelper.h>
#include <Fight.h>
#include <Person.h>
#include <Shop.h>
#include <Map_cell.h>
using namespace std;

class Map {
public:
	Map(int ID);
	//地图操作
	void map_pro(Player* player);
	//输出地图
	void map_print();
	//打开技能面板
	void print_PlayerSkill(Player* player);
	//打开背包面板
	void print_PlayerBags(Player* player);
	//更换装备  //读取有问题
	void ChangeEquip(Player* player, Single* single, int i);
	//使用物品
	void UseGood(Player* player, int i);
	//打开人物面板
	void print_PlayerAttributes(Player* player);
	//输出单品
	void printSingle(Single* single);
	//打开装备面板
	void print_PlayerEquipment(Player* player);
	//输出开始剧情
	void print_scriptBegin(Player* player);
	//输出开始剧情
	void print_scriptEnd(Player* player);
	//输出开始剧情
	void print_script1(Player* player);
	//输出开始剧情
	void print_script2(Player* player);
private:
	int ID;
	Map_cell map[20];
	int cellCount;
	int printCount;
	string printMap[50];
	Monster monster;
	string scriptBegin[10];		//开始剧情
	int scriptBeginCount;		//开始剧情计数
	string scriptEnd[10];		//结束剧情
	int scriptEndCount;			//结束剧情计数
	string script1[10];			//中间剧情1
	int script1Count;				//中间剧情1计数
	string script2[10];			//中间剧情2
	int script2Count;				//中间剧情2计数
};