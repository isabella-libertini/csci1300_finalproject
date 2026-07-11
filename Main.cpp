#include <iostream> 
#include <vector>
#include "Character.h"
#include "Townie.h"
#include "Player.h"
using namespace std;

int main() {
    Player player("Resident");

    vector<Townie> townies;
    townies.push_back(Townie("Luke", "Diner", "Coffee"));
    townies.push_back(Townie("Lorelai", "Inn", "Flowers"));
    townies.push_back(Townie("Ms. Patti", "Town Square", "Gossip")); //come back to

    int choice = 0;
    while (choice != 4) {
        cout << endl;
        cout << "Day: " << player.getDay() << " Energy: " << player.getEnergy() << " Money: " << player.getMoney() << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. "
    }
}