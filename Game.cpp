#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;

//should read townie roster from townies.txt
//names, location, then favorite gift!
void Game::loadTowniesFromFile(string fileName) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()){
        cout << "Could not open " << fileName << ". Using default townies instead." << endl;
        townies.push_back(Townie("Luke", "Luke's Diner", "Food"));
        townies.push_back(Townie("Lorelai", "Independence Inn", "Coffee"));
        townies.push_back(Townie("Ms. Patti", "Town Square", "Gossip"));
        townies.push_back(Townie("Mr. Waterhouse", "Starbucks Coffee Co.", "Money"));
        return;

    };
    
    string n, loc, gift;
    while (getline(inputFile, n)) {
        getline(inputFile, loc);
        getline(inputFile, gift);
        townies.push_back(Townie(n, loc, gift));

    }

    inputFile.close();

};

void Game::setUpGame(){
    locations.push_back(Location("Luke's Diner"));
    locations.push_back(Location("Independence Inn"));
    locations.push_back(Location("Town Square"));
    locations.push_back(Location("Doose's Market"));
    locations.push_back(Location("Starbucks Coffee Co."));

    loadTowniesFromFile("Townies.txt");

    maxDays = 7;
};

Game::Game() {
    cout << "==================================================" << endl;
    cout << "            THE FINAL BUNDLE: STARS HOLLOW            " << endl;
    cout << "==================================================" << endl;
    cout << endl;
    cout << "What is your name? ";
    string playerName;
    getline(cin, playerName);

    if (playerName == ""){
        playerName = "Resident";
    };

    setUpGame();
    player = Player(playerName, "Luke's Diner");
};

//main game loop, should keep going until days run out || bundle is done

void Game::run(){
    while (player.getDay() <= maxDays && !bundle.isComplete()){
        displayDashboard();
        displayMap();
        showMainMenu();

        if (player.getActionsLeft() == 0) {
            cout << endl << "You are out of actions for today." << endl;
            player.nextDay();
        }
    }
    displayEnding();

}

void Game::displayDashboard() {
    cout << endl;
    cout << "==================================================" << endl;
    cout << "Day: " << player.getDay() << " /7" << endl;
    cout << "Energy: " << player.getEnergy() << endl;
    cout << "Money: " << "$" << player.getMoney() << endl;
    cout << "Corporate Influence: " << player.getCorporateInfluence() << endl;
    cout << "Location: " << player.getCurrentLocation() << endl;
    cout << "Actions Left Today: " << player.getActionsLeft() << endl;
    cout << endl;
    bundle.displayBundle();
    cout << endl;
    player.displayInventory();
};

void Game::displayMap() {
    cout << endl << "Map: " << endl;
    int size = locations.size();

    for (int i = 0; i < size; i++) {
        cout << "- " << locations[i].getName();
        if (locations[i].getName() == player.getCurrentLocation()){
            cout << " (you are here!)";
        };
        
    }
    cout << endl;
}

