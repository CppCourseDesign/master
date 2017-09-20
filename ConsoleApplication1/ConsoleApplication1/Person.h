#pragma once
#include <iostream>
#include <Skill.h>
#include <Good.h>
#include <Equipment.h>
using namespace std;



//人物基类
class Person {
public:
	void setLevel(int level);
	int getLevel();
	void setName(string name);
	void setHp(int hp);
	int getHp();
	void setHpNow(int hp_now);
	int getHpNow();
	void setMp(int mp);
	int getMp();
	void setMpNow(int mp_now);
	int getMpNow();
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
	void setStrengthAll(int strength_all);
	int getStrengthAll();
	void setIntelligenceAll(int intelligence_all);
	int getIntelligenceAll();
	void setAgilityAll(int agility_all);
	int getAgilityAll();
	void setCritAll(int crit_all);
	int getCritAll();
	void setHitAll(int hit_all);
	int getHitAll();
	void setMark(float mark);
	float getMark();
	void setExperience(int experience);
	int getExperience();
	void setExperienceAll(int experience_all);
	int getExperienceAll();
	void setLucky(int lucky);
	int getLucky();
	void setMoney(int money);
	int getMoney();
	int getAttack();
	void setAttack(int attack);
	void setDefence(int defence);
	int getDefence();
	void setSkill(int i, Skill skill);
	Skill getSkill(int i);
private:
	string name;             //Ãû³Æ
	int level;               //µÈ¼¶
	int experience;
	int experience_all;
	int money;				 //金钱
	int hp;                  //hp上限
	int hp_now;              //当前hp
	int mp;                  //mp上限
	int mp_now;              //当前mp
	int attack;				 //攻击力
	int defense;			 //防御力
	int strength;            //力量
	int intelligence;        //智力
	int agility;             //敏捷
	int crit;                //暴击
	int hit;                 //命中
	int strength_all;        //力量上限
	int intelligence_all;    //智力上限
	int agility_all;         //敏捷上限
	int crit_all;            //暴击上限
	int hit_all;             //命中上限
	int mark;                //坐标
	int lucky;				 //上限
	Skill skill[3];			 //技能
};

//玩家类
class Player :public Person { 
public:
	Player(int armor_id, string armor_name, int accessories_id, string accessories_name, int arms_id, string arms_name) :equipment(armor_id, armor_name, accessories_id, accessories_name, arms_id, arms_name)
	{
		bag1_count = 0;
		bag2_count = 0;
	}
	void setEquipment(Equipment equipment);
	Equipment getEquipment();
	void addBag1(Good good);
	void setBag1Count(int count);
	int getBag1Count();
	void setBag2Count(int count);
	int getBag2Count();
	void useBag1(int thing);
	Good readBag1(int i);
	void initBag1(int i, Good thing);
	void addBag2(Single single);
	void initBag2(int i, Single thing);
	void useBag2(int thing);
	Single readBag2(int i);
	void setBag2(Single single, int i);

private:
	int bag1_count;
	int bag2_count;
	Equipment equipment;
	Good bags1[20];
	Single bags2[20];
};

//怪物类
class Monster :public Person {
public:
	Single getSingle();
	void setSingle(Single single);
	Good getFallGood(int i);
	void setFallGood(Good good, int i);
	int getFallMoney();
	void setFallMoney(int fallMoney);
	int getFallExprience();
	void setFallExperience(int fallExperience);
private:

	Single fallSingle;        //掉落装备
	Good fallGood[3];		//掉落物品
	int fallMoney;				//掉落金钱
	int fallExperience;			//掉落经验
};