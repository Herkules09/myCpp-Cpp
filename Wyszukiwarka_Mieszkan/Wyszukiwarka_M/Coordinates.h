#ifndef COORDINATES
#define COORDINATES
#include "Header.h"

class Coordinates
{
private:
	int x, y;

public:
	Coordinates();
	Coordinates(int x, int y);
	int coordinate_distanse(Coordinates a,Coordinates b);
	int add_coordinates();
	Coordinates& operator= (const Coordinates& n);
	bool operator ==(const Coordinates& n);
	friend ostream& operator<<(ostream& ekran, const Coordinates& obj);
	friend istream& operator >> (istream& in, Coordinates& c);
	int  get_x();
	int get_y();
	void set_x(int);
	void set_y(int);
	
};

#endif