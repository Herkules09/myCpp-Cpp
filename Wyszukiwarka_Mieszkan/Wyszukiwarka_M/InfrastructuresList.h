#ifndef INFRASTRUCTURESLIST
#define INFRASTRUCTURESLIST
#include "Header.h"
#include"Coordinates.h"
#include"Infrastructure.h"
#include"Building.h"
#include"Hospital.h"
#include"InfListElement.h"



class InfrastructuresList:public Infrastructure
{
public:
	InfrastructuresList();
	~InfrastructuresList();
	
	
	void add(Infrastructure i);
	void find_Infrastructure(InfrastructuresList infL,Coordinates c);
	void clear();
	//int compiude_distanse(InfListElement* head, Building *b);
	friend ostream& operator<<(ostream& ostr, const InfrastructuresList& rhs);
	Infrastructure& operator[](int)const;
	int size();
private:
	InfListElement* Head;
};

#endif