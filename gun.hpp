#ifndef GUN_H
#define GUN_H
#include <iostream>
#include <list>
#include <ctime>
#include "person.hpp"
#include "ammo.hpp"
#include "sleep.hpp"
using namespace std;
class Gun{
	private:
		int ammo_;
		int maxAmmo_;
		int reloadSpeed_;
		int shotSpeed_;
		int ammoType_;
		int ammoPower_;
		
	public:
		Gun()
		{
			ammo_=0;
			maxAmmo_=6;
			reloadSpeed_=3;
			shotSpeed_=0;
			ammoType_=3;
			ammoPower_=0;
		}
		void reload(list<Ammo> &ammo)
		{
			int enc=0;
			int aux=ammo_;
			list<Ammo>::iterator it;
			for(it=ammo.begin();it!=ammo.end() and enc==0;it++)
			{
				if(it->getType()==ammoType_)
					enc=1;
				if(enc)
					cout<<"Recargando..."<<endl;
			}
			it=ammo.begin();
			while(ammo_<maxAmmo_ and enc==1 and !ammo.empty() and it!=ammo.end())
			{
				if(it->getType()==ammoType_)
				{
					ammoPower_=it->getPower();
					it->setType(0);
					ammo_++;
				}
				it++;
			}
			if(aux==ammo_)
				cout<<"No hay munición."<<endl;
			else
			{
				sleep(reloadSpeed_);
				cout<<"Recargado "<<ammo_-aux<<" bala/s."<<endl;
			}

		}
		void shoot(Person &target, list<Ammo> &ammo)
		{
			if(target.getHP()<=0)
				cout<<"El objetivo está muerto."<<endl;
			else if(ammo_>0)
			{
				cout<<"Disparo a "<<target.getID()<<"."<<endl;
				target.setHP(target.getHP()-ammoPower_);
				ammo_--;
				sleep(shotSpeed_);
			}
			else if(ammo_==0)
			{
				cout<<"No queda munición para seguir disparando."<<endl;
				reload(ammo);
			}
		}
};
#endif
