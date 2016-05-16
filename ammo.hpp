#ifndef AMMO_H
#define AMMO_H
class Ammo{
	private:
		int type_;
		int power_;
	public:
		Ammo(int type, int power)
		{
			type_=type;
			power_=power_;
		}
		int getType(){return type_;}
		int getPower(){return power_;}
		void setType(int t){type_=t;}
		void setPower(int p){power_=p;}
};
#endif
