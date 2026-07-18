#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
    name = "Resident"; 
    money = 50;
    energy = 10;
    day = 1;
    currentLocation = "";
    actionsLeft = 4;
    corporateInfluence = 0;
};

Player::Player(string n, string startLocation) {
    name = n;
    money = 50;
    energy = 10;
    day = 1;
    currentLocation = startLocation;;
    corporateInfluence = 0;
    actionsLeft = 4;
};

string Player::getName() {
    return name;
}

int Player::getMoney() {
    return money; //troubleshoot
};

void Player::addMoney(int amount) {
    money = money + amount;
}

int Player::getEnergy() {
    return energy;
}

int Player::getDay() {
    return day;
}

void Player::nextDay(){
    day = day + 1; 
    actionsLeft = 4;
    addEnergy(4);
};

string Player::getCurrentLocation(){
    return currentLocation;
};

void Player::moveTo(string locationName) {
    currentLocation = locationName;
};

void Player::addEnergy(int amount) {
    energy = energy + amount;
    if (energy > 10) {
        energy = 10;
    }
}


bool Player::spendEnergy(int amount){
    if (energy < amount){
        return false;
    }
    energy = energy - amount;
    return true;

};

bool Player::spendMoney(int amount) {
    if (money < amount) {
        return false;
    }
    money = money - amount;
    return true;
}

int Player::getActionsLeft(){
    return actionsLeft;
}

void Player::useAction() {
    if (actionsLeft > 0) {
        actionsLeft = actionsLeft -1;
    }
}

int Player::getCorporateInfluence(){
    return corporateInfluence;
}

void Player::increaseCorporateInfluence(int amount){
    corporateInfluence = corporateInfluence + amount;
};

void Player::addItem(Item newItem) {
    inventory.push_back(newItem);
}

bool Player::hasItemOfType(string type) {
    int size = inventory.size();
    
    for (int i = 0; i < size; i++){
        if (inventory[i].getType() == type) {
            return true;
        }
    };
    return false;
};

int Player::getInventorySize(){
    return inventory.size();
}

string Player::getItemName(int index){
    return inventory[index].getType();    
};

string Player::getItemType(int index){
    return inventory[index].getType();
};

void Player::removeItemAt(int index){
    inventory.erase(inventory.begin() + index);
};

void Player::displayInventory(){
    int size = inventory.size();
    
    if (size == 0){
        cout <<"Your inventory is empty." << endl;
        return;
    };
    cout << "Inventory: " << endl;

    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << inventory[i].getName() << " - " << inventory[i].getType() << endl;

    }
};
//office hours: how to resolve issue with name 

