#ifndef TOWNIE_H
#define TOWNIE_H

#include <string>
#include "Character.h"
using namespace std;

class Townie : public Character {
    private: 
    string favoriteGift;

    public:
    Townie();
    Townie(string n , string loc, string gift);
    string getFavoriteGift();
    void talk();
};

#endif