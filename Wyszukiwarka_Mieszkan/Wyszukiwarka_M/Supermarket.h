#ifndef SUPERMARKET
#define SUPERMARKET
#include "Header.h"
#include"Infrastructure.h"
class Supermarket :public Infrastructure{
public:
	Supermarket(string name, string city, Coordinates c);
};

#endif