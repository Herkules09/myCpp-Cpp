#ifndef HOSPITALSLISTELEMENT
#define HOSPITALSLISTELEMENT
#include "Header.h"
#include"Hospital.h"
class HospitalsListElement
{
 public:
	
	Hospital H;
	HospitalsListElement* Next;
	HospitalsListElement* Previous;

	HospitalsListElement(Hospital h, HospitalsListElement* previous=nullptr, HospitalsListElement* next=nullptr);
	
};

#endif