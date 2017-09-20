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
	//��ͼ����
	void map_pro(Player* player);
	//�����ͼ
	void map_print();
	//�򿪼������
	void print_PlayerSkill(Player* player);
	//�򿪱������
	void print_PlayerBags(Player* player);
	//����װ��  //��ȡ������
	void ChangeEquip(Player* player, Single* single, int i);
	//ʹ����Ʒ
	void UseGood(Player* player, int i);
	//���������
	void print_PlayerAttributes(Player* player);
	//�����Ʒ
	void printSingle(Single* single);
	//��װ�����
	void print_PlayerEquipment(Player* player);
	//�����ʼ����
	void print_scriptBegin(Player* player);
	//�����ʼ����
	void print_scriptEnd(Player* player);
	//�����ʼ����
	void print_script1(Player* player);
	//�����ʼ����
	void print_script2(Player* player);
private:
	int ID;
	Map_cell map[20];
	int cellCount;
	int printCount;
	string printMap[50];
	Monster monster;
	string scriptBegin[10];		//��ʼ����
	int scriptBeginCount;		//��ʼ�������
	string scriptEnd[10];		//��������
	int scriptEndCount;			//�����������
	string script1[10];			//�м����1
	int script1Count;				//�м����1����
	string script2[10];			//�м����2
	int script2Count;				//�м����2����
};