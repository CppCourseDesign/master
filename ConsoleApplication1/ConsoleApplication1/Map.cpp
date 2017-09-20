#include <iostream>
#include <Map.h>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


Map::Map(int ID) {
	//初始化地图
	this->ID = ID;
	ifstream is;
	switch (ID)
	{
	case 1:
		is.open("map1.txt");
		break;
	case 2:
		is.open("map2.txt");
		break;
	case 3:
		is.open("map3.txt");
		break;
	case 4:
		is.open("map4.txt");
		break;
	default:
		break;
	}

	
	if (!is.is_open())
		cout << "error!" << endl;
	else
	{
		//初始化MapCell属性
		is >> cellCount;
		for (int i = 0; i < cellCount; i++)
		{
			int mark, W, S, A, D, flag;
			is >> mark >> W >> S >> A >> D >> flag;
			map[i].setMap_cell(mark, W, S, A, D, flag);			
		}
		//初始化地图图形
		is >> printCount;
		for (int i = 0; i < printCount; i++)
			getline(is, printMap[i]);

		//初始化开始剧情
		is >> scriptBeginCount;
		for (int i = 0; i < scriptBeginCount; i++)
			is >> scriptBegin[i];

		//初始化结束剧情
		is >> scriptEndCount;
		for (int i = 0; i < scriptEndCount; i++)
			is >> scriptEnd[i];

		//初始化剧情1
		is >> script1Count;
		for (int i = 0; i < script1Count; i++)
			is >> script1[i];

		//初始化剧情2
		is >> script2Count;
		for (int i = 0; i < script2Count; i++)
			is >> script2[i];
	}
	//初始化boss
	FileHelper fh;
	monster = fh.ReadMonster(ID);
}
//输出开始剧情
void Map::print_scriptBegin(Player* player) {
	cout << endl << endl;
	for (int i = 0; i < scriptBeginCount; i++)
		cout << scriptBegin[i] << endl << endl;
	cout << endl << "输入E继续游戏:";
	char flag;
	cin >> flag;
	while (flag != 'E')
		cin >> flag;
	system("cls");
	map_pro(player);
}
//输出结尾剧情
void Map::print_scriptEnd(Player* player) {
	cout << endl << endl;
	for (int i = 0; i < scriptEndCount; i++)
		cout << scriptEnd[i] << endl << endl;
	cout << endl << "输入E进入下一地图:";
	char flag;
	cin >> flag;
	while (flag != 'E')
		cin >> flag;
	system("cls");
}
//输出中间剧情1
void Map::print_script1(Player* player) {
	cout << endl << endl;
	for (int i = 0; i < script1Count; i++)
		cout << script1[i] << endl << endl;
	cout << endl << "输入Z继续游戏:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}
//输出中间剧情2
void Map::print_script2(Player* player) {
	cout << endl << endl;
	for (int i = 0; i < script2Count; i++)
		cout << script2[i] << endl << endl;
	cout << endl << "输入Z继续游戏:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}
//地图操作
void Map::map_pro(Player* player) {
	FileHelper fh;
	Shop shop;
	int marks = player->getMark();
	int mark = marks % 100;
	int Z_flag = 0;
	map_print();
	cout << "您当前的位置是 ：" << mark << endl;
	cout << "输入W A S D 选择移动" << endl;
	while (map[mark - 1].flag != 5)
	{
		char flag;
		cin >> flag;
		system("cls");
		switch (flag)
		{
		case 'W':
			marks = map[mark - 1].linker_N(marks / 100) ;
			mark = marks % 100;
			player->setMark(marks);
			map_print();
			break;
		case 'A':
			marks = map[mark - 1].linker_W(marks / 100);
			mark = marks % 100;
			player->setMark(marks);
			map_print();
			break;
		case 'S':
			marks = map[mark - 1].linker_S(marks / 100);
			mark = marks % 100;
			player->setMark(marks);
			map_print();
			break;
		case 'D':
			marks = map[mark - 1].linker_E(marks / 100);
			player->setMark(marks);
			mark = marks % 100;
			map_print();
			break;
		case 'C':
			print_PlayerAttributes(player);
			break;
		case 'B':
			print_PlayerBags(player);
			break;
		case 'E':
			print_PlayerEquipment(player);
			break;
		case 'P':
			print_PlayerSkill(player);
			break;
		case 'X':
			fh.SavePlayer(player);
			break;
		default:
			map_print();
			break;
		}
		Fight fight;
		switch (map[mark - 1].flag)
		{
		case 0:
			break;
		case 1:
			system("cls");
			shop.print_Shop(player);
			break;
		case 2:
			system("cls");
			print_script1(player);
			break;
		case 3:
			system("cls");
			print_script2(player);
			break;
		case 5:
			system("cls");
			cout << "=========进入战斗！=========" << endl;
			fight.fight_begin(player, &monster);
			break;
		default:break;
		}
		if (map[mark - 1].flag != 5) {
			cout << "您当前的位置是 ：" << mark << endl;
			cout << "输入W A S D 选择移动" << endl;
		}
	}
}
//输出地图
void Map::map_print() {
	for (int i = 0; i < printCount; i++)
		cout << printMap[i] << endl;
}
//打开技能面板
void Map::print_PlayerSkill(Player* player) {
	for (int i = 0; i < 3; i++)
	{
		Skill skill = player->getSkill(i);
		cout << skill.getName() << endl;
		cout << "消耗hp :  " << skill.getCost_hp() << endl;
		cout << "消耗mp :  " << skill.getCost_mp() << endl;
		cout << "伤害   :  " << skill.getHurt_hp() << endl;
		cout << endl;
	}
	cout << "输入Z返回上一级:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}
//打开背包面板
void Map::print_PlayerBags(Player* player) {
	cout << " ---------------" << endl;
	for (int i = 0; i < player->getBag1Count(); i++)
		cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << "|" << endl;
	for (int i = 0; i < player->getBag2Count(); i++)
		cout << "|   " << i + 1 + player->getBag1Count() << ":  " << left << setw(8) << player->readBag2(i).getName() << "|" << endl;
	cout << " ----------------" << endl;

	cout << "输入序号使用物品(输入0返回上一级): ";
	int flag;
	cin >> flag;
	while (flag != 0)
	{
		if (flag > player->getBag1Count())
			ChangeEquip(player, &(player->readBag2(flag - 1 - player->getBag1Count())), flag - 1 - player->getBag1Count());//更换装备
		else
			UseGood(player, flag - 1);//使用物品
		system("cls");

		cout << " ---------------" << endl;
		for (int i = 0; i < player->getBag1Count(); i++)
			cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << "|" << endl;
		for (int i = 0; i < player->getBag2Count(); i++)
			cout << "|   " << i + 1 + player->getBag1Count() << ":  " << left << setw(8) << player->readBag2(i).getName() << "|" << endl;
		cout << " ----------------" << endl;
		cout << "输入序号使用物品(输入0返回上一级): ";
		cin >> flag;
	}
	system("cls");
	map_print();
}
//更换装备  
void Map::ChangeEquip(Player* player, Single* single, int i) {
	Single temp;
	if (single->getId() == 1)
	{
		temp = player->getEquipment().getArmor();
		player->getEquipment().setArmor(*single);
	}
	else if (single->getId() == 2)
	{
		temp = player->getEquipment().getAccessories();
		player->getEquipment().setAccessories(*single);
	}
	else
	{
		temp = player->getEquipment().getArms();
		player->getEquipment().setArms(*single);
	}
	player->setBag2(temp, i);
}
//使用物品
void Map::UseGood(Player* player, int i) {
	Good good = player->readBag1(i);
	player->setHpNow((player->getHpNow() + good.getHp()) > player->getHp() ? player->getHp() : (player->getHpNow() + good.getHp()));
	player->setMpNow((player->getMpNow() + good.getMp()) > player->getMp() ? player->getMp() : (player->getMpNow() + good.getMp()));
	player->setStrength((player->getStrength() + good.getStrength()) > player->getStrengthAll() ? player->getStrengthAll() : (player->getStrength() + good.getStrength()));
	player->setIntelligence((player->getIntelligence() + good.getIntelligence()) > player->getIntelligenceAll() ? player->getIntelligenceAll() : player->getIntelligence() + good.getIntelligence());
	player->setAgility((player->getAgility() + good.getAgility()) > player->getAgilityAll() ? player->getAgilityAll() : (player->getAgility() + good.getAgility()));
	player->setCrit((player->getCrit() + good.getCrit()) > good.getCrit() ? good.getCrit() : (player->getCrit() + good.getCrit()));
	player->useBag1(i);
}
//打开人物面板
void Map::print_PlayerAttributes(Player* player) {
	cout << "--------------------------------------------------------" << endl;
	cout << "|                                                      |" << endl;
	cout << "|   体力:         " << player->getHpNow() << "\\" << player->getHp() << "                              |" << endl;
	cout << "|   魔力:         " << player->getMpNow() << "\\" << player->getMp() << "                                |" << endl;
	cout << "|   攻击力:                " << player->getAttack() << "                          |" << endl;
	cout << "|   防御力:                " << player->getDefence() << "                          |" << endl;
	cout << "|   力量:         " << player->getStrength() << "\\" << player->getStrengthAll() << "                                  |" << endl;
	cout << "|   智力:         " << player->getIntelligence() << "\\" << player->getIntelligenceAll() << "                                  |" << endl;
	cout << "|   敏捷:         " << player->getAgility() << "\\" << player->getAgilityAll() << "                                  |" << endl;
	cout << "|   暴击率:       " << player->getCrit() << "\\" << player->getCritAll() << "                                  |" << endl;
	cout << "|   命中率:       " << player->getHit() << "\\" << player->getHitAll() << "                                 |" << endl;
	cout << "|                                                      |" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "输入Z返回上一级:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}
//输出单品
void Map::printSingle(Single* single) {
	cout << single->getName() << endl;
	cout << "力量:         " << single->getStrength() << endl;
	cout << "智力:         " << single->getIntelligence() << endl;
	cout << "敏捷:         " << single->getAgility() << endl;
	cout << "暴击率:       " << single->getCrit() << endl;
	cout << "命中率:       " << single->getHit() << endl << endl;
}
//打开装备面板
void Map::print_PlayerEquipment(Player* player) {
	cout << "盔甲" << endl;
	printSingle(&(player->getEquipment().getArmor()));
	cout << "武器" << endl;
	printSingle(&(player->getEquipment().getAccessories()));
	cout << "饰品" << endl;
	printSingle(&(player->getEquipment().getArms()));
	cout << "输入Z返回上一级:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}