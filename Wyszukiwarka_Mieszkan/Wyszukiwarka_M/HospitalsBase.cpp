#include "HospitalsBase.h"

vector<Hospital>HospitalsBase::getHospitals() {
	fileReader f;
	vector<vector<string>>hospitalsData = f.readFile("hospitals.txt");
	vector<Hospital> hospitals;


	for (vector<string> su :  hospitalsData) {
		Coordinates co(stoi(su[2]), stoi(su[3]));
	    Hospital a(su[0], su[1], co);

		hospitals.push_back(a);
	}
	return hospitals;
}


