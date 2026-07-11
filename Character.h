#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std; 

class Character {
    private: 
    string name;
    string location;
    int friendship;

    public: 
    Character();
    Character(string n, string loc);
    string getName();
    string getLocation();
    int getFriendship();
    void increaseFriendship(int amount);
    void talk();
};

#endif