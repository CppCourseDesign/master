#include <iostream>
#include <Person.h>
using namespace std;

/*===============Person成员函数===============*/

void Person::setLevel(int level) {
	this->level = level;
}

int Person::getLevel() {
	return level;
}

void Person::setName(string name) {
	this->name = name;
}

void Person::setHp(int hp) {
	this->hp = hp;
}

int Person::getHp() {
	return hp;
}

void Person::setHpNow(int hp_now) {
	this->hp_now = hp_now;
}

int Person::getHpNow() {
	return hp_now;
}

void Person::setMp(int mp) {
	this->mp = mp;
}

int Person::getMp() {
	return mp;
}

void Person::setMpNow(int mp_now) {
	this->mp_now = mp_now;
}

int Person::getMpNow() {
	return mp_now;
}

void Person::setStrength(int strength) {
	this->strength = strength;
}

int Person::getStrength() {
	return strength;
}

void Person::setIntelligence(int intelligence) {
	this->intelligence = intelligence;
}

int Person::getIntelligence() {
	return intelligence;
}

void Person::setAgility(int agility) {
	this->agility = agility;
}

int Person::getAgility() {
	return agility;
}

void Person::setCrit(int crit) {
	this->crit = crit;
}

int Person::getCrit() {
	return crit;
}

void Person::setHit(int hit) {
	this->hit = hit;
}

int Person::getHit() {
	return hit;
}

void Person::setStrengthAll(int strength_all) {
	this->strength_all = strength_all;
}

int Person::getStrengthAll() {
	return strength_all;
}

void Person::setIntelligenceAll(int intelligence_all) {
	this->intelligence_all = intelligence_all;
}

int Person::getIntelligenceAll() {
	return intelligence_all;
}

void Person::setAgilityAll(int agility_all) {
	this->agility_all = agility_all;
}
int Person::getAgilityAll() {
	return agility_all;
}

void Person::setCritAll(int crit_all) {
	this->crit_all = crit_all;
}

int Person::getCritAll() {
	return crit_all;
}

void Person::setHitAll(int hit_all) {
	this->hit_all = hit_all;
}

int Person::getHitAll() {
	return hit_all;
}
void Person::setMark(float mark) {
	this->mark = mark;
}

float Person::getMark() {
	return mark;
}
void Person::setExperience(int experience) {
	this->experience = experience;
}

int Person::getExperience() {
	return experience;
}

void Person::setExperienceAll(int experience_all) {
	this->experience_all = experience_all;
}

int Person::getExperienceAll() {
	return experience_all;
}

void Person::setLucky(int lucky) {
	this->lucky = lucky;
}
int Person::getLucky() {
	return lucky;
}

void Person::setMoney(int money) {
	this->money = money;
}

int Person::getMoney() {
	return money;
}

int Person::getAttack() {
	return attack;
}

void Person::setAttack(int attack) {
	this->attack = attack;
}

void Person::setDefence(int defence) {
	this->defense = defence;
}

int Person::getDefence() {
	return defense;
}

void Person::setSkill(int i, Skill skill) {
	this->skill[i] = skill;
}

Skill Person::getSkill(int i) {
	return skill[i];
}


/*===============Player成员函数===============*/

void Player::setEquipment(Equipment equipment) {
	this->equipment = equipment;
}

Equipment Player::getEquipment() {
	return equipment;
}

void Player::addBag1(Good good) {
	bags1[bag1_count] = good;
	bag1_count++;
}

void Player::setBag1Count(int count) {
	bag1_count = count;
}

int Player::getBag1Count() {
	return bag1_count;
}

void Player::setBag2Count(int count) {
	bag2_count = count;
}

int Player::getBag2Count() {
	return bag2_count;
}

void Player::useBag1(int thing) {
	//Good good_temp = bags1[thing - 1];
	for (int i = thing; i < bag1_count - thing; i++)
		bags1[i] = bags1[i + 1];
	bag1_count--;
	//return good_temp;
}

Good Player::readBag1(int i) {
	return bags1[i];
}

void Player::initBag1(int i, Good thing) {
	bags1[i] = thing;
}

void Player::addBag2(Single single) {
	bags2[bag2_count] = single;
	bag2_count++;

}

void Player::initBag2(int i, Single thing) {
	bags2[i] = thing;
}

void Player::useBag2(int thing) {
	//Single good_temp = bags2[thing - 1];
	for (int i = thing; i < bag2_count - thing; i++)
		bags2[i] = bags2[i + 1];
	bag2_count--;
	//return good_temp;
}

Single Player::readBag2(int i) {
	return bags2[i];
}

void Player::setBag2(Single single, int i) {
	bags2[i] = single;
}

/*===============Monster成员函数===============*/

Single Monster::getSingle() {
	return	fallSingle;
}
void Monster::setSingle(Single single) {
	this->fallSingle = single;
}
Good Monster::getFallGood(int i) {
	return fallGood[i];
}
void Monster::setFallGood(Good good, int i) {
	fallGood[i] = good;
}
int Monster::getFallMoney() {
	return fallMoney;
}
void Monster::setFallMoney(int fallMoney) {
	this->fallMoney = fallMoney;
}
int Monster::getFallExprience() {
	return fallExperience;
}
void Monster::setFallExperience(int fallExperience) {
	this->fallExperience = fallExperience;
}