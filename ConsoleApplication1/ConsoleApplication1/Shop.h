#pragma once
#include <iostream>
#include <Person.h>
#include <Good.h>

using namespace std;

class Shop {
public:
	//����
	void Buy(Player* player, Good good[50], int* goodCount, Single single[50], int* singleCount);

	//����
	void Sell(Player* player, Good good[50], int* goodCount, Single single[50], int* singleCount);

	//����̵�
	void print_Shop(Player* player);
};
