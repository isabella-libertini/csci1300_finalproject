#include "Bundle.h"
#include <iostream>
using namespace std;

// these are the 5 categories the player needs to fill to finish the game
Bundle::Bundle() {
    requiredCategories.push_back("Baked Good");
    requiredCategories.push_back("Craft");
    requiredCategories.push_back("Raffle Prize");
    requiredCategories.push_back("Decoration");
    requiredCategories.push_back("Specialty Item");
};

bool Bundle::needsCategory(string category) {
    bool isRequired = false;
    int requiredSize = requiredCategories.size();
    
    for (int i = 0; i < requiredSize; i++){
        if (requiredCategories[i] == category) {
            isRequired = true;
        }
    }
    if (!isRequired) {
        return false;
    };

    int donatedSize = donatedCategories.size();

    for (int i = 0; i < donatedSize; i++) {
        if (donatedCategories[i] == category) {
            return false;
        }
    }
    return true;
}

void Bundle::donateCategory(string category) {
    if (needsCategory(category)) {
        donatedCategories.push_back(category);
    }
}

int Bundle::getProgress(){
    return donatedCategories.size();
}

int Bundle::getTotalNeeded() {
    return requiredCategories.size();
}

bool Bundle::isComplete() {
    return donatedCategories.size() == requiredCategories.size();

}

void Bundle::displayBundle() {
    cout << "Founder's Day Bundle Progress: " << getProgress() << " / " << getTotalNeeded() << endl;
    cout << "Still Needed: " << endl;
    int requiredSize = requiredCategories.size();

    for (int i = 0; i < requiredSize; i++) {
        if (needsCategory(requiredCategories[i])){
            cout << "- " << requiredCategories[i] << endl;
        }
    }

};
//come back and fix