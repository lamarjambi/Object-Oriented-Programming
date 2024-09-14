// CS 2124 - REC01
// Author: Lamar Jambi - lmj8416
// This program aims to apply the basics of C++ 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() { // Yes, it has to have an int for the return type
    // 
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"
    std::cout << "Hello World!" << std::endl;

    // Task 2  Printing hello ...  Using "using namespace"
    cout << "Hello World!" << endl;

    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable
    int x; // This means we declared a variable as int, which is a must, but we didn't assign it
    //cout << "x: " << x << endl;
    
    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.
    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;

    cout << "y: " << y << endl;
    cout << "size of y: " << sizeof(y) << endl;

    cout << "z: " << z << endl;
    cout << "size of z: " << sizeof(z) << endl;

    cout << "pie: " << pie << endl;
    cout << "size of pie: " << sizeof(pie) << endl;
    
    // Task 5  Attempt to assign the wrong type of thing to a variable
    // x = "felix"; (it was declared as an int, so we can't assign a non-int)

    //
    // Conditions
    //

    // Task 6  Testing for a range
    if (y >= 10 && y <= 20){
        cout << "Y is between 10 and 20 :P" << endl;
    }
    
    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive
    // First with a for loop
    for (int q = 10; q <= 20; ++q){
        cout << "Using a for loop: " << q << endl;
    }

    // Then with a while loop
    int i = 10;
    while (i <= 20){
        cout << "Using a while loop: " << i << endl;
        ++i;
    }

    // Finally with a do-while loop
    int j = 10;
    do {
        cout << "Using a do-while loop: " << j << endl;
        ++j;
    }
    while (j <= 20);

    // Task 8  Looping to successfully open a file, asking user for the name
    // until a file opens, keep asking for an input file
    string fileInput;
    ifstream fileAttempt;
    
    do { // while the file is not opened
        cout << "Enter file name: ";
        cin >> fileInput;
        fileAttempt.open(fileInput);
    } while (!fileAttempt);

    /* do {
        fileAttempt.open(fileInput);

        if (!(fileAttempt.is_open())) {
            cout << "Enter file name: ";
            
        }
    } */
    
    // Task 9  Looping, reading file word by "word". 
    string line;
    cout << "File content: " << endl;
    while (fileAttempt >> line) { // how to use .eof() here?
        cout << line << endl;
    }

    fileAttempt.close();

    // Task 10 Open a file of integers, read it in, and display the sum.
    ifstream intFile;

    intFile.open("integers.txt");
    if (!intFile.is_open()) {
        cout << "Error opening the file" << endl;
        return 1;
    }

    double num = 0;
    double sum = 0;

    while (intFile >> num) {
        sum += num;
    }
    cout << "Sum: " << sum << endl;

    intFile.close();

    // Taks 11 Open and read a file of integers and words. Display the sum.
    ifstream mixedFile;

    mixedFile.open("mixed.txt");
    if (!mixedFile.is_open()) {
        cout << "Error opening the file" << endl;
        return 1;
    }

    double mixedNum = 0;
    double mixedSum = 0;

    while (mixedFile >> mixedNum) {
        mixedSum += mixedNum;
    }
    cout << "Sum: " << mixedSum << endl;

    mixedFile.close();

    //
    // Vectors
    //

    // Task 12 Filling a vector of ints
    vector<int> v1;
    int v1Num = 10;

    while (v1Num <= 100) {
        if ((v1Num % 2) == 0) {
            v1.push_back(v1Num);
        }
        ++v1Num;
    }
    
    // Task 13 Displaying the vector THREE times
    //         a) using the indices,
    for (size_t ind = 0; ind < v1.size(); ++ind) { // what's the difference between ++i and i++
        cout << v1[ind] << " ";
    }
    cout << endl;

    //         b) using a "ranged for"
    for (int elem : v1) {
        cout << elem << " ";
    }
    cout << endl;

    //         c) using indices again but backwards
    for (size_t reverseInd = v1.size(); reverseInd > 0; reverseInd--) { // instead of starting from index 0, start from last
        cout << v1[reverseInd - 1];
    }
    cout << endl;

    // Task 14. Initialize a vector with the primes less than 20. 
    vector<int> primeVec = {1, 2, 3, 5, 7, 11, 13, 17, 19};
    // int primeNum = 4;

    // primeVec.push_back(2); // 2 and 3 are prime numbers for sure
    // primeVec.push_back(3); 

    // while (primeNum <= 20) {
    //     if (!((primeNum % 2 == 0) || (primeNum % 3 == 0))) { // doesnt include edge cases i feel
    //         primeVec.push_back(primeNum); 
    //     }
    //     ++primeNum;
    // }

    for (int elem : primeVec) { // displaying vector
        cout << elem << endl;
    }

    //
    // Function calls
    //
    
    // Task 15  Function to print a vector


    // Task 16  Function to double the values in a vector


    // Task 17  Function to double the values in a vector, using a ranged for 

    
}

//
// Function definitions for tasks 15-17
//

// Task 15. Function to display a vector of ints



// Task 16. Function to modify the vector, using indices



// Task 17. Function to modify the vector, using a ranged for


