#ifndef HOSPITALSLIST
#define HOSPITALSLIST
#include "Header.h"
#include"HospitalsListElement.h"
#include"Coordinates.h"
#include"Infrastructure.h"
#include"Building.h"
class HospitalsList:public Infrastructure
{
public:
	HospitalsList();
	~HospitalsList();
	void load_Hospitals();
	void add_Hospital(Hospital h);
	void find_Hospital(Coordinates c);
	void clear();
	Coordinates compiude_distanse(HospitalsListElement *head,Building b);
	friend ostream& operator<<(ostream& ostr, const HospitalsList& rhs);
private:
	HospitalsListElement *Head;
};

#endif