#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <cmath>

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

    void write(ostream & o) const {
        o << "{" << latitude << ", " << longitude << ", \"" << ID << "\", " << time << "}";
    }

    double distanceTo(Item itemIn) {
        
    }

};


ostream & operator<<(ostream & o, const Item & itemIn) {
    itemIn.write(o);
    return o;
}

// don't write any code below this line

#endif

