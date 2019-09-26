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
    int R = 6373000;

public:
	Item(double latitudeIn, double longitudeIn, string IDIn, int timeIn):
	latitude(latitudeIn), longitude(longitudeIn), ID(IDIn), time(timeIn) {
	
	}

    void write(ostream & o) const {
        o << "{" << latitude << ", " << longitude << ", \"" << ID << "\", " << time << "}";
    }

    double distanceTo(Item & itemIn) {
        double dlon = convertRad(itemIn.longitude- longitude);
        double dlat = convertRad(itemIn.latitude - latitude);

        double a = pow((sin(dlat/2)), 2) + cos(convertRad(itemIn.latitude)) * cos(convertRad(latitude)) * pow((sin(dlon/2)), 2);
        double c = 2 * atan2( sqrt(a), sqrt(1-a) );
        double distance = R * c;
        return distance;
    }

    double convertRad(double deg) {
        return (deg * M_PI)/180;
    }

};


ostream & operator<<(ostream & o, const Item & itemIn) {
    itemIn.write(o);
    return o;
}

// don't write any code below this line

#endif

