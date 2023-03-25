#include"Header.h"
#include "House.h"

House::House() {}

House::House(bool _garden, string prize, int area, string city, string street, string type_of_building, Stan* stan,Coordinates coordinates) :Building(prize, area, city, street, type_of_building, stan,coordinates) {
	this->garden = _garden;
}
House::House(bool garden,string prize, int area, string city, string street, string type_of_building,Coordinates coordinates) : Building(prize, area, city, street, type_of_building, new Stan(),coordinates) {
	this->garden = garden;

}

House::House(const House& h) : Building(h) {
	garden = h.garden;
}

House& House::operator= (const House& n) {
	(*this).Building::operator=(n);
	garden = n.garden;
	return *this;
}

ostream& operator<<(ostream& ekran, const House& obj) {
	ekran << obj.type_of_building<<";"<< obj.prize
		<< ";" << obj.area
		<< ";" << obj.city
		<< ";" << obj.street
		<< ";" << obj.garden 
		<<";"<<obj.coordinates<< endl;
	return ekran;
}

istream& operator>> (istream& in, House& c)
{
	cout << "Podaj typ budynku: ";
	in >> c.type_of_building;
	cout << endl;
	cout << "Podaj cene: ";
	in >> c.prize;
	cout << "Podaj miejscowosc lokalizacji budynku: ";
	in >> c.city;
	cout << endl;
	cout << "Podaj powierzchnie: ";
	in >> c.area;
	cout << endl;
	cout << "Podaj ulice:";
	in >> c.street;
	cout << endl;
	cout << "Czy dom jest z ogrodem?(1-tak, 0-nie) ";
	in >> c.garden;
	cout << "Podaj wspolrzedne: ";
	in >> c.coordinates;

	return in;
}


House House::setBuilding(House & obj)
{
	cin.ignore();
	cout << "Podaj dane dotyczace domu" << endl;
	cout << "Miejscowosc: ";
	getline(cin, obj.city);
	cout << "Ulica: ";
	getline(cin, obj.street);
	cout << "Typ domu: ";
	getline(cin, obj.type_of_building);
	cout << "Cena: ";
	cin>>obj.prize;
	cout << "Powierzchnia: ";
	cin>>obj.area;
	cout << "Ogrod(1-tak 0-nie): ";
	cin >> obj.garden;
	cout << "Podaj Wspolrzedne: " << endl;
	cin >> obj.coordinates;

	return obj;

}


void House::showBuilding() {
	cout << "Typ domu: " << type_of_building << ", " << "cena: " << prize << ", " << "powierzchnia: " << area << ", " << "miasto: " << city << ", " << "ulica: " << street << ", " << "ogrod: " << garden <<", "<<"wspolrzedne: "<<coordinates<< endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}


bool House::get_garden() {
	return garden;
}