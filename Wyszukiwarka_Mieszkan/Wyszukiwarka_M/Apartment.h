#ifndef APARTMENT
#define APARTMENT
#include "Header.h"
#include "Building.h"



class Apartment :public Building {
private:
	int floor;

public:
	Apartment();
	Apartment(int _floor, string prize, int area, string city, string street, string type_of_building, Stan* stan, Coordinates coordinates);
	Apartment(int _floor, string prize, int area, string city, string street, string type_of_building, Coordinates coordinates);
	Apartment(const Apartment&);
	Apartment& operator= (const Apartment& n);

	friend ostream& operator<<(ostream& ekran, const Apartment& obj);
	friend istream& operator >> (istream& in,  Apartment& c);


	int get_floor();
	void set_floor(int floor);
	Apartment setBuilding(Apartment & obj);
	void showBuilding();
	
};

#endif