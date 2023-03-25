#ifndef APARTMENTSBASE
#define APARTMENTSBASE
#include "Header.h"
#include"Apartment.h"
#include"fileReader.h"
#include "Filters.h"
#include"HospitalsBase.h"
class ApartmentsBase
{
public:
	
	vector<Apartment> getApartments();
	vector<Apartment> getApartments(Filters f);
	void addApartment(Apartment);

	
};

#endif