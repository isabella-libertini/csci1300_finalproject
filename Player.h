#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Player {
    private: 
    string name;
    string currentLocation;
    int money;
    int energy;
    int day;
    int actionsLeft;
    int corporateInfluence;
    vector<Item> inventory;

    public:
    Player();
    Player(string n, string startLocation);

    string getName();

    string getCurrentLocation();
    void moveTo(string locationName);

    int getMoney();
    void addMoney(int amount);
    bool spendMoney(int amount);

    int getEnergy();
    void addEnergy(int amount);
    bool spendEnergy(int amount);

    int getDay();
    void nextDay();

    int getActionsLeft();
    void useAction();

    int getCorporateInfluence();
    void increaseCorporateInfluence(int amount);

    void addItem(Item newItem);
    bool hasItemOfType(string type);
    int getInventorySize();
    string getItemType(int index);
    string getItemName(int index);
    void removeItemAt(int index);
    void displayInventory();
    

};

#endif
