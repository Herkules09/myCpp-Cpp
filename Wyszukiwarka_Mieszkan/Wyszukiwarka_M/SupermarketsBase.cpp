#include"SupermarketsBase.h"


vector<Supermarket>SupermarketsBase::getSupermarkets() {
	fileReader f;
	vector<vector<string>>supermarketsData = f.readFile("supermarkets.txt");
	vector<Supermarket> supermarkets;

	
	for (vector<string> su : supermarketsData) {
		Coordinates co(stoi(su[2]), stoi(su[3]));
		Supermarket a(su[0], su[1],  co);

		supermarkets.push_back(a);
	}
	return supermarkets;
}