#pragma once
//15_21
//дһ����Ϸ��ɫ�������Եļ̳���ϵ��
//15_22
#include<iostream>
struct Skill {

};
struct Character {
protected:
	int heal;
	int MP;
};
struct Monster:public Character {
public:

private:
	//item fallen_item;
protected:
	Skill A;
	Skill B;
	Skill C;
};
struct Player :public Monster {
public:
	//control ctrl;
private:

protected:
	//map<int,item> bag;
};