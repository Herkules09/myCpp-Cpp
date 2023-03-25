#ifndef STAN
#define STAN
#include "Header.h"

class Stan
{
private:
	bool forRenovation;
	bool furnished;
	string owner;

public:
	Stan();
	Stan(bool _forRenovation, bool _furinshed, string _owner);
};

#endif