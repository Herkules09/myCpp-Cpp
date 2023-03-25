#ifndef BUILDING
#define BUILDING
#include "Header.h"
#include "Stan.h"
#include "Coordinates.h"
class Building
{
protected:
	string prize;
	int area;
	string city;
	string street;
	string type_of_building;
	Stan* stan;
	Coordinates coordinates;

public:
	//friend std::istream& operator>>(std::istream& is, Apartment& apartament);
	Building();
	Building(string _prize, int _area, string _city, string _street, string type_of_building, Stan* _stan, Coordinates coordinates);
	Building(const Building&);
	Building& operator=(const Building& b);

	virtual void showBuilding() = 0;

	string get_prize();
	int get_area();
	string get_city();
	string get_street();
	string get_type_of_building();
	Stan get_stan();
	Coordinates get_coordinates();
	void set_prize(string prize);
	void set_area(int area);
	void set_city(string city);
	void set_type_of_building(string type_of_building);
	void set_street(string street);
};



#endif