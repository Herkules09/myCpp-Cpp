#include "HospitalsList.h"

HospitalsList::HospitalsList():Head(nullptr) {

}

HospitalsList::~HospitalsList() {
	clear();
}

void HospitalsList::add_Hospital(Hospital hospital) {
	if (Head == nullptr) {
		//Empty case
		Head = new HospitalsListElement(hospital);
	}
	else {
		//Non-empty case
		HospitalsListElement* Current = Head;
		while (Current->Next != nullptr) {
			Current = Current->Next;
		}
		HospitalsListElement* Temp = new HospitalsListElement(hospital, Current);
	}
}

ostream& operator<<(ostream& ostr, const HospitalsList& rhs)
{
	HospitalsListElement* Current = rhs.Head;
	while (Current!=nullptr) {
		cout << Current->H << " ";
		Current = Current->Next;
	}
	
	return ostr;

}

void HospitalsList::clear() {
	HospitalsListElement* Current = Head;
	while (Current != nullptr) {
		HospitalsListElement*Temp = Current->Next;
		delete Current;
		Current = Temp;
	}
}


void HospitalsList::find_Hospital(Coordinates value) {
	/*HospitalsListElement* Current = Head;
	int found;
	if (Head == nullptr) {
		cout << "LISTA JEST PUSTA";
		return;
	}
	while (Current) {
		if()
	}*/
	
	
}

void HospitalsList::load_Hospitals() {

}