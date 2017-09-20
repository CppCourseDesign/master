#pragma once
#include<iostream>
using namespace std;


//技能类
class Skill {
public:
	string getName();
	void setName(string name);
	void setCost_mp(int cost_mp);
	int getCost_mp();
	void setCost_hp(int cost_hp);
	int getCost_hp();
	void setHurt_hp(int hurt_hp);
	int getHurt_hp();
	void setParameter(int parameter);
	int getParameter();

private:
	string name;        //技能名字
	int cost_mp;        //技能消耗mp
	int cost_hp;        //技能消耗hp
	int hurt_hp;        //技能伤害hp¦
	int parameter;      //命中率
};

