#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
    private: 
    string name;
    string type;
    int value;

    public: 
    Item();
    Item(string n, string t, int v);
    string getName();
    string getType();
    int getValue();
};

#endif