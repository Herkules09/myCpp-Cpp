#ifndef INFLISTELEMENT
#define INFLISTELEMENT
#include "Header.h"
#include"Infrastructure.h"
class InfListElement
{
public:

	Infrastructure H;
	InfListElement* Next;
	InfListElement* Previous;

	InfListElement(Infrastructure h, InfListElement* previous = nullptr, InfListElement* next = nullptr);

};

#endif