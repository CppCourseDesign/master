#include <iostream>
#include <string>
#include <iomanip>
#include <Person.h>
#include <Fight.h>
#include <Map.h>
using namespace std;


//战斗过程
void Fight::fighting_P(Player* player)
{
	char flag_f, flag_s;                                         ///flag_f记录战斗动作 flag_s记录技能动作
	int flag = 0;
	cout << "1.攻击 2.使用技能 3.使用物品" << endl;
	cout << "请输入战斗指令:";
	cin >> flag_f;
	while (flag == 0)
	{

		if (flag_f == '1')
		{
			//damage = 100 * player->getStrengthAll() * 0.05;     ///默认面板攻击为100 力量系数为20 普通攻击伤害为 （面板*力量/20)
			damage = 99;
			cout << "你使用了普通攻击,对敌方造成了" << damage << "点伤害" << endl;    //普通攻击
			flag = 1;                                     ///成功执行动作后flag=1 跳出循环
		}
		else if (flag_f == '2')
		{
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << "." << player->getSkill(i).getName() << endl;
			}
			cout << "请选择你要使用的技能：" << endl;
			cin >> flag_s;

			if (flag_s == '1' || flag_s == '2' || flag_s == '3') {           ///我居然发现'3'有点可爱
				damage = player->getSkill(flag_s - 49).getHurt_hp();
				if (player->getMp() - player->getSkill(flag_s - 49).getCost_mp() < 0)
					cout << "MP不足！" << endl;
				player->setMp(player->getMp() - player->getSkill(flag_s - 49).getCost_mp());
				cout << "你使用了技能" << player->getSkill(flag_s - 49).getName() << ", 对敌方造成了" << damage << "点伤害" << endl;
				flag = 1;
			}
			else
				flag = 0;
		}
		else if (flag_f == '3')
		{
			cout << " ---------------" << endl;
			for (int i = 0; i < player->getBag1Count(); i++)
				cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << "|" << endl;
			cout << " ----------------" << endl;

			cout << "输入序号使用物品: ";
			int flagM;
			cin >> flagM;
			Good good = player->readBag1(flagM - 1);
			player->setHpNow((player->getHpNow() + good.getHp()) > player->getHp() ? player->getHp() : (player->getHpNow() + good.getHp()));
			player->setMpNow((player->getMpNow() + good.getMp()) > player->getMp() ? player->getMp() : (player->getMpNow() + good.getMp()));
			player->setStrength((player->getStrength() + good.getStrength()) > player->getStrengthAll() ? player->getStrengthAll() : (player->getStrength() + good.getStrength()));
			player->setIntelligence((player->getIntelligence() + good.getIntelligence()) > player->getIntelligenceAll() ? player->getIntelligenceAll() : player->getIntelligence() + good.getIntelligence());
			player->setAgility((player->getAgility() + good.getAgility()) > player->getAgilityAll() ? player->getAgilityAll() : (player->getAgility() + good.getAgility()));
			player->setCrit((player->getCrit() + good.getCrit()) > good.getCrit() ? good.getCrit() : (player->getCrit() + good.getCrit()));
			player->useBag1(flagM - 1);
			cout << "您使用了" << good.getName() << endl;
			if (good.getHp() != 0)
				cout << "增加HP" << good.getHp() << endl;
			if (good.getMp() != 0)
				cout << "增加MP" << good.getMp() << endl;
			flag = 1;
		}
		else
		{
			cout << "指令错误" << endl;
			flag = 0;
		}
	}
}

void Fight::fighting_M(Monster* monster)
{
	damage = (1 + 0.02*(monster->getHp() - monster->getHpNow())) *(monster->getStrengthAll() + monster->getCrit() + monster->getHit()) *0.05;  ///伤害计算同人物普通攻击
	//damage = 1;
	cout << "敌方对你造成了" << damage << "点伤害。";
}

//战斗结算
void Fight::fight_end(Player* player, Monster* monster)
{
	for (int i = 0; i < 3; i++)
		player->addBag1(monster->getFallGood(i));
	player->addBag2(monster->getSingle());
	player->setMoney(player->getMoney() + monster->getFallMoney());
	if (player->getExperience() + monster->getFallExprience() > player->getExperienceAll())
	{
		player->setExperience(0);
		player->setLevel(player->getLevel() + 1);
	}
	else
		player->setLevel(player->getExperience() + monster->getFallExprience());
	cout << "YOU WIN" << endl;
	cout << "您获得：" << endl;
	cout << monster->getFallGood(0).getName() << endl << monster->getFallGood(1).getName() << endl << monster->getFallGood(2).getName() << endl;
	cout << monster->getSingle().getName() << endl;// << monster->getMoney() << "金钱" << endl << monster->getFallExprience() << "经验" << endl;
	cout << "输入Z继续游戏:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");

}

void Fight::fight_fail(Player* player)
{
	cout << "YOU DIED" << endl;
	cout << "输入Z返回上一级:";
	char flag;
	cin >> flag;
	while (flag != 'Z')
		cin >> flag;
	system("cls");
	char flag_start = '7';
	while (flag_start != '1'&&flag_start != '2') {
		cout << "*************************************************************************" << endl;
		cout << "*                                                                       *" << endl;
		cout << "*                                                                       *" << endl;
		cout << "*                           1. 新的开始                                 *" << endl;
		cout << "*                           2. 旧的回忆                                 *" << endl;
		cout << "*                           0. 结束游戏                                 *" << endl;
		cout << "*                                                                       *" << endl;
		cout << "*                                                                       *" << endl;
		cout << "*************************************************************************" << endl;
		cin >> flag_start;
		if (flag_start == '1') {
			system("cls");
			//map[0].map_pro(&player);
		}
		else if (flag_start == '2') {
			system("cls");
			//map[(int)(player.getMark() / 100) - 1].map_pro(&player);
		}
		else if (flag_start == '0')
			exit(0);
		else {
			cout << "warning!";
			system("cls");
			flag_start = '7';
		}
	}

}


void Fight::fight_begin(Player* player, Monster* monster)
{
	while (player->getHpNow() > 0 && monster->getHpNow() > 0)
	{
		if (player->getAgility() >= monster->getAgility())
		{
			fighting_P(player);
			monster->setHpNow(monster->getHpNow() - getDamage());
			cout << "  敌方体力(" << monster->getHpNow() << "/" << monster->getHp() << ")" << endl;
			if (monster->getHpNow() > 0)
			{
				fighting_M(monster);
				player->setHpNow(player->getHpNow() - getDamage());
				cout << "  你的体力(" << player->getHpNow() << "/" << player->getHp() << ")" << endl;
				if (player->getHpNow() <= 0)
					fight_fail(player);
			}
			else
				fight_end(player, monster);
		}
		else
		{
			fighting_M(monster);
			player->setHpNow(player->getHpNow() - getDamage());
			cout << "  你的体力(" << player->getHpNow() << "/" << player->getHp() << ")" << endl;
			if (player->getHpNow() > 0)
			{
				fighting_P(player);
				monster->setHpNow(monster->getHpNow() - getDamage());
				cout << "  敌方体力(" << monster->getHpNow() << "/" << monster->getHp() << ")" << endl;
				if (monster->getHpNow() <= 0)
					fight_end(player, monster);
			}
			else
				fight_fail(player);
		}

	}
}