#include<iostream>
using namespace std;

class Equipment{
public:
    void setArmor(Single& armor){
        this.armor = armor;
    }
    Single getArmor() {
        return armor;
    }
    void setAccessories(Single& accessories){
        this.accessories = accessories;
    }
    Single getAccessories() {
        return accessories;
    }
    void setArms(Single& arms){
        this.arms= arms;
    }
    Single getArms() {
        return arms;
    }

private:
    Single armor;        //战甲
    Single accessories;  //饰品
    Single arms;         //武器
};


class Single{            //单品
public:
    Single(int id, string name) {
        id = 1;
        this->name = name;
    }
    void setId(int id) {
        this.id = id;
    }
    int getId() {
        return id;
    }
    void setName(string name) {
        this.name = name;
    }
    string getName() {
        return name;
    }
    void setEquip_class(int equip_class) {
        this.equip_class = equip_class;
    }
    int getName() {
        return equip_class;
    }
    void setConst_mp(int const_mp) {
        this.const_mp = const_mp;
    }
    int getConst_mp() {
        return const_mp;
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
