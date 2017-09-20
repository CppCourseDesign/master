#include<iostream>
#include<Skill.h>

using namespace std;

string Skill::getName() {
	return name;
}

void Skill::setName(string name) {
		this->name = name;
}

void Skill::setCost_mp(int cost_mp){
	this->cost_mp = cost_mp;
}


int Skill::getCost_mp() {
	return cost_mp;
}
void Skill::setCost_hp(int cost_hp) {
	this->cost_hp = cost_hp;
};
int Skill::getCost_hp() {
	return cost_hp;
}
void Skill::setHurt_hp(int hurt_hp) {
	this->hurt_hp = hurt_hp;
};
int Skill::getHurt_hp() {
	return hurt_hp;
}
void Skill::setParameter(int parameter) {
	this->parameter = parameter;
};
int Skill::getParameter() {
	return parameter;
}