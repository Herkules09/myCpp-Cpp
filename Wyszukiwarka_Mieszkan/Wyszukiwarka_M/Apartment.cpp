#include"Header.h"
#include "Apartment.h"

Apartment::Apartment() {}

Apartment::Apartment(int _floor,string prize,int area,string city,string street,string type_of_building,Stan* stan, Coordinates coordinates) :Building(prize, area, city, street, type_of_building, stan, coordinates) {
	this->floor = _floor;

}
Apartment::Apartment(int _floor, string prize, int area, string city, string street, string type_of_building, Coordinates coordinates) : Building(prize, area, city, street, type_of_building,new Stan(),  coordinates) {
	this->floor = _floor;

}

Apartment::Apartment(const Apartment& a) :Building(a) {
	floor = a.floor;
}


Apartment& Apartment::operator= (const Apartment& n) {
	(*this).Building::operator=(n);
	floor = n.floor;

	return *this;
}

ostream& operator<<(ostream& ekran, const Apartment& obj) {
	ekran <<obj.type_of_building << ";" << obj.prize
		<< ";" << obj.area
		<< ";" << obj.city
		<< ";" << obj.street
		<< ";" << obj.floor
		<<";"<<obj.coordinates<<endl; 
	return ekran;
}


istream& operator>> (istream& in,  Apartment& c)
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
	cout << "Podaj numer pietra: ";
	in >> c.floor;
	cout << "Podaj wspolrzedne: "<<endl;
	in >> c.coordinates;

	return in;
}
void Apartment::set_floor(int floor)
{
	this->floor = floor;
}


Apartment Apartment::setBuilding(Apartment & c)
{
	string input;
	cin.ignore();
	cout << "Podaj typ budynku: ";
	getline(cin, input);
	c.set_type_of_building(input);
	//cin.ignore();
	cout << "Podaj cene: ";
	getline(cin, input);
	c.set_prize(input);
	cout << "Podaj miejscowosc lokalizacji budynku: ";
	getline(cin, input);
	c.set_city(input);
	cout << "Podaj powierzchnie: ";
	cin >> input;
	c.set_area(stoi(input));
	cin.ignore();
	cout << "Podaj ulice:";
	getline(cin,input);
	c.set_street(input);
	cout << "Podaj numer pietra: ";
	cin >> input;
	c.set_floor(stoi(input));
	cout << "Podaj wspolrzedne: "<<endl;
	cin>> c.coordinates;
	
	

	return c;
}



void Apartment::showBuilding() {
	cout << "Typ mieszkania: " << type_of_building << ", " << "cena: " << prize << ", " << "powierzchnia: " << area << ", " << "miasto: " << city << ", " << "ulica: " << street << ", " << "pietro: " << floor <<", "<<"wspolrzedne: "<< coordinates<< endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}

int Apartment::get_floor() {
	return floor;
}
