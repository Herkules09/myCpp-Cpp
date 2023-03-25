#include "Filters.h"

Filters::Filters(){}


Filters& Filters::operator=(const Filters& f) {
	min_price = f.min_price;
	max_price = f.max_price;
	min_area = f.min_area;
	max_area = f.max_area;
	Fcity = f.Fcity;
	Fstreet = f.Fstreet;
	Ftype_of_building = f.Ftype_of_building;
	Fgarden = f.Fgarden;
	Ffloor = f.Ffloor;

	return *this;
}

string Filters::get_min_price() {
	return min_price;
}

string Filters::get_max_price() {
	return max_price;
}

string Filters::get_max_area() {
	return max_area;
}

string Filters::get_min_area() {
	return min_area;
}

string Filters::get_Fcity() {
	return Fcity;
}

string Filters::get_Fstreet() {
	return Fstreet;
}

string Filters::get_Ftype_of_building() {
	return Ftype_of_building;
}
string Filters::get_Ffloor() {
	return Ffloor;
}

string Filters::get_Fgarden() {
	return Fgarden;
}
int Filters::get_Fx() {
	return Fx;
}
int Filters::get_Fy() {
	return Fy;
}

void Filters::set_max_area(string max_area) {
	this->max_area = max_area;
}
void Filters::set_min_area(string min_area) {
	this->min_area = min_area;
}

void Filters::set_min_price(string min_price) {
	this->min_price = min_price;
}

void Filters::set_max_price(string max_price) {
	this->max_price = max_price;
}

void Filters::set_Fcity(string Fcity) {
	this->Fcity = Fcity;
}

void Filters::set_Fstreet(string Fstreet) {
	this->Fstreet = Fstreet;
}

void Filters::set_Ftype_of_building(string Ftype_of_building) {
	this->Ftype_of_building = Ftype_of_building;
}

void Filters::set_Ffloor(string Ffloor) {
	this->Ffloor = Ffloor;
}
void Filters::set_Fgarden(string Fgarden) {
	this->Fgarden = Fgarden;
}

void Filters::set_Fx(int Fx) {
	this->Fx = Fx;
}
void Filters::set_Fy(int Fy) {
	this->Fy = Fy;
}