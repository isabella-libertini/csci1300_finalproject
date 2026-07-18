#include "Item.h"

Item::Item() {
    name = "";
    type = "";
    value = 0;
};

Item::Item(string n, string t, int v) {
    name = n;
    type = t;
    value = v;
};

string Item::getName(){
    return name;
}

string Item::getType() {
    return type;
};

int Item::getValue() {
    return value;
}