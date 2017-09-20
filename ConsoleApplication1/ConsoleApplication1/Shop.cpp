#include <iostream>
#include <fstream>
#include <string>
#include <Good.h>
#include <Person.h>
#include <Shop.h>
#include <iomanip>
#include <Map.h>
using namespace std;

//购买
void Shop::Buy(Player* player, Good good[50], int* goodCount, Single single[50], int* singleCount) {
	cout << "输入物品前序号购买:";
	int number;
	cin >> number;
	if (number > *goodCount)
	{
		//购买装备
		Single sing = single[number - *goodCount - 1];
		if (player->getMoney() > sing.getGetMoney()) {
			player->addBag2(sing);
			for (int i = number - 1 - *goodCount; i < *goodCount + *singleCount - 1; i++)
				single[i] = single[i + 1];
			(*singleCount)--;
			cout << "购买成功！" << endl;
			player->setMoney(player->getMoney() - sing.getGetMoney());
			//输出背包
			{
				cout << endl << "您的背包: " << endl;
				cout << " ---------------" << endl;
				for (int i = 0; i < player->getBag1Count(); i++)
					cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << "|" << endl;
				for (int i = 0; i < player->getBag2Count(); i++)
					cout << "|   " << i + 1 + player->getBag1Count() << ":  " << left << setw(8) << player->readBag2(i).getName() << "|" << endl;
				cout << " ----------------" << endl;
			}
		}
		else
		{
			cout << "金钱不足，不能购买。" << endl;
		}
	}
	else
	{
		//购买物品
		Good goods = good[number - 1];
		if (player->getMoney() > goods.getGetMoney()) {
			player->addBag1(goods);
			for (int i = number - 1; i < *goodCount - 1; i++)
				good[i] = good[i + 1];
			(*goodCount)--;
			player->setMoney(player->getMoney() - goods.getGetMoney());
			cout << "购买成功！" << endl;
			//输出背包
			{
				cout << endl << "您的背包: " << endl;
				cout << " ---------------" << endl;
				for (int i = 0; i < player->getBag1Count(); i++)
					cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << "|" << endl;
				for (int i = 0; i < player->getBag2Count(); i++)
					cout << "|   " << i + 1 + player->getBag1Count() << ":  " << left << setw(8) << player->readBag2(i).getName() << "|" << endl;
				cout << " ----------------" << endl;
			}
		}
		else
		{
			cout << "金钱不足，不能购买。" << endl;
		}
	}

}

//出售
void Shop::Sell(Player* player, Good good[50], int* goodCount, Single single[50], int* singleCount) {
	{
		cout << " ---------------" << endl;
		for (int i = 0; i < player->getBag1Count(); i++)
			cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << player->readBag1(i).getOutMoney() << "  " << "|" << endl;
		for (int i = 0; i < player->getBag2Count(); i++)
			cout << "|   " << i + 1 + player->getBag1Count() << ":  " << left << setw(8) << player->readBag2(i).getName() << player->readBag2(i).getOutMoney() << "  " << "|" << endl;
		cout << " ----------------" << endl;
	}
	cout << "请选择出售物品" << endl;
	int flag;
	cin >> flag;
	if (flag > player->getBag1Count())
	{
		//出售装备
		player->setMoney(player->getMoney() + player->readBag2(flag - *goodCount - 1).getOutMoney());
		player->useBag2(flag - *goodCount - 1);
		//输出背包
		{
			cout << endl << "您的背包: " << endl;
			cout << " ---------------" << endl;
			for (int i = 0; i < player->getBag1Count(); i++)
				cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << "|" << endl;
			for (int i = 0; i < player->getBag2Count(); i++)
				cout << "|   " << i + 1 + player->getBag1Count() << ":  " << left << setw(8) << player->readBag2(i).getName() << "|" << endl;
			cout << " ----------------" << endl;
			//cout << player->getMoney() << endl;
		}
	}
	else
	{
		//出售物品
		player->setMoney(player->getMoney() + player->readBag1(flag - 1).getOutMoney());
		player->useBag1(flag - 1);
		//输出背包
		{
			cout << endl << "您的背包: " << endl;
			cout << " ---------------" << endl;
			for (int i = 0; i < player->getBag1Count(); i++)
				cout << "|   " << i + 1 << ":  " << left << setw(8) << player->readBag1(i).getName() << "|" << endl;
			for (int i = 0; i < player->getBag2Count(); i++)
				cout << "|   " << i + 1 + player->getBag1Count() << ":  " << left << setw(8) << player->readBag2(i).getName() << "|" << endl;
			cout << " ----------------" << endl;
		}
		cout << player->getMoney() << endl;
	}
}

//输出商店
void Shop::print_Shop(Player* player) {
	//打印商店商品
	ifstream is_bags1("Shop1.txt");
	ifstream is_bags2("Shop2.txt");
	int tem, shop1Count, shop2Count;
	string temp_string;


	is_bags1 >> shop1Count;
	Good shop1[50];
	cout << "**********************" << endl;
	cout << "**********************" << endl;
	for (int i = 0; i < shop1Count; i++)
	{
		is_bags1 >> temp_string;
		Good good(temp_string);
		is_bags1 >> tem;
		good.setGetMoney(tem);
		is_bags1 >> tem;
		good.setOutMoney(tem);
		is_bags1 >> tem;
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

		shop1[i] = good;

		cout << i + 1 << " " << shop1[i].getName() << "  价格: " << shop1[i].getGetMoney() << endl;
	}
	is_bags2 >> shop2Count;
	Single shop2[50];
	for (int i = 0; i < shop2Count; i++)
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

		shop2[i] = single_temp;

		cout << shop1Count + i + 1 << " " << shop2[i].getName() << "  价格: " << shop2[i].getGetMoney() << endl;
	}
	cout << "**********************" << endl;
	cout << "**********************" << endl << endl;

	int flag;
	cout<< "当前您的金币数为"  << player->getMoney() << ",输入1购买商品，2出售商品，0离开商店: ";
	cin >> flag;
	while (flag != 0)
	{
		if (flag == 1)
			Buy(player, shop1, &shop1Count, shop2, &shop2Count);
		else if (flag == 2)
			Sell(player, shop1, &shop1Count, shop2, &shop2Count);
		else
		{

		}
		//输出商店
		{
			cout << "**********************" << endl;
			cout << "**********************" << endl;
			for (int i = 0; i < shop1Count; i++)
				cout << i + 1 << " " << shop1[i].getName() << "  价格: " << shop1[i].getGetMoney() << endl;
			for (int i = 0; i < shop2Count; i++)
				cout << shop1Count + i + 1 << " " << shop2[i].getName() << "  价格: " << shop2[i].getGetMoney() << endl;
			cout << "**********************" << endl;
			cout << "**********************" << endl << endl;
		}
		cout << "当前您的金币数为" << player->getMoney() << ",输入1购买商品，2出售商品，0离开商店: ";
		cin >> flag;
	}
	Map map(player->getMark()/100);
	system("cls");
	map.map_print();


}