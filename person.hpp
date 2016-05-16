#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "gun.hpp"
using namespace std;
class Person{
	private:
		int hp_;
		unsigned int id_;
		Gun gun_;
		string name_;
	public:
		Person(int hp=256, unsigned int id=0000, string name="")
		{
			Gun Magnum;
			if(hp>0)
				hp_=hp;
			id_=id;
			gun_=Magnum;
			name_=name;
		}
		int getHP(){return hp_;}
		unsigned int getID(){return id_;}
		Gun getGun(){return gun_;}
		string getName(){return name_;}
		void setHP(int hp){hp_=hp;}
		void setID(unsigned int id){id_=id;}
		void setGun(Gun gun){gun_=gun;}
		void setName(string n){name_=n;}
};
#endif
