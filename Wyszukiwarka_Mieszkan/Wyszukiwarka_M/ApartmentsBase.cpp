#include "ApartmentsBase.h"

vector<Apartment>ApartmentsBase:: getApartments() {
	fileReader f;
	vector<vector<string>>apartmentsData=f.readFile("apartments.txt");
	vector<Apartment> apartments;
	
	Stan *s=new Stan();
	for (vector<string> ap : apartmentsData) {
		Coordinates co(stoi(ap[6]), stoi(ap[7]));
		Apartment a(stoi(ap[5]),ap[1], stoi(ap[2]), ap[3],ap[4],ap[0],co);
		
		apartments.push_back(a);
	}
	return apartments;
}

vector<Apartment>ApartmentsBase::getApartments(Filters f) {
	vector<Apartment>apa=getApartments();
	vector<Apartment>good;
	HospitalsBase hb;
	vector<Hospital>hospital=hb.getHospitals();
	for (Apartment ap : apa) {
		if (f.get_min_price() != "") {
			int minP = stoi(f.get_min_price());
			int P = stoi(ap.get_prize());
			if (P < minP) {
				continue;
			}

		}
		if (f.get_max_price() != "") {
			int maxP = stoi(f.get_max_price());
			int P = stoi(ap.get_prize());
			if (P > maxP) {
				continue;
			}
			
		}
		if (f.get_max_area() != "") {

			if (ap.get_area() > stoi(f.get_max_area())) {
				continue;
			}
		}
		if (f.get_min_area() != "") {

			if (ap.get_area() < stoi(f.get_min_area())) {
				continue;
			}
		}
		if (f.get_Fcity() != "" && ap.get_city() != f.get_Fcity()) {
			continue;
		}
	
		if (f.get_Ftype_of_building() != "" && ap.get_type_of_building() != f.get_Ftype_of_building()) {
			continue;
		}
		if (f.get_Ffloor() != "") {

			if (ap.get_floor() < stoi(f.get_Ffloor())) {
				continue;
			}
		}
		good.push_back(ap);

	}
	return good;
}

void ApartmentsBase::addApartment(Apartment ap) {


	ofstream file;
	file.open("C:\\Users\\michk\\source\\repos\\Losowanie\\Losowanie\\apartments.txt",ios::out | ios::app);
	if (!file.is_open()) {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		exit(0);
	}
	else {
		
		file << ap;
		
       file.close();


	}
}