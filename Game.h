#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Player.h"
#include "Townie.h"
#include "Location.h"
#include "Bundle.h"
using namespace std;

class Game {
    private:
    Player player;
    vector<Townie> townies;
    vector<Location> locations;
    Bundle bundle;
    int maxDays;

    void loadTowniesFromFile(string fileName);
    void setUpGame();
    void displayDashboard();
    void displayMap();
    void showMainMenu();
    void moveMenu();
    void talkMenu();
    void talkToCharacter(int index);
    void donateMenu();
    void corporateMenu();
    void displayEnding();

    public: 
    Game();
    void run();

};

#endif