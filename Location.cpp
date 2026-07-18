#include "Location.h"

Location::Location() {
    name = "";

};

Location::Location(string n) {
    name = n;

};

string Location::getName() {
    return name;
};