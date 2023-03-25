#ifndef SEARCH_H
#define SEARCH_H
#include "Header.h"
#include "Building.h"
#include "Apartment.h"
#include "House.h"
#include"ApartmentsBase.h"
 #include"HousesBase.h"
#include"InfrastructuresList.h"
#include"Advantages.h"



class Search {
	int option;
public:
	void display_search();
	void display_end();
	void search_building();	
	void add_building();
	Search();
	~Search();

};



#endif 
