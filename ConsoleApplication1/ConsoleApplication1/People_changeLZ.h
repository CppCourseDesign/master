#ifndef FIGHT_DEMO_H_INCLUDED
#define FIGHT_DEMO_H_INCLUDED

#include<iostream>
using namespace std;

class Person{
public:
    Person(string name){
        this->name = name;
        level = 1;
        strength = 100;
        intelligence = 100;
        agility = 100;
        mark = 0;
    }
private:
    string name;             //名称
    int level;               //等级
    int hp_all;              //体力
    int hp;                  //体力（基础）
    int hp_now;              //体力（当前）
    int mp_all;              //魔力
    int mp;                  //魔力（基础）
    int mp_now;              //体力（当前）
    int strength;            //力量（基础）
    int intelligence;        //智力（基础）
    int agility;             //敏捷（基础）
    int crit;                //暴击率（基础）
    int hit;                 //命中率（基础）
    int strength_all;        //力量
    int intelligence_all;    //智力
    int agility_all;         //敏捷
    int crit_all;            //暴击率
    int hit_all;             //命中率
    float mark;              //当前位置
    Skill[] skill;           //技能
};


class Player:public Person{ //玩家
public:

private:
    int experience;
    int lucky;
    Equipment equipment;
};

class Monster:public Person{ //怪物
public:

private:
    Equipment[] fall;        //掉落
};

#endif // FIGHT_DEMO_H_INCLUDED
