#include "Infrastructure.h"

Infrastructure::Infrastructure(){}


Infrastructure::Infrastructure(string name, string city, Coordinates c) {
	this->name = name;
	this->city = city;
	this->c = c;
}

ostream& operator<<(ostream& ekran, const Infrastructure& obj) {
	ekran << obj.name << "; " << obj.city
		<< "; " << obj.c
		<< endl;
	return ekran;
}

Coordinates Infrastructure::get_Coordinates() {
	return c;
}

void Infrastructure::show_Infrastructure()
{
	cout << "Nazwa: " << name << ", " << "miasto: " << city << ", " << "wspolrzedne: " << c << endl;
	cout << "-------------------------------------------------------" << endl;
}

 int Infrastructure::compiude_distanse( Building* b) {
	Coordinates c;

	 return c.coordinate_distanse(get_Coordinates(), b->get_coordinates());
	 
}