#include<iostream>
#include<Equipment.h>
#include<Good.h>
using namespace std;

void Equipment::setArmor(Single armor) {
	this->armor = armor;
}

Single Equipment::getArmor() {
	return armor;
}

void Equipment::setAccessories(Single accessories) {
	this->accessories = accessories;
}

Single Equipment::getAccessories() {
	return accessories;
}

void Equipment::setArms(Single arms) {
	this->arms = arms;
}

Single Equipment::getArms() {
	return arms;
}