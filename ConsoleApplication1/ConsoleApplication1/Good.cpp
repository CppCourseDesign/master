#include<iostream>
#include<Good.h>

using namespace std;


Good::Good(string name) {
	this->name = name;
}

string Good::getName() {
	return name;
}

void Good::setName(string name) {
	this->name = name;
}
void Good::setGetMoney(int get_money) {
	this->get_money = get_money;
}

int Good::getGetMoney() {
	return get_money;
}

void Good::setOutMoney(int out_money) {
	this->out_money = out_money;
}

int Good::getOutMoney() {
	return out_money;
}

void Good::setHp(int hp) {
	this->hp = hp;
}

int Good::getHp() {
	return hp;
}

void Good::setMp(int mp) {
	this->mp = mp;
}

int Good::getMp() {
	return mp;
}

void Good::setStrength(int strength) {
	this->strength = strength;
}

int Good::getStrength() {
	return strength;
}

void Good::setIntelligence(int intelligence) {
	this->intelligence = intelligence;
}

int Good::getIntelligence() {
	return intelligence;
}

void Good::setAgility(int agility) {
	this->agility = agility;
}

int Good::getAgility() {
	return agility;
}
void Good::setCrit(int crit) {
	this->crit = crit;
}

int Good::getCrit() {
	return crit;
}

void Good::setHit(int hit) {
	this->hit = hit;
}

int Good::getHit() {
	return hit;
}



Single::Single(int id, string name) {
	this->id = id;
	setName(name);
}

void Single::setId(int id) {
	this->id = id;
}

int Single::getId() {
	return id;
}

void Single::setEquip_class(int equip_class) {
	this->equip_class = equip_class;
}

int Single::getEquip_class() {
	return equip_class;
}
void Single::setConst_hp(int const_hp) {
	this->const_hp = const_hp;
}

int Single::getConst_hp() {
	return const_hp;
}

void Single::setConst_mp(int const_mp) {
	this->const_mp = const_mp;
}

int Single::getConst_mp() {
	return const_mp;
}