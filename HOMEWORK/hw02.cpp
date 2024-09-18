// CS 2124 - HW2
// Author: Lamar Jambi - lmj8416
// This program is a medival game :P
// DONT FORGET PROTOTYPES + put comments outside of functions
// General steps: make struct of warriors and check commands

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Warrior {
    string name;
    int strength;
    string status = "Alive";
};

// prototypes
size_t findIndex(const vector<Warrior>& warriors, string& name);
void warriorHandling(string& name, int& strength, string& status , vector<Warrior>& warriors);
void displayWarrior(const Warrior warrior);
void statusHandling(const vector<Warrior>& warriors);
void battleHandling(Warrior& warrior1, Warrior& warrior2, const vector<Warrior>& warriors);

int main() {
    /*
    :desc: read command and pass the line to a function that handles it
    */
    ifstream file;
    vector<Warrior> warriors;

    file.open("warriors.txt");

    if (!file) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    string command;
    string name1, name2;
    int strength;
    string status;

    while (file >> command) {
        if (command == "Warrior") {
            file >> name1 >> strength >> status;
            warriorHandling(name1, strength, status, warriors);

        } else if (command == "Battle") {
            file >> name1 >> name2;
            
            size_t ind1 = findIndex(warriors, name1);
            size_t ind2 = findIndex(warriors, name2);

            if (ind1 < warriors.size() && ind2 < warriors.size()) {
                battleHandling(warriors[ind1], warriors[ind2], warriors);
            }

        } else if (command == "Status") {
            statusHandling(warriors);
        }
    } 

    file.close();
    return 0;
}

size_t findIndex(const vector<Warrior>& warriors, string& name) {
    /*
    :desc: find if the warrior obj already exists or not
    */
    for (size_t i = 0; i < warriors.size(); ++i) {
        if (warriors[i].name == name) {
            return i;
        }
    }
    return warriors.size();
}

void warriorHandling(string& name, int& strength, string& status , vector<Warrior>& warriors) {
    /*
    :return: none
    :param: name, strength, and status of warrior + vector of warrior objects
    :desc: check if name exists, print error. if not, add
    */
    size_t ind = findIndex(warriors, name);

    if (ind == warriors.size()) {
        Warrior warrior;
        warrior.name = name;
        warrior.strength = strength;
        warrior.status = status;
        warriors.push_back(warrior);
    } else {
        cout << "Warrior with the same name already exists." << endl;
    }
}

void displayWarrior(const Warrior warrior) {
    /*
    :desc: prints each warrior individually
    */
    cout << "Warrior: " << warrior.name << ", strength: " << warrior.strength << endl;
}

void statusHandling(const vector<Warrior>& warriors) {
    /*
    :return: none
    :param: vector of warrior objects
    :desc: should display warriors and strength + call printStatus
    */
    cout << "There are: " << warriors.size() << " warriors" << endl; // print how many warriors there are

    for (size_t i = 0; i < warriors.size(); ++i) {
        displayWarrior(warriors[i]);
   }

}

void battleHandling(Warrior& warrior1, Warrior& warrior2, const vector<Warrior>& warriors) {
    /*
    :return: none
    :param: txt file of commands and vector of warrior objects
    :desc: check status of warrior + display one line + update status of warrior
            + compare strength and based on that let them fight +
            winner loses as much strength his dead opponent had!
    */
   if (warrior1.status == "Dead" && warrior2.status == "Dead") {
       cout << "They're both dead!" << endl;
    } else if (warrior1.status == "Dead") {
        cout << "Find an ALIVE opponent, " << warrior2.name << " :/" << endl;
    } else if (warrior2.status == "Dead") {
        cout << "Find an ALIVE opponent, " << warrior1.name << " :/" << endl;
    } 
    
    // if they're both alive, compare strengths!
    else {
        if (warrior1.strength == warrior2.strength) {
            warrior1.status = "Dead";
            warrior2.status = "Dead";
            warrior1.strength = 0;
            warrior2.strength = 0;
            cout << "They fought to death :D" << endl;
        } else if (warrior1.strength > warrior2.strength) {
            warrior2.status = "Dead";
            warrior2.strength = 0;
            warrior1.strength = warrior1.strength - warrior2.strength;
            cout << warrior1.name << " defeats " << warrior2.name;
        } else if (warrior2.strength > warrior1.strength) {
            warrior1.status = "Dead";
            warrior1.strength = 0;
            warrior2.strength = warrior2.strength - warrior1.strength;
            cout << warrior2.name << " defeats " << warrior1.name;
        } 
    }
}