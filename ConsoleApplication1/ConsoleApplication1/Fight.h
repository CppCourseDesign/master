#pragma once
#include <iostream>
#include <Person.h>
using namespace std;

class Fight {
public:
	Fight() {
		damage = 0;
		damage = 0;
	}
	void Fight::fight_begin(Player* player, Monster* monster);
	void fighting_M(Monster* monster);
	void fighting_P(Player* player);
	void fight_end(Player* player, Monster* monster);
	void fight_fail(Player* player);
	int getDamage()
	{
		return damage;
	}
	int getDamage_f()
	{
		return damage_f;
	}
private:
	int damage;
	int damage_f;

};
