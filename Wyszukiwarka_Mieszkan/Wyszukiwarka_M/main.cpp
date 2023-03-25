
#include "fileReader.h"
#include "Header.h"
#include "House.h"
#include"ApartmentsBase.h"
#include"Filters.h"
#include"Apartment.h"
#include"Search.h"
#include"InfrastructuresList.h"
#include"HospitalsBase.h"
#include"Advantages.h"





int main()
{
	
	
	Filters f;
	
	HospitalsBase ho;
	vector<Hospital>hospitalsV=ho.getHospitals();
	ApartmentsBase ap;
	vector<Apartment> gg = ap.getApartments();
	
	
	Coordinates e(30, 12);
	Coordinates d(12, 12);
	
	Hospital b("kat", "warszawa", e);
	Hospital c("kat", "warszawa", d);

	InfrastructuresList hospitalsList;
	hospitalsList.add(b);
	hospitalsList.add(c);
	
	

	Search se;
	se.display_search();


}


 