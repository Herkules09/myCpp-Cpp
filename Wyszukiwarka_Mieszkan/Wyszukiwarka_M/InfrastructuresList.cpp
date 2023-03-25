#include "InfrastructuresList.h"

InfrastructuresList::InfrastructuresList() :Head(nullptr) {

}

InfrastructuresList::~InfrastructuresList() {
	clear();
}



void InfrastructuresList::add(Infrastructure i) {
	
	if (Head == nullptr) {
		//Empty case
		Head = new InfListElement(i);
	}
	else {
		//Non-empty case
		InfListElement* Current = Head;
		while (Current->Next != nullptr) {
			Current = Current->Next;
		}
		InfListElement* Temp = new InfListElement(i, Current);
		Current->Next = Temp;
	}
}

void InfrastructuresList::find_Infrastructure(InfrastructuresList infL,Coordinates c)
{
	for (size_t i = 0; i < infL.size(); i++) {
		if (c == infL[i].get_Coordinates()) {
			infL[i].show_Infrastructure();
		}
	}
}

ostream& operator<<(ostream& ostr, const InfrastructuresList& rhs)
{
	InfListElement* Current = rhs.Head;
	while (Current != nullptr) {
		cout << Current->H << " ";
		Current = Current->Next;
	}

	return ostr;

}

void InfrastructuresList::clear() {
	InfListElement* Current = Head;
	while (Current != nullptr) {
		InfListElement* Temp = Current->Next;
		delete Current;
		Current = Temp;
	}
}

Infrastructure& InfrastructuresList::operator[](int r) const
{
	InfListElement* search = Head;
	for (int i = 0; i < r; i++) {
		search = search->Next;
	}
	return search->H;
}

int InfrastructuresList::size() {
	int size = 0;
	InfListElement* temp = Head;
	while (temp) {
		size++;
		temp = temp->Next;
	}
	return size;
}




