// CS 2124 - HW1
// Author: Lamar Jambi - lmj8416
// This program decrypts an encrypted .txt file using Caesar cypher algorithm
// General steps: open & read .txt file, display content, shift lines...

#include <iostream>
#include <fstream> // <fstream> is a library which handles operaations on file
#include <string> // The string type is non-primitive, so we should include it
#include <vector> 
using namespace std;

char decryptingChar(char letter, int steps){ 
    /*
    :param: char of uppercase letter, int of steps
    :return: decrypted char
    :desc: turns char into new char
    */

    steps = (steps % 26 + 26) % 26;  // makes sure that even negative numbers are between 0-25 (alphabet)
    return (letter - 'A' - steps + 26) % 26 + 'A';  // caesar cipher logic  
}

void modifyText(string& text, int steps){ // make a reference to each line instead of copying it
    /*
    :param: string of file, int of steps
    :return: none
    :desc: will modify the string that is passed in without returning anything
    */
   char upperLetter;
   char decrypted;

   for (int ind = 0; ind < text.length(); ++ind) {
        upperLetter = text[ind];
        if (upperLetter >= 'A' && upperLetter <= 'Z') { // only decrypt uppercase letters. in C++, we can use 'A' and etc instead of their ASCII codes
            decrypted = decryptingChar(upperLetter, steps);
            text[ind] = decrypted;
        }
    }
}

int main() { 
    /* 
    :desc: will turn file content into a vector, so when we want to modify it, we'll loop through it
    */

    ifstream encryptedFile; 
    encryptedFile.open("encrypted.txt");

    if (!encryptedFile) {
        cout << "Failed to open the file." << endl;
        return 1; // return 1 to indicate error
    }

    int steps;
    encryptedFile >> steps; // store steps 

    vector<string> lines;
    string line;

    while (getline(encryptedFile, line)) {
        lines.push_back(line);
    }
    encryptedFile.close();

    // print given file content
    cout << "Encrypted text: " << endl;
    for (size_t i = 1; i < lines.size(); ++i) { // ind = 1 to not show the steps (int) line
        cout << lines[i] << endl;
    } 

    // modify file content
    for (size_t i = 1; i < lines.size(); ++i) { // modify line by line
        modifyText(lines[i], steps);
    }

    // print file content lines in reverse
    cout << "\nDecrypted text: " << endl;
    for (size_t i = lines.size(); i > 1; --i) { 
        cout << lines[i-1] << endl;
    }

    return 0;
}
