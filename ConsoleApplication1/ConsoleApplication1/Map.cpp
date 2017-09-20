#include <iostream>
#include <Map.h>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


Map::Map(int ID) {
	//��ʼ����ͼ
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
		//��ʼ��MapCell����
		is >> cellCount;
		for (int i = 0; i < cellCount; i++)
		{
			int mark, W, S, A, D, flag;
			is >> mark >> W >> S >> A >> D >> flag;
			map[i].setMap_cell(mark, W, S, A, D, flag);			
		}
		//��ʼ����ͼͼ��
		is >> printCount;
		for (int i = 0; i < printCount; i++)
			getline(is, printMap[i]);

		//��ʼ����ʼ����
		is >> scriptBeginCount;
		for (int i = 0; i < scriptBeginCount; i++)
			is >> scriptBegin[i];

		//��ʼ����������
		is >> scriptEndCount;
		for (int i = 0; i < scriptEndCount; i++)
			is >> scriptEnd[i];

		//��ʼ������1
		is >> script1Count;
		for (int i = 0; i < script1Count; i++)
			is >> script1[i];

		//��ʼ������2
		is >> script2Count;
		for (int i = 0; i < script2Count; i++)
			is >> script2[i];
	}
	//��ʼ��boss
	FileHelper fh;
	monster = fh.ReadMonster(ID);
}
//�����ʼ����
void Map::print_scriptBegin(Player* player) {
	cout << endl << endl;
	for (int i = 0; i < scriptBeginCount; i++)
		cout << scriptBegin[i] << endl << endl;
	cout << endl << "����E������Ϸ:";
	char flag;
	cin >> flag;
	while (flag != 'E')
		cin >> flag;
	system("cls");
	map_pro(player);
}
//�����β����
void Map::print_scriptEnd(Player* player) {
	cout << endl << endl;
	for (int i = 0; i < scriptEndCount; i++)
		cout << scriptEnd[i] << endl << endl;
	cout << endl << "����E������һ��ͼ:";
	char flag;
	cin >> flag;
	while (flag != 'E')
		cin >> flag;
	system("cls");
}
//����м����1
void Map::print_script1(Player* player) {
	cout << endl << endl;
	for (int i = 0; i < script1Count; i++)
		cout << script1[i] << endl << endl;
	cout << endl << "����Z������Ϸ:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}
//����м����2
void Map::print_script2(Player* player) {
	cout << endl << endl;
	for (int i = 0; i < script2Count; i++)
		cout << script2[i] << endl << endl;
	cout << endl << "����Z������Ϸ:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}
//��ͼ����
void Map::map_pro(Player* player) {
	FileHelper fh;
	Shop shop;
	int marks = player->getMark();
	int mark = marks % 100;
	int Z_flag = 0;
	map_print();
	cout << "����ǰ��λ���� ��" << mark << endl;
	cout << "����W A S D ѡ���ƶ�" << endl;
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
			cout << "=========����ս����=========" << endl;
			fight.fight_begin(player, &monster);
			break;
		default:break;
		}
		if (map[mark - 1].flag != 5) {
			cout << "����ǰ��λ���� ��" << mark << endl;
			cout << "����W A S D ѡ���ƶ�" << endl;
		}
	}
}
//�����ͼ
void Map::map_print() {
	for (int i = 0; i < printCount; i++)
		cout << printMap[i] << endl;
}
//�򿪼������
void Map::print_PlayerSkill(Player* player) {
	for (int i = 0; i < 3; i++)
	{
		Skill skill = player->getSkill(i);
		cout << skill.getName() << endl;
		cout << "����hp :  " << skill.getCost_hp() << endl;
		cout << "����mp :  " << skill.getCost_mp() << endl;
		cout << "�˺�   :  " << skill.getHurt_hp() << endl;
		cout << endl;
	}
	cout << "����Z������һ��:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}
//�򿪱������
void Map::print_PlayerBags(Player* player) {
	cout << " ---------------" << endl;
	for (int i = 0; i < player->getBag1Count(); i++)
		cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << "|" << endl;
	for (int i = 0; i < player->getBag2Count(); i++)
		cout << "|   " << i + 1 + player->getBag1Count() << ":  " << left << setw(8) << player->readBag2(i).getName() << "|" << endl;
	cout << " ----------------" << endl;

	cout << "�������ʹ����Ʒ(����0������һ��): ";
	int flag;
	cin >> flag;
	while (flag != 0)
	{
		if (flag > player->getBag1Count())
			ChangeEquip(player, &(player->readBag2(flag - 1 - player->getBag1Count())), flag - 1 - player->getBag1Count());//����װ��
		else
			UseGood(player, flag - 1);//ʹ����Ʒ
		system("cls");

		cout << " ---------------" << endl;
		for (int i = 0; i < player->getBag1Count(); i++)
			cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << "|" << endl;
		for (int i = 0; i < player->getBag2Count(); i++)
			cout << "|   " << i + 1 + player->getBag1Count() << ":  " << left << setw(8) << player->readBag2(i).getName() << "|" << endl;
		cout << " ----------------" << endl;
		cout << "�������ʹ����Ʒ(����0������һ��): ";
		cin >> flag;
	}
	system("cls");
	map_print();
}
//����װ��  
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
//ʹ����Ʒ
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
//���������
void Map::print_PlayerAttributes(Player* player) {
	cout << "--------------------------------------------------------" << endl;
	cout << "|                                                      |" << endl;
	cout << "|   ����:         " << player->getHpNow() << "\\" << player->getHp() << "                              |" << endl;
	cout << "|   ħ��:         " << player->getMpNow() << "\\" << player->getMp() << "                                |" << endl;
	cout << "|   ������:                " << player->getAttack() << "                          |" << endl;
	cout << "|   ������:                " << player->getDefence() << "                          |" << endl;
	cout << "|   ����:         " << player->getStrength() << "\\" << player->getStrengthAll() << "                                  |" << endl;
	cout << "|   ����:         " << player->getIntelligence() << "\\" << player->getIntelligenceAll() << "                                  |" << endl;
	cout << "|   ����:         " << player->getAgility() << "\\" << player->getAgilityAll() << "                                  |" << endl;
	cout << "|   ������:       " << player->getCrit() << "\\" << player->getCritAll() << "                                  |" << endl;
	cout << "|   ������:       " << player->getHit() << "\\" << player->getHitAll() << "                                 |" << endl;
	cout << "|                                                      |" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "����Z������һ��:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}
//�����Ʒ
void Map::printSingle(Single* single) {
	cout << single->getName() << endl;
	cout << "����:         " << single->getStrength() << endl;
	cout << "����:         " << single->getIntelligence() << endl;
	cout << "����:         " << single->getAgility() << endl;
	cout << "������:       " << single->getCrit() << endl;
	cout << "������:       " << single->getHit() << endl << endl;
}
//��װ�����
void Map::print_PlayerEquipment(Player* player) {
	cout << "����" << endl;
	printSingle(&(player->getEquipment().getArmor()));
	cout << "����" << endl;
	printSingle(&(player->getEquipment().getAccessories()));
	cout << "��Ʒ" << endl;
	printSingle(&(player->getEquipment().getArms()));
	cout << "����Z������һ��:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	map_print();
}