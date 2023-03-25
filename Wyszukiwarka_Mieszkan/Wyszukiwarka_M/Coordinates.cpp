#include "Coordinates.h"

Coordinates::Coordinates(){}

Coordinates::Coordinates(int x, int y) {
	this->x = x;
	this->y = y;
}

Coordinates& Coordinates::operator= (const Coordinates& n) {
	x = n.x;
	y = n.y;

	return *this;
}

bool Coordinates::operator==(const Coordinates& n)
{
	if ((this->x == n.x) && (this->y == n.y))
		return true;
	else
		return false;
}

ostream& operator<<(ostream& ekran, const Coordinates& obj) {
	ekran << obj.x << "; " << obj.y;
	
	return ekran;
}

istream& operator>> (istream& in, Coordinates& c) {
	cout << "Podaj wspolrzedna x: ";
	in >> c.x;
	cout << "Podaj wspolrzedna y: ";
	in >> c.y;
	
	return in;
}

int Coordinates::get_x() {
	return x;
}

int Coordinates::get_y() {
	return y;
}
void Coordinates::set_x(int x) {
	this->x = x;
}

void Coordinates::set_y(int y) {
	this->y = y;
}

 int Coordinates::coordinate_distanse(Coordinates a, Coordinates b) {
	int x = abs(a.get_x() - b.get_x());
	int y = abs(a.get_y() - b.get_y());

	return x + y;
}

