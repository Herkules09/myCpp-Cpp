#ifndef HOSPITAL
#define HOSPITAL
#include "Header.h"
#include"Infrastructure.h"
class Hospital :public Infrastructure
{
public:
	
	Hospital();
	Hospital(string name, string city, Coordinates c);
	
};

#endif