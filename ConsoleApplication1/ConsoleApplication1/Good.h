#pragma once
#include <iostream>
using namespace std;

//消耗品类
class Good {
public:
	Good() {}
	Good(string name);
	string getName();
	void setName(string name);
	void setGetMoney(int get_money);
	int getGetMoney();
	void setOutMoney(int out_money);
	int getOutMoney();
	void setHp(int hp);
	int getHp();
	void setMp(int mp);
	int getMp();
	void setStrength(int strength);
	int getStrength();
	void setIntelligence(int intelligence);
	int getIntelligence();
	void setAgility(int agility);
	int getAgility();
	void setCrit(int crit);
	int getCrit();
	void setHit(int hit);
	int getHit();
private:
	string name;         //物品名称
	int get_money;       //购买价钱
	int out_money;       //出售价钱
	int hp;              //获得hp
	int mp;              //获得mp
	int strength;        //获得力量
	int intelligence;    //获得智力
	int agility;         //获得敏捷
	int crit;            //获得暴击
	int hit;             //获得命中

};


//装备单品类
class Single :public Good {
public:
	Single() {}
	Single(int id, string name);
	void setId(int id);
	int getId();
	void setEquip_class(int equip_class);
	int getEquip_class();
	void setConst_hp(int const_hp);
	int getConst_hp();
	void setConst_mp(int const_mp);
	int getConst_mp();
private:
	int id;              //id
	int equip_class;     //分类:1.盔甲 2.武器 3.饰品
	int const_hp;        //hp
	int const_mp;        //mp
};
