#ifndef ITEM_H
#define ITEM_H

// TODO: copy your Item.h file from assignment 1 over this file

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

    double const distanceTo(Item & itemIn) {
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

    int getTime() const{
        return time;
    }

};


ostream & operator<<(ostream & o, const Item & itemIn) {
    itemIn.write(o);
    return o;
}

#endif

