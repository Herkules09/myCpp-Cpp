#ifndef INFRASTRUCTURE
#define INFRASTRUCTURE
#include "Header.h"
#include"Coordinates.h"
#include"Building.h"
class Infrastructure
{
private:
	string name;
	string city;
	Coordinates c;
public:
	Infrastructure();
	Infrastructure(string name,string city,Coordinates c);
	friend ostream& operator<<(ostream& ekran, const Infrastructure& obj);
	Coordinates get_Coordinates();
	void show_Infrastructure();
	 int compiude_distanse( Building * b);
};

#endif