#include<iostream>
using namespace std;

class Person{
public:
    Person(string name) {
        this->name = name;
        level = 1;
        strength = 100;
        intelligence = 100;
        agility = 100;
        mark = 0;
    }
    void setName(string name) {
        this.name = name;
    }
    string getName() {
        return name;
    }
    void setLevel(int level) {
        this.level = level;
    }
    int getLevel() {
        return level;
    }
    void setHp(int hp) {
        this.hp = hp;
    }
    int getHp() {
        return hp;
    }
    void setMp(int mp) {
        this.mp = mp;
    }
    int getMp() {
        return mp;
    }
    void setStrength(int strength) {
        this.strength = strength;
    }
    int getStrength() {
        return strength;
    }
    void setIntelligence(int intelligence) {
        this.intelligence = intelligence;
    }
    int getIntelligence() {
        return intelligence;
    }
    void setAgility(int agility) {
        this.agility = agility;
    }
    int getAgility() {
        return agility;
    }
    void setCrit(int crit) {
        this.crit = crit;
    }
    int getCrit() {
        return crit;
    }
    void setHit(int hit) {
        this.hit = hit;
    }
    int getHit() {
        return hit;
    }
    void setMark(float mark) {
        this.mark = mark;
    }
    int getMark() {
        return mark;
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
    Skill[] skill;       //技能
};

class Player:public Person{ //玩家
public:
    Player(string name):Person(string name) {}
    void setExperience(int experience) {
        this.experience = experience;
    }
    int geteExperience() {
        return experience;
    }
    void setLucky(int lucky) {
        this.lucky = lucky;
    }
    int getLucky() {
        return lucky;
    }
    void setEquipment(Equipment& equipment){
        this.equipment = equipment;
    }
    Equipment getEquipment() {
        return equipment;
    }
private:
    int experience;
    int lucky;
    Equipment equipment;
};

class Monster:public Person{ //怪物
public:
    Monster(string name):Person(string name) {}

    void setLucky(int lucky) {
        this.lucky = lucky;
    }
    int geteLucky() {
        return lucky;
    }
private:
    int lucky;
    Equipment[] fall;        //掉落
};

