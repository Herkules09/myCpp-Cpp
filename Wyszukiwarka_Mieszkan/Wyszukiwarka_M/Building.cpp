#include"Building.h"
#include"Header.h"

Building::Building() {}


Building::Building(string _prize, int _area, string _city,  string _street, string _type_of_building,Stan * _stan, Coordinates coordinates) {
	this->prize = _prize;
	this->area = _area;
	this->city = _city;
	this->street = _street;
	this->type_of_building = _type_of_building;
	this->stan = _stan;
	this->coordinates = coordinates;
}

Building::Building(const Building & b) {
	prize = b.prize;
	area = b.area;
	city = b.city;
	street = b.street;
	type_of_building = b.type_of_building;
	stan = b.stan;
	coordinates = b.coordinates;
}
Building& Building::operator=(const Building& b) {
	prize = b.prize;
	area = b.area;
	city = b.city;
	street = b.street;
	type_of_building = b.type_of_building; 
	stan = b.stan;
	coordinates = b.coordinates;

	return *this;
}



string Building::get_prize() {
	return prize;
}

int Building::get_area() {
	return area;
}

string Building::get_city() {
	return city;
}
string Building::get_street() {
	return street;
}

string Building::get_type_of_building() {
	return type_of_building;
}

Stan Building::get_stan() {
	return *stan;
}

Coordinates Building::get_coordinates() {
	return coordinates;
}

void Building::set_prize(string prize)
{
	this->prize = prize;
}

void Building::set_area(int area)
{
	this->area = area;
}

void Building::set_city(string city)
{
	this->city = city;
}

void Building::set_type_of_building(string type_of_building)
{
	this->type_of_building = type_of_building;
}

void Building::set_street(string street)
{
	this->street = street;
}


