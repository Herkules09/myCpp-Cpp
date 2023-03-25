#ifndef HOUSE
#define HOUSE
#include "Header.h"
#include "Building.h"


class House :public Building {
private:
	bool garden;
	
public:
	House();
	House(bool garden, string prize, int area, string city, string street, string type_of_building, Stan* stan,Coordinates coordinates);
	House( bool garden ,string prize, int area, string city, string street, string type_of_building, Coordinates coordinates);
	House(const House&);
	House& operator= (const House& n);
	friend ostream& operator<<(ostream& ekran, const House& obj);
	friend istream& operator >> (istream& in, House& c);

	House setBuilding(House  & h);
	void showBuilding();
	bool get_garden();
};

#endif