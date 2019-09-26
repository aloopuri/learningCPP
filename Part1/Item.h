#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

// TODO: your code  goes here

class Item {

private:
	double latitude;
	double longitude;
	string ID;
	int time;

public:
	Item(double latitudeIn, double longitudeIn, string IDIn, int timeIn):
	latitude(latitudeIn), longitude(longitudeIn), ID(IDIn), time(timeIn) {
	
	}
};



// don't write any code below this line

#endif

