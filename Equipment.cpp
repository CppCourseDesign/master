#include<iostream>
using namespace std;

class Equipment{
public:

private:
    Single armor;        //战甲
    Single accessories;  //饰品
    Single arms;         //武器
};


class Single{            //单品
public:

private:
    int id;              //id
    string name;         //名称
    int equip_class;     //单品类型  1.战甲  2.饰品  3.武器
    int const_mp;        //魔力
    int strength;        //力量
    int intelligence;    //智力
    int agility;         //敏捷
    int crit;            //暴击率
    int hit;             //命中率
};