void Game::showMainMenu(){
    string loc = player.getCurrentLocation();
    int optionCount = 2;

    cout << endl << "What would you like to do?" << endl;
    cout << "1. Move to another location" << endl;
    cout << "2. Talk to someone" << endl;

    if (loc == "Luke's Diner"){
        cout << "3. Work a shift (earn $15, costs 3 energy)" << endl;
        cout << "4. Buy a coffee ($10, restores 4 energy)" << endl;
        optionCount = 4;
    } else if (loc == "Doose's Market"){
        cout << "3. Buy Blueberry Pie - $20 (Baked Good)" << endl;
        cout << "4. Buy String Lights - $15 (Decoration)" << endl;
        optionCount = 4;
    } else if (loc == "Town Square") {
        cout << "3. Donate an item to the bundle" << endl;
        optionCount = 3;
    } else if (loc == "Starbucks Coffee Co.") {
        cout << "3. Buy a bundle shortcut from Mr. Waterhouse" << endl;
        optionCount = 3;
    }

    cout << (optionCount + 1) << ". End the day" << endl;
    cout << "Choose an option: ";

    int choice; 
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        moveMenu();
    } else if (choice == 2) {
        talkMenu();
    } else if (loc == "Luke's Diner" && choice == 3){
        if (player.spendEnergy(3)){
            player.addMoney(15);
            cout << "You worked a shift and earned $15." << endl;
        } else {
            cout << "You are too tired to work right now." << endl;
        };
        player.useAction();
    } else if (loc == "Luke's Diner" && choice == 4){
        if (player.spendMoney(10)) {
            player.addEnergy(4);
            cout << "You drink a coffee and feel recharged!" << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
        player.useAction();
    } else if (loc == "Doose's Market" && choice == 3) {
        if (player.spendMoney(20)){
            player.addItem(Item("Blueberry Pie", "Baked Good", 20));
            cout << "You bought a Blueberry Pie." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
        player.useAction();
    } else if (loc == "Doose's Market" && choice == 4){
        if (player.spendMoney(15)){
            player.addItem(Item("String Lights", "Decoration", 15));
            cout << "You bought string Lights." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
        player.useAction();
    } else if (loc == "Town Square" && choice == 3){
        donateMenu();
        player.useAction();
    } else if (loc == "Starbs Coffee Co." && choice == 3){
        corporateMenu();
        player.useAction();
    } else if (choice == optionCount + 1) {
        cout << "You decide to call it a day." << endl;
        player.nextDay();
    } else {
        cout << "That is not a valid option." << endl;
    }

}

void Game::moveMenu() {
    cout << endl << "Where would you like to go?" << endl;
    int size = locations.size();

    for (int i = 0; i < size; i++){
        cout << i + 1 << ". " << locations[i].getName() << endl;
    };
    cout << "Choose a location: ";

    int choice;
    cin >> choice;
    cout << endl;
    cin.ignore();

    if (choice < 1 || choice > size){
        cout << "That is not a valid location." << endl;
        return;
    }

    if (player.spendEnergy(2)){
        player.moveTo(locations[choice - 1].getName());
        cout << "You travel to " << player.getCurrentLocation() << "." << endl;
        player.useAction();
    } else {
        cout << "You are too tired to travel right now." << endl;
    };
};

void Game::talkMenu() {
    string loc = player.getCurrentLocation();
    vector<int> nearbyIndexes;
    int size = townies.size();

    for (int i = 0; i < size; i++){
        if (townies[i].getLocation() == loc){
            nearbyIndexes.push_back(i);
        }
    }

    int nearbySize = nearbyIndexes.size();
    if(nearbySize == 0){
        cout << endl << "There is nobody here to talk to." << endl;
        return;
    }

    cout << endl << "Who would you like ot talk to?" << endl;
    for (int i = 0; i < nearbySize; i ++){
        cout << i + 1 << ". " << townies[nearbyIndexes[i]].getName() << endl;
    }
    cout << "Choose someone: ";

    int choice;
    cin >> choice;
    cout << endl;

    if (choice < 1 || choice > nearbySize){
        cout << "That is not a valid choice." << endl;
        return;
    }
    
    int index = nearbyIndexes[choice - 1];
    talkToCharacter(index);
    player.useAction();
}

//inheritance gets used
//checks if townie has a reward to give or not

void Game::talkToCharacter(int index){
    cout << endl;
    townies[index].talk();
    townies[index].increaseFriendship(1);

    string name = townies[index].getName();
    int friendship = townies[index].getFriendship();

    if (name == "Luke" && friendship >= 3 && !player.hasItemOfType("Specialty Item")){
        cout << "Luke hands you a bag of Local Coffee Beans (Specialty Item!1) for the festival!" << endl;
        player.addItem(Item("Local Coffee Beans", "Specialty Item", 0));
    } else if (name == "Lorelai" && friendship >= 3 && !player.hasItemOfType("Craft")){
        cout << "Lorelai hands you a Handmade Quilt (Craft!) for the festival!" << endl;
        player.addItem(Item("Handmade Quilt", "Craft", 0));
    } else if (name == "Ms. Patti" && friendship >= 2 && !player.hasItemOfType("Raffle Prize")){
        cout << "Ms. Patti hands you a Gift Basket for the raffle!" << endl;
        player.addItem(Item("Gift Basket", "Raffle Prize", 0));
    }
};

void Game::donateMenu() {
    cout << endl << "You visit the bundle board." << endl;
    bundle.displayBundle();
    cout << endl;
    player.displayInventory();

    int size = player.getInventorySize();
    if (size == 0) {
        cout << "You have nothing to donate." << endl;
        return;
    };

    cout << "Which item number would you like to donate? (0 to cancel): ";
    int choice;
    cin >> choice;
    cin.ignore(); 
    cout << endl;

    if (choice == 0) {
        return;
    }
    if (choice < 1 || choice > size) {
        cout << "That is not a valid item." << endl;
        return;
    }
    string type = player.getItemType(choice - 1);
    if (bundle.needsCategory(type)) {
        cout <<"You donated " << player.getItemName(choice - 1) << " to the Founder's Day Bundle!" << endl;
        bundle.donateCategory(type);
        player.removeItemAt(choice - 1);
    } else {
        cout << "The bundle does not need that kind of item right now." << endl;
    }

};
//joja style trade-off: pay to skip work but costs pts
void Game::corporateMenu(){
    cout << endl << "Mr. Waterhouse says: Why waste time gathering everything yourself? We can help...for a price." << endl;

    vector<string> categories;
    categories.push_back("Baked Good");
    categories.push_back("Craft");
    categories.push_back("Raffle Prize");
    categories.push_back("Decoration");
    categories.push_back("Specialty Item");

    vector<string> missing;
    int catSize = categories.size();
    for (int i = 0; i < catSize; i++){
        if (bundle.needsCategory(categories[i])) {
            missing.push_back(categories[i]);
        }
    };

    int missingSize = missing.size();
    if (missingSize == 0) {
        cout << "The bundle is already complete!" << endl;
        return;
    };

    for (int i = 0; i < missingSize; i++) {
        cout << i + 1 << ". Buy " << missing[i] << " -$40" << endl;
    }
    cout << (missingSize + 1) << ". Leave" << endl;
    cout << "Choose an option: ";

    int choice;
    cin >> choice;
    cin.ignore();
    cout << endl;

    if (choice >= 1 && choice <= missingSize){
        if (player.spendMoney(40)){
            bundle.donateCategory(missing[choice - 1]);
            player.increaseCorporateInfluence(1);
            cout << "You bought a " << missing[choice - 1] << " shortcut. The bundle now has this item!" << endl;
            cout << "Corporate Influence increased." << endl;
        } else {
            cout << "You do not have enough money." << endl;
        }
    } else {
        cout << "You leave Starbucks Coffee Co." << endl;
    }

};
//ending picked on if the bundle gets completed and how much mr.waterhouse was used
void Game::displayEnding() {
    cout << endl << "==================================================" << endl;
    if (bundle.isComplete()){
        cout << "The Founder's Day Bundle is complete!" << endl;
        int influence = player.getCorporateInfluence();
        if (influence == 0) {
            cout << "Ending: Stars Hollow Legend" << endl;
            cout << "The whole town pitched in, and Founder's Day is better than ever." << endl;
        } else if (influence <= 2) {
            cout << "Ending: Quiet Restoration" << endl;
            cout << "Founder's Day goes off well, though you hear a few angry whispers about the Starbucks cups." << endl;
        } else {
            cout << "Ending: Corporate Shortcut" << endl;
            cout << "The festival happens, but Starbucks Coffee Co. has quietly taken over most of the planning." << endl;
        }

    } else {
        cout << "The season has ended." << endl;
        if (bundle.getProgress() > 0) {
            cout << "Ending: Almost There" << endl;
            cout << "You made progress, but ran out of time to finish the bundle." << endl;

        } else { 
            cout << "Ending: Season Over" << endl;
            cout << "Founder's Day comes and goes without much to show for it." << endl;
        }
    }
    cout << "==================================================" << endl;
};