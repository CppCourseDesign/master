#include<iostream>
using namespace std;

class Equipment{
public:

private:
    Single armor;        //ս��
    Single accessories;  //��Ʒ
    Single arms;         //����
};


class Single{            //��Ʒ
public:

private:
    int id;              //id
    string name;         //����
    int equip_class;     //��Ʒ����  1.ս��  2.��Ʒ  3.����
    int const_mp;        //ħ��
    int strength;        //����
    int intelligence;    //����
    int agility;         //����
    int crit;            //������
    int hit;             //������
};

