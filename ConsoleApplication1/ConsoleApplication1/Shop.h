#pragma once
#include <iostream>
#include <Person.h>
#include <Good.h>

using namespace std;

class Shop {
public:
	//购买
	void Buy(Player* player, Good good[50], int* goodCount, Single single[50], int* singleCount);

	//出售
	void Sell(Player* player, Good good[50], int* goodCount, Single single[50], int* singleCount);

	//输出商店
	void print_Shop(Player* player);
};
