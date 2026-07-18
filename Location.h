#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

class Location {
    private: 
    string name;

    public:
    Location();
    Location(string n);
    string getName();
};

#endif