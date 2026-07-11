#include "Townie.h"
#include <iostream>
using namespace std;

Townie::Townie() : Character() {
    favoriteGift = "";
};

Townie::Townie(string n, string loc, string gift) : Character(n, loc) {
    favoriteGift = gift;
};

string Townie::getFavoriteGift() {
    return favoriteGift;
};

void Townie::talk() {
    cout << name << " says: We still need a few more things for the Founder's Day parade." << endl;
};
//come back and fix name issue
