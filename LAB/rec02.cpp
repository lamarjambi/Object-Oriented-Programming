// CS 2124 - REC02
// Author: Lamar Jambi - lmj8416
// This program aims to apply the advanced basics of c++

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct HydroCarbon {
    int carbon;
    int hydrogen;
    vector<string> names;
};


// prototypes
void openFile(ifstream& file);
size_t findIndex(const vector<HydroCarbon>& hydroCarbVec, int cNum, int hNum);
void insertInfo(vector<HydroCarbon>& hydroCarbVec, const string& name, int cNum, int hNum);
void fillVector(vector<HydroCarbon>& hydrocarbVec, ifstream& file);
void displayVector(const vector<HydroCarbon>& hydroCarbVec);
void sortVector(vector<HydroCarbon>& hydroCarbVec);
void printMolecule(const HydroCarbon& hydroCarb);


int main() {
    ifstream file;
    vector<HydroCarbon> hydrocarbs;

    openFile(file);
    fillVector(hydrocarbs, file);
    cout << endl;

    file.close();

    cout << "Unsorted: " << endl;
    displayVector(hydrocarbs);

    sortVector(hydrocarbs);
    cout << endl;

    cout << "Sorted: " << endl;
    displayVector(hydrocarbs);
    return 0;
}

void openFile(ifstream& file) {
    /* 
    :param: ifstream var from main 
    :return: none
    :desc: asks user for filename and keep asking until open
    */
    string filename;

    do {
        cout << "Enter filename: ";
        cin >> filename;

        file.open(filename);

        if (!file) {
            cout << "Error opening file." << endl;
        }
    } while (!file); 
}

size_t findIndex(const vector<HydroCarbon>& hydroCarbVec, int cNum, int hNum) {
    for (size_t i = 0; i < hydroCarbVec.size(); ++i) {
        if (hydroCarbVec[i].carbon== cNum && hydroCarbVec[i].hydrogen == hNum) {
            return i;
        }
    }
    return hydroCarbVec.size();
}

void insertInfo(vector<HydroCarbon>& hydroCarbVec, const string& name, int cNum, int hNum) { 
    /*
    :return: none
    :param: vector of HydroCarbon types from fillVector()
    :desc: compare formulas and add
    */
   
   size_t ind = findIndex(hydroCarbVec, cNum, hNum);

   if (ind == hydroCarbVec.size()) {
        HydroCarbon newObj {cNum, hNum, {name}};
        hydroCarbVec.push_back(newObj);
    } else { // if exists (two names with the same formula), add to names vector
        hydroCarbVec[ind].names.push_back(name);
    }
}

void fillVector(vector<HydroCarbon>& hydrocarbVec, ifstream& file) {
    /*
    :return: none
    :param: vector of HydroCarbon types + file
    :desc: seperate c and h ints + names
    */
    string hydroCarbName;
    int cNum;
    int hNum;
    char temp;
    
    while(file >> hydroCarbName >> temp >> cNum >> temp >> hNum) {
        insertInfo(hydrocarbVec, hydroCarbName, cNum, hNum);
    }
}

void displayVector(const vector<HydroCarbon>& hydroCarbVec) {
    /*
    :return: none
    :param: vecror of HydroCarbon types
    :desc: print out the hydroCarbVec vector. Formula first then name(s)
    */
    for (size_t i = 0; i < hydroCarbVec.size(); ++i) {
        printMolecule(hydroCarbVec[i]);
    } 
}

void sortVector(vector<HydroCarbon>& hydroCarbVec) {
    /*
    :return: none
    :param: vector of Hydrocarbon
    :desc: use insertion sorting to swap  
    */
   for (size_t i = 1; i < hydroCarbVec.size(); i++) {
        for (size_t j = i; j > 0; j--) {
            if (hydroCarbVec[j].carbon < hydroCarbVec[j - 1].carbon 
            || hydroCarbVec[j].carbon == hydroCarbVec[j - 1].carbon && 
            hydroCarbVec[j].hydrogen < hydroCarbVec[j - 1].hydrogen ) {
                swap(hydroCarbVec[j], hydroCarbVec[j - 1]);
            } 
            else {
                break;
            }
        }
   }
}

void printMolecule(const HydroCarbon& hydroCarb) {
    /*
    :return: none
    :param: hydrocarbs object
    :desc: print out individual molecules
    */
    cout << "C" << hydroCarb.carbon << "H" << hydroCarb.hydrogen << " ";
    for (size_t i = 0; i < hydroCarb.names.size(); ++i) {
        cout << " " << hydroCarb.names[i];
    }
    cout << endl;
}
