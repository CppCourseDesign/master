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
    string name;         //����
    int level;           //�ȼ�
    int hp;              //����
    int mp;              //ħ��
    int strength;        //����
    int intelligence;    //����
    int agility;         //����
    int crit;            //������
    int hit;             //������
    float mark;          //��ǰλ��
    string[] skill;      //����
};


class Player:public Person{ //���
public:

private:
    int experience;
    int lucky;
    Equipment
};
