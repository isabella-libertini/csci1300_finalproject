#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
    private: 
    string name;
    int money;
    int energy;
    int day;

    public:
    Player();
    Player(string n);
    string getName();
    int getMoney();
    
    void addMoney(int amount);
    int getEnergy();
    bool spendEnergy(int amount);
    int getDay();
    void nextDay();
};

#endif
