#ifndef HOUSESBASE
#define HOUSESBASE
#include "Header.h"
#include"House.h"
#include"fileReader.h"
#include "Filters.h"

class HousesBase
{
public:
	vector<House> getHouses();
	vector<House> getHouses(Filters f);
	void addHouse(House);
	bool to_bool(string str);

};

#endif