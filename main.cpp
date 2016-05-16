#include "gun.hpp"
#include "ammo.hpp"
#include "person.hpp"
#include <list>
int main()
{
	Gun g;
	Person p;
	Ammo a(3,200);
	list<Ammo> ammo;
	for(int i=0;i<25;i++)
	{
		ammo.push_back(a);
	}
	g.shoot(p,ammo);
	return 0;
}
