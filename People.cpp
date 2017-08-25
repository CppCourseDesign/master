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
    string name;         //名称
    int level;           //等级
    int hp;              //体力
    int mp;              //魔力
    int strength;        //力量
    int intelligence;    //智力
    int agility;         //敏捷
    int crit;            //暴击率
    int hit;             //命中率
    float mark;          //当前位置
    string[] skill;      //技能
};


class Player:public Person{ //玩家
public:

private:
    int experience;
    int lucky;
    Equipment
};
