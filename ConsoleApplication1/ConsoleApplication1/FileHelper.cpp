#include <iostream>
#include <iomanip>
#include<string>
#include <fstream>
#include <FileHelper.h>
#include <Person.h>
using namespace std;

//保存玩家信息
void FileHelper::SavePlayer(Player* player) {

	ofstream out("Player.txt");
	ofstream out_skill("Skill.txt");
	ofstream out_equip("Equipment.txt");
	ofstream out_bags1("Bag1.txt");
	ofstream out_bags2("Bag2.txt");

	// Player player(1, "11", 2, "22", 3, "33");
	// int tem; 
	// double temp;
	// string temp_string;

	if (!out.is_open() || !out_skill.is_open() || !out_equip.is_open() || !out_bags1.is_open())
		cout << "file can't open!" << endl;
	else {
		{
			//存入基本属性
			out << player->getLevel() << endl;
			out << player->getExperience() << endl;
			out << player->getExperienceAll() << endl;
			out << player->getMoney() << endl;
			out << player->getHp() << endl;
			out << player->getHpNow() << endl;
			out << player->getMp() << endl;
			out << player->getMpNow() << endl;
			out << player->getAttack() << endl;
			out << player->getDefence() << endl;
			out << player->getStrength() << endl;
			out << player->getIntelligence() << endl;
			out << player->getAgility() << endl;
			out << player->getCrit() << endl;
			out << player->getHit() << endl;
			out << player->getStrengthAll() << endl;
			out << player->getIntelligenceAll() << endl;
			out << player->getAgilityAll() << endl;
			out << player->getCritAll() << endl;
			out << player->getHitAll() << endl;
			out << player->getLucky() << endl;
			out << player->getMark() << endl;
		}
		//存入技能
		//Skill temp_Skill;
		for (int i = 0; i < 3; i++)
		{
			out_skill << player->getSkill(i).getName() << endl;
			out_skill << player->getSkill(i).getCost_mp() << endl;
			out_skill << player->getSkill(i).getCost_hp() << endl;
			out_skill << player->getSkill(i).getHurt_hp() << endl;
			out_skill << player->getSkill(i).getParameter() << endl;
		}
		//存入装备
		Equipment equip;
		//盔甲
		out_equip << player->getEquipment().getArmor().getId() << endl;
		out_equip << player->getEquipment().getArmor().getName() << endl;
		out_equip << player->getEquipment().getArmor().getEquip_class() << endl;
		out_equip << player->getEquipment().getArmor().getConst_hp() << endl;
		out_equip << player->getEquipment().getArmor().getConst_mp() << endl;
		out_equip << player->getEquipment().getArmor().getStrength() << endl;
		out_equip << player->getEquipment().getArmor().getIntelligence() << endl;
		out_equip << player->getEquipment().getArmor().getAgility() << endl;
		out_equip << player->getEquipment().getArmor().getCrit() << endl;
		out_equip << player->getEquipment().getArmor().getHit() << endl;
		out_equip << player->getEquipment().getArmor().getGetMoney() << endl;
		out_equip << player->getEquipment().getArmor().getOutMoney() << endl;
		//武器
		out_equip << player->getEquipment().getArms().getId() << endl;
		out_equip << player->getEquipment().getArms().getName() << endl;
		out_equip << player->getEquipment().getArms().getEquip_class() << endl;
		out_equip << player->getEquipment().getArms().getConst_hp() << endl;
		out_equip << player->getEquipment().getArms().getConst_mp() << endl;
		out_equip << player->getEquipment().getArms().getStrength() << endl;
		out_equip << player->getEquipment().getArms().getIntelligence() << endl;
		out_equip << player->getEquipment().getArms().getAgility() << endl;
		out_equip << player->getEquipment().getArms().getCrit() << endl;
		out_equip << player->getEquipment().getArms().getHit() << endl;
		out_equip << player->getEquipment().getArms().getGetMoney() << endl;
		out_equip << player->getEquipment().getArms().getOutMoney() << endl;
		//饰品
		out_equip << player->getEquipment().getAccessories().getId() << endl;
		out_equip << player->getEquipment().getAccessories().getName() << endl;
		out_equip << player->getEquipment().getAccessories().getEquip_class() << endl;
		out_equip << player->getEquipment().getAccessories().getConst_hp() << endl;
		out_equip << player->getEquipment().getAccessories().getConst_mp() << endl;
		out_equip << player->getEquipment().getAccessories().getStrength() << endl;
		out_equip << player->getEquipment().getAccessories().getIntelligence() << endl;
		out_equip << player->getEquipment().getAccessories().getAgility() << endl;
		out_equip << player->getEquipment().getAccessories().getCrit() << endl;
		out_equip << player->getEquipment().getAccessories().getHit() << endl;
		out_equip << player->getEquipment().getAccessories().getGetMoney() << endl;
		out_equip << player->getEquipment().getAccessories().getOutMoney() << endl;

		//存入背包
		{
			//is_bags1 >> tem;
			//player.setBag1Count(tem);
			int bag1count = player->getBag1Count();
			out_bags1 << player->getBag1Count() << endl;
			for (int i = 0; i < player->getBag1Count(); i++)
			{
				//is_bags1 >> temp_string;
				//Good good(temp_string);
				out_bags1 << player->readBag1(i).getName() << endl;
				out_bags1 << player->readBag1(i).getGetMoney() << endl;
				out_bags1 << player->readBag1(i).getOutMoney() << endl;
				out_bags1 << player->readBag1(i).getHp() << endl;
				out_bags1 << player->readBag1(i).getMp() << endl;
				out_bags1 << player->readBag1(i).getStrength() << endl;
				out_bags1 << player->readBag1(i).getIntelligence() << endl;
				out_bags1 << player->readBag1(i).getAgility() << endl;
				out_bags1 << player->readBag1(i).getCrit() << endl;
				out_bags1 << player->readBag1(i).getHit() << endl;
			}
			player->setBag1Count(bag1count);
			//is_bags2 >> tem;
			//player.setBag2Count(tem);
			int bag2count = player->getBag2Count();
			out_bags2 << player->getBag2Count() << endl;
			for (int i = 0; i < player->getBag2Count(); i++)
			{
				//is_bags2 >> tem >> temp_string;
				//Single single_temp(tem, temp_string);
				out_bags2 << player->readBag2(i).getId() << endl;
				out_bags2 << player->readBag2(i).getName() << endl;
				out_bags2 << player->readBag2(i).getEquip_class() << endl;
				out_bags2 << player->readBag2(i).getConst_hp() << endl;
				out_bags2 << player->readBag2(i).getConst_mp() << endl;
				out_bags2 << player->readBag2(i).getStrength() << endl;
				out_bags2 << player->readBag2(i).getIntelligence() << endl;
				out_bags2 << player->readBag2(i).getAgility() << endl;
				out_bags2 << player->readBag2(i).getCrit() << endl;
				out_bags2 << player->readBag2(i).getHit() << endl;
				out_bags2 << player->readBag2(i).getGetMoney() << endl;
				out_bags2 << player->readBag2(i).getOutMoney() << endl;
			}
			player->setBag2Count(bag2count);
		}
	}
}
//读取玩家信息
Player FileHelper::ReadPlayer() {

	ifstream is("Player.txt");
	ifstream is_skill("Skill.txt");
	ifstream is_equip("Equipment.txt");
	ifstream is_bags1("Bag1.txt");
	ifstream is_bags2("Bag2.txt");


	Player player(1, "11", 2, "22", 3, "33");
	int tem;
	double temp;
	string temp_string;

	if (!is.is_open() || !is_skill.is_open() || !is_equip.is_open() || !is_bags1.is_open())
		cout << "file can't open!" << endl;
	else {
		{
			//初始化基本属性
			is >> tem;
			player.setLevel(tem);
			is >> tem;
			player.setExperience(tem);
			is >> tem;
			player.setExperienceAll(tem);
			is >> tem;
			player.setMoney(tem);
			is >> tem;
			player.setHp(tem);
			is >> tem;
			player.setHpNow(tem);
			is >> tem;
			player.setMp(tem);
			is >> tem;
			player.setMpNow(tem);
			is >> tem;
			player.setAttack(tem);
			is >> tem;
			player.setDefence(tem);
			is >> tem;
			player.setStrength(tem);
			is >> tem;
			player.setIntelligence(tem);
			is >> tem;
			player.setAgility(tem);
			is >> tem;
			player.setCrit(tem);
			is >> tem;
			player.setHit(tem);
			is >> tem;
			player.setStrengthAll(tem);
			is >> tem;
			player.setIntelligenceAll(tem);
			is >> tem;
			player.setAgilityAll(tem);
			is >> tem;
			player.setCritAll(tem);
			is >> tem;
			player.setHitAll(tem);
			is >> tem;
			player.setLucky(tem);
			is >> temp;
			player.setMark(temp);
		}

		//初始化技能
		Skill temp_Skill;
		for (int i = 0; i < 3; i++)
		{
			is_skill >> temp_string >> tem;
			temp_Skill.setName(temp_string);
			temp_Skill.setCost_mp(tem);
			is_skill >> tem;
			temp_Skill.setCost_hp(tem);
			is_skill >> tem;
			temp_Skill.setHurt_hp(tem);
			is_skill >> tem;
			temp_Skill.setParameter(tem);
			player.setSkill(i, temp_Skill);
		}
		//初始化装备
		Equipment equip;
		for (int i = 0; i < 3; i++)
		{
			is_equip >> tem >> temp_string;
			Single single_temp(tem, temp_string);
			is_equip >> tem;
			single_temp.setEquip_class(tem);
			is_equip >> tem;
			single_temp.setConst_hp(tem);
			is_equip >> tem;
			single_temp.setConst_mp(tem);
			is_equip >> tem;
			single_temp.setStrength(tem);
			is_equip >> tem;
			single_temp.setIntelligence(tem);
			is_equip >> tem;
			single_temp.setAgility(tem);
			is_equip >> tem;
			single_temp.setCrit(tem);
			is_equip >> tem;
			single_temp.setHit(tem);
			is_equip >> tem;
			single_temp.setGetMoney(tem);
			is_equip >> tem;
			single_temp.setOutMoney(tem);
			if (single_temp.getId() == 1)
				equip.setArmor(single_temp);
			else if (single_temp.getId() == 2)
				equip.setAccessories(single_temp);
			else
				equip.setArms(single_temp);
		}
		player.setEquipment(equip);
		//读入背包
		{
			is_bags1 >> tem;
			player.setBag1Count(tem);
			for (int i = 0; i < player.getBag1Count(); i++)
			{
				is_bags1 >> temp_string;
				Good good(temp_string);
				is_bags1 >> tem;
				good.setGetMoney(tem);
				is_bags1 >> tem;
				good.setOutMoney(tem);
				is_bags1 >> tem;
				//is_bags1 >> tem;
				good.setHp(tem);
				is_bags1 >> tem;
				good.setMp(tem);
				is_bags1 >> tem;
				good.setStrength(tem);
				is_bags1 >> tem;
				good.setIntelligence(tem);
				is_bags1 >> tem;
				good.setAgility(tem);
				is_bags1 >> tem;
				good.setCrit(tem);
				is_bags1 >> tem;
				good.setHit(tem);
				player.initBag1(i, good);
			}
			is_bags2 >> tem;
			player.setBag2Count(tem);
			for (int i = 0; i < player.getBag2Count(); i++)
			{
				is_bags2 >> tem >> temp_string;
				Single single_temp(tem, temp_string);
				is_bags2 >> tem;
				single_temp.setEquip_class(tem);
				is_bags2 >> tem;
				single_temp.setConst_hp(tem);
				is_bags2 >> tem;
				single_temp.setConst_mp(tem);
				is_bags2 >> tem;
				single_temp.setStrength(tem);
				is_bags2 >> tem;
				single_temp.setIntelligence(tem);
				is_bags2 >> tem;
				single_temp.setAgility(tem);
				is_bags2 >> tem;
				single_temp.setCrit(tem);
				is_bags2 >> tem;
				single_temp.setHit(tem);
				is_bags2 >> tem;
				single_temp.setGetMoney(tem);
				is_bags2 >> tem;
				single_temp.setOutMoney(tem);
				player.initBag2(i, single_temp);
			}
		}

	}
	is.close();
	is_skill.close();
	is_equip.close();
	is_bags1.close();
	is_bags2.close();

	//SavePlayer(player);

	return player;
}
//读取boss信息
Monster FileHelper::ReadMonster(int mapCount) {

	ifstream is("monster1.txt");

	Monster monster, monster_map[4];
	int tem;
	string temp_string;


	if (!is.is_open())
		cout << "file can't open!" << endl;
	else {
		for (int j = 0; j < 4; j++)
		{
			//设置初始属性
			{
				is >> tem;
				monster.setLevel(tem);
				is >> tem;
				monster.setHp(tem);
				is >> tem;
				monster.setHpNow(tem);
				is >> tem;
				monster.setMp(tem);
				is >> tem;
				monster.setMpNow(tem);
				is >> tem;
				monster.setDefence(tem);
				is >> tem;
				monster.setAttack(tem);
				is >> tem;
				monster.setStrength(tem);
				is >> tem;
				monster.setIntelligence(tem);
				is >> tem;
				monster.setAgility(tem);
				is >> tem;
				monster.setCrit(tem);
				is >> tem;
				monster.setHit(tem);
				is >> tem;
				monster.setStrengthAll(tem);
				is >> tem;
				monster.setIntelligenceAll(tem);
				is >> tem;
				monster.setAgilityAll(tem);
				is >> tem;
				monster.setCritAll(tem);
				is >> tem;
				monster.setHitAll(tem);
				is >> tem;
				monster.setMark(tem);
				is >> tem;
				monster.setLucky(tem);
				is >> tem;
				monster.setFallMoney(tem);
			}
			//设置技能
			Skill skill;
			for (int i = 0; i < 3; i++)
			{
				is >> temp_string >> tem;
				skill.setName(temp_string);
				skill.setCost_mp(tem);
				is >> tem;
				skill.setCost_hp(tem);
				is >> tem;
				skill.setHurt_hp(tem);
				is >> tem;
				skill.setParameter(tem);
				monster.setSkill(i, skill);
			}
			//掉落物品
			{
				Single fallSingle;
				is >> tem >> temp_string;
				Single single(tem, temp_string);
				is >> tem;
				fallSingle.setEquip_class(tem);
				is >> tem;
				fallSingle.setConst_hp(tem);
				is >> tem;
				fallSingle.setConst_mp(tem);
				is >> tem;
				fallSingle.setStrength(tem);
				is >> tem;
				fallSingle.setIntelligence(tem);
				is >> tem;
				fallSingle.setAgility(tem);
				is >> tem;
				fallSingle.setCrit(tem);
				is >> tem;
				fallSingle.setHit(tem);
				is >> tem;
				fallSingle.setGetMoney(tem);
				is >> tem;
				fallSingle.setOutMoney(tem);
				monster.setSingle(fallSingle);
			}
			//掉落物品
			Good fallGood;
			for (int i = 0; i < 3; i++)
			{
				is >> temp_string;
				Good fallGood(temp_string);
				is >> tem;
				fallGood.setGetMoney(tem);
				is >> tem;
				fallGood.setOutMoney(tem);
				is >> tem;
				fallGood.setHp(tem);
				is >> tem;
				fallGood.setMp(tem);
				is >> tem;
				fallGood.setStrength(tem);
				is >> tem;
				fallGood.setIntelligence(tem);
				is >> tem;
				fallGood.setAgility(tem);
				is >> tem;
				fallGood.setCrit(tem);
				is >> tem;
				fallGood.setHit(tem);
				monster.setFallGood(fallGood, i);
			}
			monster_map[j] = monster;
		}
	}

	is.close();

	return monster_map[mapCount - 1];
}