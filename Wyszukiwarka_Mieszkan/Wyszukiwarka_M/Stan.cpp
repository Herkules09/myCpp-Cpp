#include "Stan.h"

Stan::Stan(){};
Stan::Stan(bool _forRenovation, bool _furinshed, string _owner) {
	this->forRenovation = _forRenovation;
	this->furnished = _furinshed;
	this->owner = _owner;
}