#include "HousesBase.h"

bool HousesBase:: to_bool(string str) {
	
	
	bool b;
	stringstream(str) >>boolalpha>>b;
	

	return b;
}


vector<House>HousesBase::getHouses() {
	fileReader f;
	vector<vector<string>>housesData = f.readFile("houses.txt");
	vector<House> houses;
    Stan* d = new Stan();


	for (vector<string> ho : housesData) {
		Coordinates co(stoi(ho[6]), stoi(ho[7]));
		House h(to_bool(ho[5]), ho[1], stoi(ho[2]), ho[3], ho[4], ho[0],co);

		houses.push_back(h);
	}
	return houses;
}

vector<House>HousesBase::getHouses(Filters f) {
	vector<House>hou = getHouses();
	vector<House>good;
	for (House ho : hou) {
	    	if (f.get_min_price() != "") {
			int minP = stoi(f.get_min_price());
			int P = stoi(ho.get_prize());
			if (P < minP) {
				continue;
			}

		}
		if (f.get_max_price() != "") {
			int maxP = stoi(f.get_max_price());
			int P = stoi(ho.get_prize());
			if (P > maxP) {
				continue;
			}
		}
		if (f.get_max_area() != "") {

			if (ho.get_area() > stoi(f.get_max_area())) {
				continue;
			}
		}
		if (f.get_min_area() != "") {

			if (ho.get_area() < stoi(f.get_min_area())) {
				continue;
			}
		}
		if (f.get_Fcity() != "" && ho.get_city() != f.get_Fcity()) {
			continue;
		}
		
		if (f.get_Ftype_of_building() != "" && ho.get_type_of_building() != f.get_Ftype_of_building()) {
			continue;
		}
		if (f.get_Fgarden() != "" && ho.get_garden() != to_bool(f.get_Fgarden())) {
			continue;
		}
			
		good.push_back(ho);

	}
	return good;
}

void HousesBase::addHouse(House ho) {


	ofstream file;
	file.open("C:\\Users\\michk\\source\\repos\\Losowanie\\Losowanie\\houses.txt", ios::out | ios::app);
	if (!file.is_open()) {
		cout << "Nie udalo sie otworzyc pliku" << endl;
		exit(0);
	}
	else {

		file << ho;

		file.close();


	}
}
