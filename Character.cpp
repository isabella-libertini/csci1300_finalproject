#include "Character.h"
#include <iostream>
using namespace std;

Character::Character() {
    name = "";
    location = "";
    friendship = 0;
};

Character::Character(string n, string loc) {
    name = n; 
    location = loc;
    friendship = 0;
};

string Character::getName() const {
    return name;
}

string Character::getLocation() {
    return location;
};

int Character::getFriendship() {
    return friendship;
}

void Character::increaseFriendship(int amount) {
    friendship = friendship + amount;

};

void Character::talk() {
    
    cout << name << " says: Hello there!" << endl;
};
