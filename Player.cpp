#include "Player.h"

Player::Player() {
    name = "Farmer";
    money = 50;
    energy = 10;
    day = 1;
};

Player::Player(string n) {
    name = n;
    money = 50;
    energy = 10;
    day = 1;
};

string Player::getName() {
    return name;
}

int Player::getMoney() {
    return name;
}

int Player::getMoney() {
    return money;

};

void Player::addMoney(int amount) {
    money = money + amount;
}

int Player::getEnergy() {
    return energy;
}

bool Player::spendEnergy(int amount) {
    if (energy < amount) {
        return false;
    }
    energy = energy - amount;
    return true;
};

int Player::getDay() {
    return day;
}

void Player::nextDay(){
    day = day + 1; 
};

//office hours: how to resolve issue with name 

