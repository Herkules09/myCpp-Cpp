#ifndef FILTERS
#define FILTERS
#include "Header.h"
class Filters
{
private:
	string min_price;
	string max_price;
	string min_area;
	string max_area;
	string Fcity;
	string Fstreet;
	string Ftype_of_building;
	string Ffloor;
	string Fgarden;
	int Fx;
	int Fy;

public:
	Filters& operator=(const Filters& f);
	string get_min_price();
	string get_max_price();
	string get_min_area();
	string get_max_area();
	string get_Fcity();
	string get_Fstreet();
	string get_Ftype_of_building();
	int get_Fx();
	int get_Fy();	
	string get_Ffloor();
	string get_Fgarden();
	void set_min_price(string);
	void set_max_price(string);
	void set_min_area(string);
	void set_max_area(string);
	void set_Fcity(string);
	void set_Fstreet(string);
	void set_Ftype_of_building(string);
	void set_Ffloor(string);
	void set_Fgarden(string);
	void set_Fx(int);
	void set_Fy(int);
	Filters();
	
};

#endif