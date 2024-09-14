#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct HydroCarbon {
    /*
    :desc: stores info about hydrocarbons
    */
        vector<string> names;
        int carbon;
        int hydrogen;
    };

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
            cout << "Error opening file.";
        }
    } while (!file);
        
}

void findLocation(vector<string>& vector) {


}

void insertInfo(vector<HydroCarbon>& vector) { 
    /*
    :return: none
    :param: vector of HydroCarbon types from fillVector()
    :desc: assembles the HydroCarbon objects. Formula first then names and enteries
    */
   
   
}

void fillVector(vector<HydroCarbon> hydrocarbVec, ifstream& file) {
    /*
    :return: none
    :param: vector of HydroCarbon types + file
    :desc: can't just push_back() becuase we have not overloaded the struct,
           + this function calls insertInfo
    */
    string line;
    string hydroCarbName = "";
    string formula = " ";

    while(getline(file, line)) { // reading file line by line
        int i = 0;

        // add letters as a name for hydroCarbon 
        while(i < line.length() && line[i] != " ") { // why error?
            hydroCarbName += line[i];
            ++ i;
        }
        ++i; // skip space

        while (i < line.length()) {
            formula += line[i];
            ++i;
        }
    }

}

void displayVector(vector<HydroCarbon>& hydroCarbVec) {
    /*
    :return: none
    :param: vecror of HydroCarbon types
    :desc: print out the hydroCarbVec vector. Formula first then name(s)
    */
    /* for (size_t i = 0; i < hydroCarbVec.size(); ++i) {
        
    } */

}

void sortVector(vector<string>& vector) {
    /*
    :return: none
    :param: vector of Hydrocarbon 
    */

}

void printFormula(vector<string>& vector) {


}

int main() {
    ifstream file;
    vector<HydroCarbon> hydrocarbs;

    openFile(file);
    fillVector(hydrocarbs, file);


    return 0;
}