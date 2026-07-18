#ifndef BUNDLE_H
#define BUNDLE_H

#include <string>
#include <vector>
using namespace std;

class Bundle {
    private: 
    vector <string> requiredCategories;
    vector<string>donatedCategories;

    public: 
    Bundle();
    bool needsCategory(string category);
    void donateCategory(string category);
    int getProgress();
    int getTotalNeeded();
    bool isComplete();
    void displayBundle();
};

#endif
