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
    string name;             //����
    int level;               //�ȼ�
    int hp_all;              //����
    int hp;                  //������������
    int hp_now;              //��������ǰ��
    int mp_all;              //ħ��
    int mp;                  //ħ����������
    int mp_now;              //��������ǰ��
    int strength;            //������������
    int intelligence;        //������������
    int agility;             //���ݣ�������
    int crit;                //�����ʣ�������
    int hit;                 //�����ʣ�������
    int strength_all;        //����
    int intelligence_all;    //����
    int agility_all;         //����
    int crit_all;            //������
    int hit_all;             //������
    float mark;              //��ǰλ��
    Skill[] skill;           //����
};


class Player:public Person{ //���
public:

private:
    int experience;
    int lucky;
    Equipment equipment;
};

class Monster:public Person{ //����
public:

private:
    Equipment[] fall;        //����
};

#endif // FIGHT_DEMO_H_INCLUDED
