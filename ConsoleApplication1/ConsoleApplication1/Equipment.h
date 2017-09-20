#pragma once
#include<iostream>
#include<Good.h>
using namespace std;


//装备类
class Equipment {
public:
	Equipment() {}
	Equipment(int armor_id, string armor_name, int accessories_id, string accessories_name, int arms_id, string arms_name) :arms(armor_id, armor_name), accessories(accessories_id, accessories_name), armor(armor_id, armor_name) {}
	void setArmor(Single armor);
	Single getArmor();
	void setAccessories(Single accessories);
	Single getAccessories();
	void setArms(Single arms);
	Single getArms();
private:
	Single armor;        //Õ½¼×
	Single accessories;  //ÊÎÆ·
	Single arms;         //ÎäÆ÷
};
