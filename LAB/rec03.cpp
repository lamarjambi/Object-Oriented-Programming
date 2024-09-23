
// CS 2124 - REC03
// Author: Lamar Jambi - lmj8416
// This program is a tutorial to class basics

/*
  rec03_start.cpp
  2024 Fall
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct
struct Account {
     string name;
     double num;
};


// Task 2
// Define an Account class (use a different name than in Task 1)
class AccountClass {
     friend ostream& operator<<(ostream& os, const AccountClass& account);
     public:
          AccountClass(const string& name, int num) : accName(name), accNum(num) {} // string will initialize empty anyways
          

          const string& getName() const {
          return accName;
          }
          double getNum() const {
               return accNum;
          }

     private:
          string accName; 
          int accNum;   
 
};

// 2b. output operator
ostream& operator<<(ostream& os, const AccountClass& account) {
     // os << "Name: " << account.getName() << ", Account Number: " << account.getNum() << endl;
     os << "Name: " << account.accName << ", Account Number: " << account.accNum << endl;
     return os;
}


// Task 3
// Define another Account class (use a different name than in Task
// 1&2) and a Transaction class. The Transaction class is to be
// defined outside of the Account class, i.e. it is not "nested".

class Transaction{
     friend ostream& operator<< (ostream& os, const Transaction& transaction);

     public:
          Transaction(const string& transType, double transAmount=0.0) : type(transType), amount(transAmount) {}
          
          const string& getType() const {
               return type;
          }
          const double& getAmount() const {
               return amount;
          }

     private:
          string type; // deposit or withdrawal
          double amount;
};

ostream& operator<< (ostream& os, const Transaction& transaction) {
               os << "Transaction type: " << transaction.type << ", Amount: " << transaction.amount << endl;
               return os;
          }

class AccountClass2 {
     friend ostream& operator<<(ostream& os, const AccountClass2& account);
     public:
          AccountClass2(const string& accName, int accNum) : name(accName), num(accNum) {}
          
          int getNum() const {
               return num;
          }

          int getBalance() const {
               return balance;
               }

          void deposit(double amount) {
               history.emplace_back("Deposit", amount);
               balance += amount;
          }

          void withdraw(double amount) {
               
               if (amount <= balance) {
                    history.emplace_back("Withdraw", amount);
                    balance -= amount;
               } else {
                    cout << "Not enough balance" << endl;
               }
               
          }

     private:
          string name;
          int num;
          vector<Transaction> history;
          int balance = 0;
};

ostream& operator<<(ostream& os, const AccountClass2& account) {
     os << "Name: " << account.name << ", Account Number: " << account.num << endl;
     os << "Account History: " << endl;
     for (size_t i = 0; i < account.history.size(); ++i) {
          os << account.history[i] << endl;
     }
     return os;
}


// Task 4
// Define yet another Account class, this time with a nested public
// Transaction class. Again use a different name for the Account class
// than in the previous Tasks. Note that it is NOT necessary to rename
// the Transaction class, since it is nested.
class AccountClass3 { // nested account + tansactions
     friend ostream& operator<<(ostream& os, const AccountClass3& account);
     
     public:
          class Transaction{
          friend ostream& operator<< (ostream& os, const Transaction& transaction);

          public:
               Transaction(const string& transType, double transAmount= 0.0) : type(transType), amount(transAmount) {}
               
               const string& getType() const {
                    return type;
               }
               const double& getAmount() const {
                    return amount;
               }

          private:
               string type; // deposit or withdrawal
               double amount;
          };

          
          AccountClass3(const string& accName, int accNum) : name(accName), num(accNum) {}
          
          int getNum() const {
               return num;
          }

          int getBalance() const {
               return balance;
               }

          void deposit(double amount) {
               history.emplace_back("Deposit", amount);
               balance += amount;
          }

          void withdraw(double amount) {
               
               if (amount <= balance) {
                    history.emplace_back("Withdraw", amount);
                    balance -= amount;
               } else {
                    cout << "Not enough balance" << endl;
               }
               
          }

     private:
          string name;
          int num;
          vector<Transaction> history;
          int balance = 0;

};

ostream& operator<< (ostream& os, const AccountClass3::Transaction& transaction) {
     return os;
}

ostream& operator<<(ostream& os, const AccountClass3& account) {
     os << "Name: " << account.name << ", Account Number: " << account.num << endl;
     os << "Account History: " << endl;
     for (size_t i = 0; i < account.history.size(); ++i) {
          os << account.history[i] << endl;
     }
     return os;
}

// Task 5
// Same as Task 4, but make the Transaction nested class private.
// Yes, the Account class needs a new name but, again, the Transaction
// class does not.


int main() {

    // Task 1: account as struct
    //      1a
     ifstream file;
     vector<Account> accounts;

     file.open("accounts.txt");

     if (!file) {
     cout << "Failed to open file" << endl;
     return 1;
     }

     Account account;
     string accName;
     double accNum;

     while (file >> accName >> accNum) {
          account.name = accName;
          account.num = accNum;
          accounts.push_back(account); 
     }


    cout << "Task1a:\n"
         << "Filling vector of struct objects, define a local struct instance\n"
         << "and set fields explicitly:\n";

     for (size_t ind = 0; ind < accounts.size(); ++ind) {
          cout << "Name: " << accounts[ind].name << ", Account Number: " << accounts[ind].num << endl;
     }
     file.close();

    //      1b 
     accounts.clear();

     file.open("accounts.txt");

     if (!file) {
     cout << "Failed to open file" << endl;
     return 1;
     }

     while (file >> accName >> accNum) {
          account.name = accName;
          account.num = accNum;
          accounts.push_back(account); 
     }     

    cout << "Task1b:\n"
         << "Filling vector of struct objects, using {} initialization:\n";

     while (file >> accName >> accNum) {
          Account accountTest {accName, accNum};
          accounts.push_back(accountTest);
     }

     for (size_t ind = 0; ind < accounts.size(); ++ind) {
          cout << "Name: " << accounts[ind].name << ", Account Number: " << accounts[ind].num << endl;
     }

     file.close();

    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:"
         << "\nFilling vector of class objects, using local class object:\n";

     file.open("accounts.txt");

     if (!file) {
     cout << "Failed to open file" << endl;
     return 1;
     }

     vector<AccountClass> accountClassVec;

     while (file >> accName >> accNum) {
          AccountClass accountClass = AccountClass(accName, accNum);
          accountClassVec.push_back(accountClass);
     }

     for (size_t ind = 0; ind < accountClassVec.size(); ++ind) {
          cout << accountClassVec[ind] << endl;
     }
          
     file.close();

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";

     for (size_t ind = 0; ind < accountClassVec.size(); ++ind) {
          cout << accountClassVec[ind] << endl;
     }

    cout << "\nTask2c:\n"
         << "output using output operator as friend without getters\n";

     for (size_t ind = 0; ind < accountClassVec.size(); ++ind) {
          cout << accountClassVec[ind] << endl;
     }

    cout << "\nTask2d:\n"
         << "Filling vector of class objects, using temporary class object:\n";
     accountClassVec.clear();

     file.open("accounts.txt");

     if (!file) {
     cout << "Failed to open file" << endl;
     return 1;
     }

     while (file >> accName >> accNum) {
          accountClassVec.push_back(AccountClass(accName, accNum));
     }

     for (size_t ind = 0; ind < accountClassVec.size(); ++ind) {
          cout << accountClassVec[ind] << endl;
     }

     file.close();

    cout << "\nTask2e:\n"
         << "Filling vector of class objects, using emplace_back:\n";
     accountClassVec.clear();

     file.open("accounts.txt");

     if (!file) {
     cout << "Failed to open file" << endl;
     return 1;
     }

     while (file >> accName >> accNum) {
          accountClassVec.emplace_back(accName, accNum);
     }

     for (size_t ind = 0; ind < accountClassVec.size(); ++ind) {
          cout << accountClassVec[ind] << endl;
     }
    
     file.close();

    cout << "==============\n"
         << "\nTask 3:\nAccounts and Transaction:\n";
     vector<AccountClass2> commandVec;
     ifstream transFile;

     transFile.open("transactions.txt");
     if (!transFile) {
          cout << "Failed to open file" << endl;
          return 1;
     }
     string command;
     string type;
     int amount;
     string name;
     int num;

     
    while (transFile >> command) {

        if (command == "Account") {
            transFile >> name >> num;
            commandVec.emplace_back(name, num);

        } else if (command == "Deposit") {
            transFile >> num >> amount;
            for (size_t i = 0; i < commandVec.size(); i++) {
                if (num == commandVec[i].getNum()) {
                    commandVec[i].deposit(amount);
                    break;
                }
            }
            
        } else if(command == "Withdraw") {
            //identify id number and amount of transaction
            transFile >> num >> amount;
            for (size_t i = 0; i < commandVec.size(); i++) {
                if (num == commandVec[i].getNum()) {
                    if(amount > commandVec[i].getBalance()) {
                        cout << "transaction failed: Insufficient funds" << endl;
                    }
                    else {commandVec[i].withdraw(amount);
                    break;
                    }
                }
            }
        }
    }

    for (size_t ind = 0; ind < commandVec.size(); ++ind) {
          cout << commandVec[ind] << endl;
    }

    transFile.close();

     

    cout << "==============\n"
         << "\nTask 4:\nTransaction nested in public section of Account:\n";

     while (transFile >> command) {

        if (command == "Account") {
            transFile >> name >> num;
            commandVec.emplace_back(name, num);

        } else if (command == "Deposit") {
            transFile >> num >> amount;
            for (size_t i = 0; i < commandVec.size(); i++) {
                if (num == commandVec[i].getNum()) {
                    commandVec[i].deposit(amount);
                    break;
                }
            }
            
        } else if(command == "Withdraw") {
            //identify id number and amount of transaction
            transFile >> num >> amount;
            for (size_t i = 0; i < commandVec.size(); i++) {
                if (num == commandVec[i].getNum()) {
                    if(amount > commandVec[i].getBalance()) {
                        cout << "transaction failed: Insufficient funds" << endl;
                    }
                    else {commandVec[i].withdraw(amount);
                    break;
                    }
                }
            }
        }
    }

    for (size_t ind = 0; ind < commandVec.size(); ++ind) {
          cout << commandVec[ind] << endl;
    }
    
    cout << "==============\n"
         << "\nTask 5:\nTransaction nested in private section of Account:\n";

    return 0;
}
