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
//sh townies have their own greeting
void Townie::talk() {
    cout << getName() << " says: We still need a few more things for Founder's Day. By the way, I love " << favoriteGift << "." << endl;
};

